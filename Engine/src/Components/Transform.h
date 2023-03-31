#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

namespace KozaCore
{
	struct Transform
	{
	private:
		//Transform(glm::vec2 startPosition);
		Transform(float startPosX, float startPosY);
		float m_startPosX;
		float m_startPosY;


	public:
		glm::vec2 m_position;
		glm::mat4 m_transform;

		Transform();

		Transform operator=(const glm::vec2& Position);

		void Translate(const glm::vec2& moveBy);
		void Translate(float moveByx, float moveByy);

		void Scale(const glm::vec2& scaleBy);
		void Scale(float scaleByx, float scaleByy);

		void Rotate(const glm::vec3& rotateBy, float radians);
		void Rotate(float rotateByx, float rotateByy, float radians);


		void setPosition(const Transform& other);
		void setScale(const Transform& other);
		void setRotation(const Transform& other);

		void setPosition(const glm::vec2& other);
		void setScale(const glm::vec2& other);
		void setRotation(const glm::vec2& other);

	public:
		// Only used for debugging
		static float* ReadMatrix(const glm::mat4& Mat);
		static Transform Origin;
	};
}