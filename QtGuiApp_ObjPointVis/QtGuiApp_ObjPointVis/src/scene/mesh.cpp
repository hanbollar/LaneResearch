#include "mesh.h"

Triangle::Triangle(const glm::vec3 &p1, const glm::vec3 &p2, const glm::vec3 &p3) :
	Triangle(p1, p2, p3, glm::vec3(1), glm::vec3(1), glm::vec3(1), glm::vec2(0), glm::vec2(0), glm::vec2(0))
{
	for (int i = 0; i < 3; i++)
	{
		normals[i] = plane_normal;
	}
}


Triangle::Triangle(const glm::vec3 &p1, const glm::vec3 &p2, const glm::vec3 &p3, const glm::vec3 &n1, const glm::vec3 &n2, const glm::vec3 &n3) :
	Triangle(p1, p2, p3, n1, n2, n3, glm::vec2(0), glm::vec2(0), glm::vec2(0))
{}


Triangle::Triangle(const glm::vec3 &p1, const glm::vec3 &p2, const glm::vec3 &p3, const glm::vec3 &n1, const glm::vec3 &n2, const glm::vec3 &n3, const glm::vec2 &t1, const glm::vec2 &t2, const glm::vec2 &t3)
{
	plane_normal = glm::normalize(glm::cross(p2 - p1, p3 - p2));
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	normals[0] = n1;
	normals[1] = n2;
	normals[2] = n3;
	uvs[0] = t1;
	uvs[1] = t2;
	uvs[2] = t3;
}

//Returns the interpolation of the triangle's three normals based on the point inside the triangle that is given.
glm::vec3 Triangle::GetNormal(const glm::vec3 &position)
{
	float d0 = glm::distance(position, points[0]);
	float d1 = glm::distance(position, points[1]);
	float d2 = glm::distance(position, points[2]);
	return (normals[0] * d0 + normals[1] * d1 + normals[2] * d2) / (d0 + d1 + d2);
}

glm::vec4 Triangle::GetNormal(const glm::vec4 &position)
{
	glm::vec3 result = GetNormal(glm::vec3(position));
	return glm::vec4(result, 0);
}

float area(glm::vec3 &a, glm::vec3 &b, glm::vec3 &c) {
	return (0.5f)*(glm::length(glm::cross(a - b, c - b)));
}

//The ray in this function is not transformed because it was *already* transformed in Mesh::GetIntersection
Intersection Triangle::GetIntersection(Ray r)
{
	// for just one triangle
	//      note: given ray in object space so dont need to do additional trans from world to obj
	// have access to the points, normals, uvs, and plane_normal of the triangle

	// Better Triangle Test equation:
	// start with point in triangle weighted with u and v
	//      point = (1-u-v)p1 + up2 + vp3 st u>=0, v>=0, (u+v)<=1
	// subs in the ray equation for point
	// move the equ around:
	//      [-rd, p2-p1, p3-p1] * vert(t u v) = ro-p1
	// to solve using cramer's rule
	//      E1 = p2 - p1, E2 = p3 - p1, T = ro - p1

	// thus, from slide 27:

	glm::vec3 rd = r.direction;
	glm::vec3 ro = r.origin;
	glm::vec3 E1 = points[1] - points[0];
	glm::vec3 E2 = points[2] - points[0];
	glm::vec3 T = ro - points[0];

	glm::vec3 tuv = 1.0f / (glm::dot(glm::cross(rd, E2), E1)) * glm::vec3(glm::dot(glm::cross(T, E1), E2),
		glm::dot(glm::cross(rd, E2), T),
		glm::dot(glm::cross(T, E1), rd)
	);

	// checking u and v values
	// to hit u+v<=1 and u>=0 v>=0
	float t = tuv[0];
	float u = tuv[1];
	float v = tuv[2];
	if (u < 0 || v <= 0 || u + v > 1) {
		// miss so no intersection
		return Intersection();
	} // else have intersection    

	Intersection i = Intersection();

	// intersection values
	i.point = ro + t*rd;
	i.normal = GetNormal(i.point);

	// note: since given ray in this obj space do not need to convert parts into world space
	//      that is done in mesh
	i.t = t;
	i.object_hit = this;

	return i;
}

Mesh::Mesh() : faces(std::vector<Triangle*>()), transform(Transform()) {};

