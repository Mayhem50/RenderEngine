#pragma once

#include "../Foundations/GoodObject.h"
#include "../GLAPI/ShaderProgram.h"
#include "../GLAPI/CubeMap.h"

#include <memory>
#include <glm/glm.hpp>

namespace Good
{
	struct GOOD_DLL Material : public GoodObject
	{
		Material(const char* name);

		glm::vec4 diffuseColor;
		glm::vec4 specularColor;
		glm::vec4 emissiveColor;

		float roughness;
		float metallic;

		float opacity;
		float indice;
	};

	typedef std::shared_ptr<Material> MaterialPtr;
}