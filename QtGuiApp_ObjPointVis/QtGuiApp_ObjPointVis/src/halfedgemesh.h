#ifndef HALFEDGEMESH_H
#define HALFEDGEMESH_H

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

#include "drawable.h"
#include "face.h"
#include "halfedge.h"
#include "vertex.h"

#include "scene/mesh.h"

#include <qlist.h>

class Intersection;
class Geometry;
class Mesh;


class HalfEdgeMesh : public Drawable {
public:
    HalfEdgeMesh(GLWidget277* context);
    HalfEdgeMesh(GLWidget277* context,
                 const std::vector<Face*>& f,
				 const std::vector<HalfEdge*> h,
                 const std::vector<Vertex*>& v);

    virtual GLenum drawMode();

    //storing values
    std::vector<Face*> faces;
	std::vector<HalfEdge*> hEdges;
	std::vector<Vertex*> vertices;

	QList<Mesh*> getObjects();

	Mesh* mesh; // subclass of geometry - used for obj intersections

    //the inherited function
    virtual void create();

};

#endif // HALFEDGEMESH_H
