#pragma once
#include "../la.h"
#include "ray.h"
#include <QList>
#include "../halfedgemesh.h"

#include <iostream>

//class Material;
class Mesh;
class Triangle;
class HalfEdgeMesh;

class Intersection
{
public:
	Intersection();

	glm::vec3 point;      //The place at which the intersection occurred
	glm::vec3 normal;     //The surface normal at the point of intersection
	float t;              //The parameterization for the ray (in world space) that generated this intersection.
						  //t is equal to the distance from the point of intersection to the ray's origin if the ray's direction is normalized.
	Triangle* object_hit;     //The object that the ray intersected, or nullptr if the ray hit nothing.
};

class IntersectionEngine
{
public:
	IntersectionEngine();

	HalfEdgeMesh* halfMesh;

	Intersection GetIntersection(Ray r);
	QList<Intersection> GetAllIntersections(Ray r);
};