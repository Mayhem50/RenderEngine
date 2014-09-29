#pragma once

#include "../Foundations/Singleton.h"
#include "Texture.h"

class TextureFactory : public Singleton<TextureFactory>
{
public:
	TexturePtr Create_1D_Texture_Immutable						(int width, int levels, Texture_Format format);
	TexturePtr Create_1D_Texture_Mutable						(int width, int levels, Texture_Format format);
	TexturePtr Create_1D_Array_Texture_Immutable				(int width, int size, int levels, Texture_Format format);
	TexturePtr Create_1D_Array_Texture_Mutable					(int width, int size, int levels, Texture_Format format);
	TexturePtr Create_2D_Texture_Immutable						(int width, int height, int levels, Texture_Format format);
	TexturePtr Create_2D_Texture_Mutable						(int width, int height, int levels, Texture_Format format);
	TexturePtr Create_2D_Array_Texture_Immutable				(int width, int height, int size, int levels, Texture_Format format);
	TexturePtr Create_2D_Array_Texture_Mutable					(int width, int height, int size, int levels, Texture_Format format);
	TexturePtr Create_2D_MultiSample_Texture_Immutable			(int width, int height, int levels, int samples, Texture_Format format);
	TexturePtr Create_2D_MultiSample_Texture_Mutable			(int width, int height, int levels, int samples, Texture_Format format);
	TexturePtr Create_2D_Array_MultiSample_Texture_Immutable	(int width, int height, int size, int levels, int samples, Texture_Format format);
	TexturePtr Create_2D_Array_MultiSample_Texture_Mutable		(int width, int height, int size, int levels, int samples, Texture_Format format);
	TexturePtr Create_3D_Texture_Immutable						(int width, int height, int depth, int levels, int samples, Texture_Format format);
	TexturePtr Create_3D_Texture_Mutable						(int width, int height, int depth, int levels, int samples, Texture_Format format);
	TexturePtr Create_Cube_Texture_Immutable					(int width, int height, int levels, Texture_Format format);
	TexturePtr Create_Cube_Texture_Mutable						(int width, int height, int levels, Texture_Format format);
	TexturePtr Create_Cube_Array_Texture_Immutable				(int width, int height, int size, int levels, Texture_Format format);
	TexturePtr Create_Cube_Array_Texture_Mutable				(int width, int height, int size, int levels, Texture_Format format);
	TexturePtr Create_Rectangle_Texture_Immutable				(int width, int height, int levels, Texture_Format format);
};