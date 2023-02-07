#include "Transform.h"

namespace Koza_Core
{
	void Transform::Translate(const glm::vec3& moveBy)
	{
		transform = glm::translate(transform, moveBy);
	}

	void Transform::Translate(float moveByx, float moveByy)
	{
		transform = glm::translate(transform, glm::vec3(moveByx, moveByy, 0.0f));
	}


	void Transform::Scale(const glm::vec3& scaleBy)
	{
		transform = glm::scale(transform, scaleBy);
	}

	void Transform::Scale(float scaleByx, float scaleByy)
	{
		transform = glm::scale(transform, glm::vec3(scaleByx, scaleByy, 0.0f));
	}


	void Transform::Rotate(const glm::vec3& rotateBy, float radians)
	{
		transform = glm::rotate(transform, glm::radians(radians), rotateBy);
	}

	void Transform::Rotate(float rotateByx, float rotateByy, float radians)
	{
		transform = glm::rotate(transform, glm::radians(radians), glm::vec3(rotateByx, rotateByy, 0.0f));
	}
}