Intersection Mesh::GetIntersection(Ray r)
{
	// given ray in world space
	// go through all triangles and return the closest intersection to camera
	// when sending triangle in to find intersection, make sure give it ray in that triangle's obj space

	QList<Intersection> intersections;

	for (Triangle* tri : faces) {
		Ray working = r.GetTransformedCopy(transform.invT());

		Intersection i = tri->GetIntersection(working);
		// note all intersection values for this are still in obj space
		// below: bring everything into world space

		glm::vec4 workingNorm = transform.invTransT() * glm::vec4(i.normal, 0.0f);
		i.normal = glm::normalize(glm::vec3(workingNorm[0], workingNorm[1], workingNorm[2]));
		i.point = glm::vec3(transform.T() * glm::vec4(i.point, 1.0f));
		// world space t needs to be solved in reverse based on found world position
		//i.t = glm::distance(r.origin, i.point);

		intersections.push_back(i);
	}

	// find closest intersection by finding smallest t of all the intersections
	float t_smallest = INFINITY;
	Intersection closest = Intersection();
	for (Intersection i : intersections) {
		if (i.object_hit != nullptr && t_smallest > i.t) {
			closest = i;
			t_smallest = i.t;
		}
	}

	if (t_smallest == INFINITY) {
		// all had nullptr for obj_hit so found no intersections
		return Intersection();
	}
	else {
		return closest;
	}
}


void Mesh::LoadOBJ(QString fPath)//const QStringRef &filename, const QStringRef &local_path)
{
	QList<Triangle*> newFaces = QList<Triangle*>();
	QString filepath = fPath; //local_path.toString(); filepath.append(filename);
	std::vector<tinyobj::shape_t> shapes; std::vector<tinyobj::material_t> materials;
	std::string errors = tinyobj::LoadObj(shapes, materials, filepath.toStdString().c_str());
	std::cout << errors << std::endl;
	if (errors.size() == 0)
	{
		//Read the information from the vector of shape_ts
		for (unsigned int i = 0; i < shapes.size(); i++)
		{
			std::vector<float> &positions = shapes[i].mesh.positions;
			std::vector<float> &normals = shapes[i].mesh.normals;
			std::vector<float> &uvs = shapes[i].mesh.texcoords;
			std::vector<unsigned int> &indices = shapes[i].mesh.indices;
			for (unsigned int j = 0; j < indices.size(); j += 3)
			{
				glm::vec3 p1(positions[indices[j] * 3], positions[indices[j] * 3 + 1], positions[indices[j] * 3 + 2]);
				glm::vec3 p2(positions[indices[j + 1] * 3], positions[indices[j + 1] * 3 + 1], positions[indices[j + 1] * 3 + 2]);
				glm::vec3 p3(positions[indices[j + 2] * 3], positions[indices[j + 2] * 3 + 1], positions[indices[j + 2] * 3 + 2]);

				Triangle* t = new Triangle(p1, p2, p3);
				if (normals.size() > 0)
				{
					glm::vec3 n1(normals[indices[j] * 3], normals[indices[j] * 3 + 1], normals[indices[j] * 3 + 2]);
					glm::vec3 n2(normals[indices[j + 1] * 3], normals[indices[j + 1] * 3 + 1], normals[indices[j + 1] * 3 + 2]);
					glm::vec3 n3(normals[indices[j + 2] * 3], normals[indices[j + 2] * 3 + 1], normals[indices[j + 2] * 3 + 2]);
					t->normals[0] = n1;
					t->normals[1] = n2;
					t->normals[2] = n3;
				}
				if (uvs.size() > 0)
				{
					glm::vec2 t1(uvs[indices[j] * 2], uvs[indices[j] * 2 + 1]);
					glm::vec2 t2(uvs[indices[j + 1] * 2], uvs[indices[j + 1] * 2 + 1]);
					glm::vec2 t3(uvs[indices[j + 2] * 2], uvs[indices[j + 2] * 2 + 1]);
					t->uvs[0] = t1;
					t->uvs[1] = t2;
					t->uvs[2] = t3;
				}
				//if (!(faces.size() >= 0)) {
				//	std::cout << std::endl; // stop for debugging
				//}
				//this->faces.append(t);
				newFaces.append(t);
			}
		}
		std::cout << "" << std::endl;

		// no error in loading the object
		this->faces;
		for (Triangle* tri : newFaces) {
			this->faces.push_back(tri);
		}
		//this->faces = newFaces;
	} else {
		//An error loading the OBJ occurred!
		std::cout << errors << std::endl;
	}
}

// dont need creates bc my mesh objects are not drawables nor are the geometries --> the halfedgemesh is