#include "halfedgemesh.h"
#include <iostream>

HalfEdgeMesh::HalfEdgeMesh(GLWidget277* context)
    : Drawable(context),
      faces(std::vector<Face*>()), hEdges(std::vector<HalfEdge*>()), vertices(std::vector<Vertex*>())
{}

HalfEdgeMesh::HalfEdgeMesh(GLWidget277 *context,
	const std::vector<Face*>& f,
	const std::vector<HalfEdge*> h,
	const std::vector<Vertex*>& v)
    : Drawable(context),
      faces(f), hEdges(h), vertices(v)
{}

GLenum HalfEdgeMesh::drawMode() {
    return GL_TRIANGLES;
}

QList<Mesh*> HalfEdgeMesh::getObjects() {
	QList<Mesh*> geo = QList<Mesh*>();
	geo.push_back(mesh);

	return geo;
}

/*
void HalfEdgeMesh::create() {
	this->mesh->create();
}*/

void HalfEdgeMesh::create() {
    //set up all these std::vectors
    //  triangle indices
    std::vector<GLuint> triIndices;
    //  pos vec4s
    std::vector<glm::vec4> posVector;
    //  normal vec4s
    std::vector<glm::vec4> normVector;
    //  color vec4s
    std::vector<glm::vec4> colVector;
    //note: pos, normal, and color vectors need to be 1:1 to eachother

    int indexOffSet = 0;

    for (Face* f : faces) {
        HalfEdge* firstEdge = f->start_edge;

        //POSITIONS, NORMALS, and COLORS
        //setting up variables to begin making position vec3s and normal vec3s for current face
        HalfEdge *currEdge = firstEdge;
        Vertex *currVert = (currEdge->vert);
        HalfEdge *prevEdge = currEdge;
        while (prevEdge->next != firstEdge) { //looping around to find prev edge for firstEdge
            prevEdge = (prevEdge->next);
        }
        Vertex *prevVert = prevEdge->vert;
        Vertex *nextVert = currEdge->next->vert;

        glm::vec3 v1 = currVert->pos - prevVert->pos;
        glm::vec3 v2 = currVert->pos - nextVert->pos;
        glm::vec3 norm = glm::cross(v1, v2);
        glm::vec4 normVec = glm::vec4(norm[0],
                                      norm[1],
                                      norm[2],
                                      0);

        bool firstLoop = true;

        while(firstLoop || currEdge != firstEdge) {
            firstLoop = false;

            //converting vec3s into vec4s so correct for the vbos
            glm::vec4 posVec = glm::vec4(currVert->pos[0],
                                         currVert->pos[1],
                                         currVert->pos[2],
                                         1);

            //std::cout << "currentVertex id: " << currVert->id << "pos: " << glm::to_string(currVert->pos) << std::endl;


            //storing
            posVector.push_back(posVec);
            normVector.push_back(normVec);
            //color also stored here to maintain 1:1
		
			// coloring by predefined color
			colVector.push_back((f->color) / 255.0f);
           

            //now shifting all values for next pos and norm values
            prevEdge = currEdge;
            currEdge = currEdge->next;
            prevVert = prevEdge->vert;
            currVert = currEdge->vert;
            nextVert = currEdge->next->vert;
        }

        //TRIANGLES
        //setting up variables to begin triangulating current face

        int count = 1;
        HalfEdge* current = firstEdge->next;

        //counting number of vertices for this face
        while (current != firstEdge) { //while next is not the first edge
            count++;
            current = current->next; //step to next edge
        }

        //making triangles for current face
        int first = 0;
        int second = 1;
        int third = 2;

        while (third < count) {
            triIndices.push_back(first + indexOffSet);
            triIndices.push_back(second + indexOffSet);
            triIndices.push_back(third + indexOffSet);

            second = third;
            third++;
        }

        indexOffSet += count;
    }


    count = triIndices.size();

    //  handling triangle indices vbo
    generateIdx();
    context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, triIndices.size() * sizeof(GLuint), triIndices.data(), GL_STATIC_DRAW);

    //  handling of pos vec3s vbo
    generatePos();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    context->glBufferData(GL_ARRAY_BUFFER, posVector.size() * sizeof(glm::vec4), posVector.data(), GL_STATIC_DRAW);

    //  handling of norm vec3s vbo
    generateNor();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufNor);
    context->glBufferData(GL_ARRAY_BUFFER, normVector.size() * sizeof(glm::vec4), normVector.data(), GL_STATIC_DRAW);

    //  handling of color vbo
    generateCol();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    context->glBufferData(GL_ARRAY_BUFFER, colVector.size() * sizeof(glm::vec4), colVector.data(), GL_STATIC_DRAW);
}
