#include "point.h"

Point::Point() : pos(glm::vec3(NAN)), id(-1) {}

Point::Point(glm::vec3 p, int i) : pos(p), id(i) {
	changeId(i);
}

void Point::changeId(int i) {
	id = i;

	QString position = QString::fromStdString(" (" + std::to_string(pos[0]) + ", " + std::to_string(pos[1]) + ", " + std::to_string(pos[2]) + ")");
	QString beg = QString::fromStdString("p" + std::to_string(id) + ":");
	QListWidgetItem::setText(beg.append(position));
}
