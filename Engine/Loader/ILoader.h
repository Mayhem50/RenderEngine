#pragma once

#include "../Foundations/Foundation.h"
#include "../RenderEngine/Mesh.h"

namespace Good
{
	class GOOD_DLL ILoader
	{
	public:
		virtual MeshPtr load(const char* file) = 0;
	};
}