#ifndef HIGHLIGHTALLPOINTS_H
#define HIGHLIGHTALLPOINTS_H

#include "drawable.h"

#include "la.h"

#include "point.h"

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>


class HighlightAllPoints : public Drawable
{
public:
	HighlightAllPoints(GLWidget277* context);

	std::vector<Point*> points;

    virtual GLenum drawMode();
    virtual void create();
};

#endif // HIGHLIGHTALLPOINTS_H
