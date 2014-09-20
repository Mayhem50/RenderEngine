#pragma once

#include "../Foundations/Foundation.h"

#include "Camera.h"

namespace Good
{
	class GOOD_DLL IRenderable
	{
	public:
		virtual ~IRenderable(){}

		virtual bool init() = 0;
		virtual float draw() = 0;
		virtual bool shutdown() = 0;
	};
}