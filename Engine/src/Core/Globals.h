#pragma once
#include <iostream>

using KOZA_STATUS = uint8_t;
using KOZA_FLAG = uint16_t;

constexpr KOZA_STATUS SUCCESSFUL = 0x01;
constexpr KOZA_STATUS FAILED = 0x02;

namespace KozaCore {

	const std::string DEFAULT_VERTEX_SHADER = "\n\
		#version 400 core\n\
		layout(location = 0) in vec2 mPos;\n\
		layout(location = 1) in vec2 mTexCoord;\n\
		out vec2 v_position; \n\
		out vec2 v_TextureCoordinates; \n\
		uniform mat4 u_trans; \n\
		void main()\n\
		{\n\
			v_position = mPos; \n\
			gl_Position = u_trans * vec4(mPos, 0.0f, 1.0f); \n\
			v_TextureCoordinates = vec2(mTexCoord.x, mTexCoord.y); \n\
		};";

	const std::string DEFAULT_FRAGMENT_SHADER = "\n\
		#version 400 core\n\
		out vec4 FragColor;\n\
		in vec2 v_TextureCoordinates;\n\
		uniform sampler2D tex0;\n\
		void main()\n\
		{\n\
			FragColor = texture(tex0, v_TextureCoordinates);\n\
		}";

}