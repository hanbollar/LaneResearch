#ifndef HIGHLIGHTALLOBJV_H
#define HIGHLIGHTALLOBJV_H

#include "drawable.h"

#include "halfedge.h"
#include "vertex.h"
#include "face.h"

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>


class HighlightAllObjV : public Drawable
{
public:
	HighlightAllObjV(GLWidget277* context);

	std::vector<Vertex*> vertices;

    virtual GLenum drawMode();
    virtual void create();
};

#endif // HIGHLIGHTALLOBJV_H
