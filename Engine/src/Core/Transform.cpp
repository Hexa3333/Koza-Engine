#include "Transform.h"
#include <iostream>

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

		glm::vec4 _pc = glm::vec4(position.x + moveBy.x, position.y + moveBy.y, 1, 1);
		position = glm::vec2(_pc.x, _pc.y);
	}

	void Transform::Translate(float moveByx, float moveByy)
	{
		m_transform = glm::translate(m_transform, glm::vec3(moveByx, moveByy, 0.0f));

		glm::vec4 _pc = glm::vec4(position.x + moveByx, position.y + moveByy, 1, 1);
		position = glm::vec2(_pc.x, _pc.y);
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

