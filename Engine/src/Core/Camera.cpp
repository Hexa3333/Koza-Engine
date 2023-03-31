#include "Camera.h"
#include <ext/matrix_clip_space.hpp>
#include <ext/matrix_transform.hpp>

namespace KozaCore
{

	Camera::Camera(float left, float right, float bottom, float top, float zNear, float zFar)
		:	m_ProjectionMatrix(glm::ortho(left, right, bottom, top, zNear, zFar))
	{
	}


	OrtographicCamera::OrtographicCamera(float left, float right, float bottom, float top, float zNear, float zFar)
		:	Camera(left, right, bottom, top, zNear, zFar)
	{

	}

}