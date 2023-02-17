#include "Transform.h"

namespace Koza_Core
{
	Transform Transform::operator=(const glm::vec3& position)
	{
		Translate(position);
		return *this;
	}

	void Transform::Translate(const glm::vec3& moveBy)
	{
		m_transform = glm::translate(m_transform, moveBy);
	}

	void Transform::Translate(float moveByx, float moveByy)
	{
		m_transform = glm::translate(m_transform, glm::vec3(moveByx, moveByy, 0.0f));
	}


	void Transform::Scale(const glm::vec3& scaleBy)
	{
		m_transform = glm::scale(m_transform, scaleBy);
	}

	void Transform::Scale(float scaleByx, float scaleByy)
	{
		m_transform = glm::scale(m_transform, glm::vec3(scaleByx, scaleByy, 0.0f));
	}


	void Transform::Rotate(const glm::vec3& rotateBy, float radians)
	{
		m_transform = glm::rotate(m_transform, glm::radians(radians), rotateBy);
	}

	void Transform::Rotate(float rotateByx, float rotateByy, float radians)
	{
		m_transform = glm::rotate(m_transform, glm::radians(radians), glm::vec3(rotateByx, rotateByy, 0.0f));
	}
}

