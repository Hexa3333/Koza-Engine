#include "Transform.h"
#include <iostream>

namespace Koza_Core
{
	// Private Constructor
	Transform::Transform(float startPosX, float startPosY)
	{
		m_startPosX = startPosX;
		m_startPosY = startPosY;

		m_position = glm::vec2(m_startPosX, m_startPosY);
		m_transform = glm::translate(glm::mat4(1.0f), glm::vec3(m_position, 1.f));
	}

	// Public Constructor
	Transform::Transform()
	{
		m_startPosX = 0.f;
		m_startPosY = 0.f;

		m_position = glm::vec2(m_startPosX, m_startPosY);
		m_transform = glm::translate(glm::mat4(1.0f), glm::vec3(m_position, 1.f));
	}

	// IN PROGRESS
	Transform Transform::operator=(const glm::vec2& Position)
	{
		m_position = glm::vec2(Position.x, Position.y);
		m_transform = glm::translate(glm::mat4(1.0f), glm::vec3(m_position, 1.f));

		return *this;
	}

	void Transform::Translate(const glm::vec2& moveBy)
	{
		m_transform = glm::translate(m_transform, glm::vec3(moveBy, 0.f));

		glm::vec4 _pc = glm::vec4(m_position.x + moveBy.x, m_position.y + moveBy.y, 0.f, 1.0f);
		m_position = glm::vec2(_pc.x, _pc.y);
	}

	void Transform::Translate(float moveByx, float moveByy)
	{
		m_transform = glm::translate(m_transform, glm::vec3(moveByx, moveByy, 0.0f));

		glm::vec4 _pc = glm::vec4(m_position.x + moveByx, m_position.y + moveByy, 0, 1);
		m_position = glm::vec2(_pc.x, _pc.y);
	}


	void Transform::Scale(const glm::vec2& scaleBy)
	{
		m_transform = glm::scale(m_transform, glm::vec3(scaleBy, 0.0f));
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

	void Transform::setPosition(const Transform& other)
	{
		glm::value_ptr(m_transform)[12] = glm::value_ptr(other.m_transform)[12];
		glm::value_ptr(m_transform)[13] = glm::value_ptr(other.m_transform)[13];

		// Set the position value accordingly
		m_position.x = glm::value_ptr(other.m_transform)[12];
		m_position.y = glm::value_ptr(other.m_transform)[13];
	}

	void Transform::setScale(const Transform& other)
	{
		glm::value_ptr(m_transform)[0] = glm::value_ptr(other.m_transform)[0];
		glm::value_ptr(m_transform)[5] = glm::value_ptr(other.m_transform)[5];
	}

	void Transform::setRotation(const Transform& other)
	{
		std::cout << "ROTCOPY NOT IMPLEMENTED YET\n";
	}

	float* Transform::ReadMatrix(const glm::mat4& Mat)
	{
		float dArray[16] = { 0.0f };

		const float* pSource = (const float*)glm::value_ptr(Mat);
		for (int i = 0; i < 16; ++i)
			dArray[i] = pSource[i];
		
		for (int i = 0; i < 16; ++i)
			std::cout << dArray[i] << std::endl;

		return dArray;
	}
}

