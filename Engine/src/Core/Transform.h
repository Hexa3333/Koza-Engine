#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

namespace Koza_Core
{
	class Transform
	{
	public:
		glm::mat4 transform = glm::mat4(1.0f);

		Transform operator=(const glm::vec3& position);

		void Translate(const glm::vec3& moveBy);
		void Translate(float moveByx, float moveByy);

		void Scale(const glm::vec3& scaleBy);
		void Scale(float scaleByx, float scaleByy);

		void Rotate(const glm::vec3& rotateBy, float radians);
		void Rotate(float rotateByx, float rotateByy, float radians);
	};
}