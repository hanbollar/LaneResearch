#pragma once
#include "ray.h"
#include "intersection.h"

class Intersection;

// The Intersectable class is an abstract interface designed to enable various classes
// to be tested for intersection with rays.

class Intersectable
{
public:
	virtual Intersection GetIntersection(Ray r) = 0;
};