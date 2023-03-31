#pragma once
#include <glm.hpp>
#include <memory>
#include <gtc/matrix_transform.hpp>

namespace KozaCore
{
	class Camera
	{
	public:
		glm::vec3 m_Position = glm::vec3(1.0f);
		glm::mat4 m_ViewMatrix = glm::mat4(1.0f);
		glm::mat4 m_ProjectionMatrix = glm::mat4(1.0f);

		Camera(float left, float right, float bottom, float top, float zNear, float zFar);

		const glm::vec3& GetPosition() { return m_Position; }
		const glm::mat4& GetViewMatrix() { return m_ViewMatrix; }
		const glm::mat4& GetProjectionMatrix() { return m_ProjectionMatrix * glm::lookAt(m_Position, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f)); }
	};

	class OrtographicCamera : Camera
	{
	public:
		OrtographicCamera(float left, float right, float bottom, float top, float zNear, float zFar);
	};
}