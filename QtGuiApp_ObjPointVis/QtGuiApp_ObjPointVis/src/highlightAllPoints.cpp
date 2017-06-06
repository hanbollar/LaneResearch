#include "highlightallpoints.h"

HighlightAllPoints::HighlightAllPoints(GLWidget277* context)
    : Drawable(context), points(std::vector<Point*>()) {}

GLenum HighlightAllPoints::drawMode() {
    return GL_POINTS;
}

void HighlightAllPoints::create() {
    //create new vbo
    //set drawmode to GL_POINTS
    //only drawing for one vertex
    //  line indices. first in line is prevVert, second in line is currentVert
    std::vector<GLuint> pointIndex;
    //  pos vec4s
    std::vector<glm::vec4> posVector;
    //  color vec4s
    std::vector<glm::vec4> colVector;
    //note: pos, and color vectors need to be 1:1 to eachother

	int amount = points.size();

	for (int i = 0; i < amount; i++) {
		pointIndex.push_back(i);
		colVector.push_back(glm::vec4(255.0f, 255.0f, 0.0f, 1.0f) / 255.0f); //yellow for highlighted points
		posVector.push_back(glm::vec4(points[i]->pos, 1.0f));
	}

    count = amount;

    //  handling line indices vbo
    generateIdx();
    context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, pointIndex.size() * sizeof(GLuint), pointIndex.data(), GL_STATIC_DRAW);

    //  handling of pos vec3s vbo
    generatePos();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    context->glBufferData(GL_ARRAY_BUFFER, posVector.size() * sizeof(glm::vec4), posVector.data(), GL_STATIC_DRAW);

    //  handling of color vbo
    generateCol();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    context->glBufferData(GL_ARRAY_BUFFER, colVector.size() * sizeof(glm::vec4), colVector.data(), GL_STATIC_DRAW);
}
