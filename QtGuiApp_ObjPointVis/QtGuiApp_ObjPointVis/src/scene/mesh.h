#pragma once
#include "../drawable.h"
#include <QList>
#include "../la.h"
#include "../tinyobj/tiny_obj_loader.h"
#include <iostream>
#include <qstring.h>

#include "transform.h"
#include "intersection.h"
#include "intersectable.h"

class Intersection;
class Mesh;
class HalfEdgeMesh;
class Triangle;

//A mesh just holds a collection of triangles against which one can test intersections.
//Its primary purpose is to store VBOs for rendering the triangles in OpenGL.
class Mesh : public Intersectable
{
public:
	Mesh();
	Intersection GetIntersection(Ray r);
	void LoadOBJ(QString filePath); /*const QStringRef &filename, const QStringRef &local_path);*/
	std::vector<Triangle*> faces;
	Transform transform;
};

class Triangle : public Mesh
{
public:
	Triangle(const glm::vec3 &p1, const glm::vec3 &p2, const glm::vec3 &p3);
	Triangle(const glm::vec3 &p1, const glm::vec3 &p2, const glm::vec3 &p3, const glm::vec3 &n1, const glm::vec3 &n2, const glm::vec3 &n3);
	Triangle(const glm::vec3 &p1, const glm::vec3 &p2, const glm::vec3 &p3, const glm::vec3 &n1, const glm::vec3 &n2, const glm::vec3 &n3, const glm::vec2 &t1, const glm::vec2 &t2, const glm::vec2 &t3);
	Intersection GetIntersection(Ray r);

	glm::vec3 points[3];
	glm::vec3 normals[3];
	glm::vec2 uvs[3];
	glm::vec3 plane_normal;

	glm::vec3 GetNormal(const glm::vec3 &position);//Returns the interpolation of the triangle's three normals
												   //based on the point inside the triangle that is given.
	glm::vec4 GetNormal(const glm::vec4 &position);
};