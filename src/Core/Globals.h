#pragma once
#include <iostream>
#include <GL/glew.h>

namespace Kz_Globals {

	const std::string DEFAULT_VERTEX_SHADER = "\n\
		#version 400 core\n\
		layout(location = 0) in vec3 mPos;\n\
		layout(location = 1) in vec2 mTex;\n\
		out vec2 TextureCoordinates;\n\
		uniform mat4 model;\n\
		void main()\n\
		{\n\
			gl_Position = model * vec4(mPos, 1.0);\n\
			TextureCoordinates = mTex;\n\
		}";

	const std::string DEFAULT_FRAGMENT_SHADER = "\n\
		#version 400 core\n\
		out vec4 FragColor;\n\
		in vec2 TextureCoordinates;\n\
		uniform sampler2D tex0;\n\
		void main()\n\
		{\n\
			FragColor = texture(tex0, TextureCoordinates);\n\
		}";

}