#include "intersection.h"

Intersection::Intersection() :
	point(glm::vec3(0)),
	normal(glm::vec3(0)),
	t(-1),
	object_hit(nullptr)
{
}

IntersectionEngine::IntersectionEngine()
{ }

Intersection IntersectionEngine::GetIntersection(Ray r)
{
	// for each piece of geometry in the scene find intersection
	// sort through the intersections so closest to camera is returned
	// if no intersection (object_hit == nullptr) then
	//      t = -1 and object_hit == nullptr for returned intersection

	QList<Intersection> intersections = this->GetAllIntersections(r);

	float smallest_t = FLT_MAX;
	Intersection smallI = Intersection();

	for (Intersection inter : intersections) {
		if (inter.t < smallest_t) {
			smallest_t = inter.t;
			smallI = inter;
		}
	}

	return smallI;
}

QList<Intersection> IntersectionEngine::GetAllIntersections(Ray r) {
	QList<Intersection> allIntersects = QList<Intersection>();
	QList<Mesh*> objects = this->halfMesh->getObjects();

	for (Mesh* g : objects) {
		Intersection gInter = g->GetIntersection(r);

		if (gInter.object_hit != nullptr && gInter.t > 0.00001f) {
			allIntersects.push_back(gInter);
		}
	}

	return allIntersects;
}
