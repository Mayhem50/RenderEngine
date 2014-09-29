#pragma once

#include <GL\glew.h>

namespace DataFormat
{
	enum class Base
	{
		Depth_Component,
		Depth_Stencil,
		Stencil_Index,
		R, RG, RGB, RGBA,
	};

	enum class Sized
	{
		R8, R8S, R16, R16s,
		RG8, RG8s, RG16, RG16s,
		RG3B2, RGB4, RGB5, R5G6B5,
		RGB8, RGB8s, RGB10, RGB12,
		RGB16, RGB16s, RGBA2, RGBA4,
		RGB5A1, RGBA8, RGBA8s, RGB10A2,
		RGB10A2ui, RGBA12, RGBA16, RGBA16s,
		SRGB8, SRGBA8, R16f, RG16f,
		RGB16f, RGBA16f, R32f, RG32f,
		RGB32f, RGBA32f, RG11B10, RGB9E5,
		R8i, R8ui, R16i, R16ui,
		R32i, R32ui, RG8i, RG8ui,
		RG16i, RG16ui, RG32i, RG32ui,
		RGB8i, RGB8ui, RGB16i, RGB16ui,
		RGB32i, RGB32ui, RGBA8i, RGBA8ui,
		RGBA16i, RGBA16ui, RGBA32i, RGBA32ui,
		Depth16, Depth24, Depth32, Depth32F,
		Depth24_Stencil8, Depth32_Stencil8,
		Stencil_Index,
	};

	enum class Compressed
	{
		Red, RG, RGB, RGBA,
		SRGB, SRGBA, Red_RGTC1,
		sRed_RGTC1, RG_RGTC2,
		sRG_RGTC2, RGBA_BPTC,
		SRGBA_BPTC, RGB_BPTC_sf,
		RGB_BPTC_uf,
		// S3TC Format
		RGB_S3TC_DXT1, SRGB_S3TC_DXT1,
		RGBA_S3TC_DXT1, SRGBA_S3TC_DXT1,
		RGBA_S3TC_DXT3, SRGBA_S3TC_DXT3,
		RGBA_S3TC_DXT5, SRGBA_S3TC_DXT5,
	};

	GLenum BaseFormatToGLenum(Base format);
	GLenum SizedFormatToGLenum(Sized format);
	GLenum CompressedFormatToGLenum(Compressed format);
}
