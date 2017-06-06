#ifndef POINT_H
#define POINT_H

#include "la.h"
#include <stdio.h>
#include <string>
#include <QListWidgetItem>

#include <QString>

class Point : public QListWidgetItem {
public:
    //for no param constructor
	Point();
	Point(glm::vec3, int);

	void changeId(int);

    //position of the vertex
    glm::vec3 pos;

    //unique int to identify this vert in menus etc
	int id;
};

#endif // POINT_H
