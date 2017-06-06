#include "camera.h"

#include "la.h"
#include <iostream>


Camera::Camera():
    Camera(400, 400)
{
    look = glm::vec3(0,0,-1);
    up = glm::vec3(0,1,0);
    right = glm::vec3(1,0,0);
}

Camera::Camera(unsigned int w, unsigned int h):
    Camera(w, h, glm::vec3(0,0,10), glm::vec3(0,0,0), glm::vec3(0,1,0))
{}

Camera::Camera(unsigned int w, unsigned int h, const glm::vec3 &e, const glm::vec3 &r, const glm::vec3 &worldUp):
    fovy(45),
    width(w),
    height(h),
    near_clip(0.1f),
    far_clip(1000),
    eye(e),
    ref(r),
    world_up(worldUp)
{
    RecomputeAttributes();
}

Camera::Camera(const Camera &c):
    fovy(c.fovy),
    width(c.width),
    height(c.height),
    near_clip(c.near_clip),
    far_clip(c.far_clip),
    aspect(c.aspect),
    eye(c.eye),
    ref(c.ref),
    look(c.look),
    up(c.up),
    right(c.right),
    world_up(c.world_up),
    V(c.V),
    H(c.H)
{}


void Camera::RecomputeAttributes()
{
    look = glm::normalize(ref - eye);
    right = glm::normalize(glm::cross(look, world_up));
    up = glm::cross(right, look);

    float tan_fovy = tan(glm::radians(fovy/2));
    float len = glm::length(ref - eye);
    aspect = width/height;
    V = up*len*tan_fovy;
    H = right*len*aspect*tan_fovy;
}

glm::mat4 Camera::getViewProj()
{
    return glm::perspective(glm::radians(fovy), width / (float)height, near_clip, far_clip) * glm::lookAt(eye, ref, up);
}

void Camera::RotateAboutUp(float deg)
{
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(deg), up);

	glm::mat4 invT = glm::translate(glm::mat4(1.0f), -ref);
	eye -= ref;
	eye = glm::vec3(rotation * glm::vec4(eye, 1.0f));
	look = glm::vec3(rotation * glm::vec4(look, 0.0f));
	right = glm::vec3(rotation * glm::vec4(right, 0.0f));
	eye += ref;

	RecomputeAttributes();
}
void Camera::RotateAboutRight(float deg)
{
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(deg), right);

	glm::mat4 invT = glm::translate(glm::mat4(1.0f), -ref);
	eye -= ref;
	eye = glm::vec3( rotation * glm::vec4(eye, 1.0f) );
	look = glm::vec3(rotation * glm::vec4(look, 0.0f));
	up = glm::vec3(rotation * glm::vec4(up, 0.0f));
	eye += ref;

    RecomputeAttributes();
}

void Camera::recenter() {
	*this = Camera(this->width, this->height);
}

void Camera::TranslateAlongLook(float amt)
{
    glm::vec3 translation = look * amt;
    eye += translation;
    ref += translation;
}

void Camera::TranslateAlongRight(float amt)
{
    glm::vec3 translation = right * amt;
    eye += translation;
    ref += translation;
}
void Camera::TranslateAlongUp(float amt)
{
    glm::vec3 translation = up * amt;
    eye += translation;
    ref += translation;
}

Ray Camera::Raycast(Point2f &pt)
{
	return Raycast(pt.x, pt.y);
}

Ray Camera::Raycast(float x, float y) 
{
	float ndc_x = (2.f*x / width - 1);
	float ndc_y = (1 - 2.f*y / height);
	return RaycastNDC(ndc_x, ndc_y);
}

Ray Camera::RaycastNDC(float ndc_x, float ndc_y) 
{
	// compute raster and camera sample positions
	glm::vec3 P = ref + ndc_x*H + ndc_y*V;
	Ray result(eye, glm::normalize(P - eye));

	return result;
}

