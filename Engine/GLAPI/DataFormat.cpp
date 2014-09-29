#include "DataFormat.h"

#include <exception>

namespace DataFormat
{
	GLenum BaseFormatToGLenum(Base format)
	{
		switch (format)
		{
		case DataFormat::Base::Depth_Component:
			return GL_DEPTH_COMPONENT;
		case DataFormat::Base::Depth_Stencil:
			return GL_DEPTH_STENCIL;
		case DataFormat::Base::Stencil_Index:
			return GL_STENCIL_INDEX;
		case DataFormat::Base::R:
			return GL_RED;
		case DataFormat::Base::RG:
			return GL_RG;
		case DataFormat::Base::RGB:
			return GL_RGB;
		case DataFormat::Base::RGBA:
			return GL_RGBA;
		default:
			throw(new std::exception("Wrong Base Internal Format"));
		}
	}

	GLenum SizedFormatToGLenum(Sized format)
	{
		switch (format)
		{
		case Sized::R8:
			return GL_R8;
		case Sized::R8S:
			return GL_R8_SNORM;
		case Sized::R16:
			return GL_R16;
		case Sized::R16s:
			return GL_R16_SNORM;
		case Sized::RG8:
			return GL_RG8;
		case Sized::RG8s:
			return GL_RG8_SNORM;
		case Sized::RG16:
			return GL_RG16;
		case Sized::RG16s:
			return GL_RG16_SNORM;
		case Sized::RG3B2:
			return GL_R3_G3_B2;
		case Sized::RGB4:
			return GL_RGB4;
		case Sized::RGB5:
			return GL_RGB5;
		case Sized::R5G6B5:
			return GL_RGB565;
		case Sized::RGB8:
			return GL_RGB8;
		case Sized::RGB8s:
			return GL_RGB8_SNORM;
		case Sized::RGB10:
			return GL_RGB10;
		case Sized::RGB12:
			return GL_RGB12;
		case Sized::RGB16:
			return GL_RGB16;
		case Sized::RGB16s:
			return GL_RGB16_SNORM;
		case Sized::RGBA2:
			return GL_RGBA2;
		case Sized::RGBA4:
			return GL_RGBA4;
		case Sized::RGB5A1:
			return GL_RGB5_A1;
		case Sized::RGBA8:
			return GL_RGBA8;
		case Sized::RGBA8s:
			return GL_RGBA8_SNORM;
		case Sized::RGB10A2:
			return GL_RGB10_A2;
		case Sized::RGB10A2ui:
			return GL_RGB10_A2UI;
		case Sized::RGBA12:
			return GL_RGBA12;
		case Sized::RGBA16:
			return GL_RGBA16;
		case Sized::RGBA16s:
			return GL_RGBA16_SNORM;
		case Sized::SRGB8:
			return GL_SRGB8;
		case Sized::SRGBA8:
			return GL_SRGB8_ALPHA8;
		case Sized::R16f:
			return GL_R16F;
		case Sized::RG16f:
			return GL_RG16F;
		case Sized::RGB16f:
			return GL_RGB16F;
		case Sized::RGBA16f:
			return GL_RGBA16F;
		case Sized::R32f:
			return GL_R32F;
		case Sized::RG32f:
			return GL_RG32F;
		case Sized::RGB32f:
			return GL_RGB32F;
		case Sized::RGBA32f:
			return GL_RGBA32F;
		case Sized::RG11B10:
			return GL_R11F_G11F_B10F;
		case Sized::RGB9E5:
			return GL_RGB9_E5;
		case Sized::R8i:
			return GL_R8I;
		case Sized::R8ui:
			return GL_R8UI;
		case Sized::R16i:
			return GL_R16I;
		case Sized::R16ui:
			return GL_R16UI;
		case Sized::R32i:
			return GL_R32I;
		case Sized::R32ui:
			return GL_R32UI;
		case Sized::RG8i:
			return GL_RG8I;
		case Sized::RG8ui:
			return GL_RG8UI;
		case Sized::RG16i:
			return GL_RG16I;
		case Sized::RG16ui:
			return GL_RG16UI;
		case Sized::RG32i:
			return GL_RG32I;
		case Sized::RG32ui:
			return GL_RG32UI;
		case Sized::RGB8i:
			return GL_RGB8I;
		case Sized::RGB8ui:
			return GL_RGB8UI;
		case Sized::RGB16i:
			return GL_RGB16I;
		case Sized::RGB16ui:
			return GL_RGB16UI;
		case Sized::RGB32i:
			return GL_RGB32I;
		case Sized::RGB32ui:
			return GL_RGB32UI;
		case Sized::RGBA8i:
			return GL_RGBA8I;
		case Sized::RGBA8ui:
			return GL_RGBA8UI;
		case Sized::RGBA16i:
			return GL_RGBA16I;
		case Sized::RGBA16ui:
			return GL_RGBA16UI;
		case Sized::RGBA32i:
			return GL_RGBA32I;
		case Sized::RGBA32ui:
			return GL_RGBA32UI;
		case Sized::Depth16:
			return GL_DEPTH_COMPONENT16;
		case Sized::Depth24:
			return GL_DEPTH_COMPONENT24;
		case Sized::Depth32:
			return GL_DEPTH_COMPONENT32;
		case Sized::Depth32F:
			return GL_DEPTH_COMPONENT32F;
		case Sized::Depth24_Stencil8:
			return GL_DEPTH24_STENCIL8;
		case Sized::Depth32_Stencil8:
			return GL_DEPTH32F_STENCIL8;
		case Sized::Stencil_Index:
			return GL_STENCIL_INDEX8;
		default:
			throw(new std::exception("Wrong Sized Internal Format"));
		}
	}
}