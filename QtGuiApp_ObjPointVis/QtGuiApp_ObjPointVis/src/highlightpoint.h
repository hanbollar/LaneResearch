#ifndef HIGHLIGHTPOINT_H
#define HIGHLIGHTPOINT_H

#include "drawable.h"

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

#include "point.h"


class HighlightPoint : public Drawable
{
public:
    HighlightPoint(GLWidget277* context);

    Point* currentPoint;

    virtual GLenum drawMode();
    virtual void create();

};

#endif // HIGHLIGHTPOINT_H
