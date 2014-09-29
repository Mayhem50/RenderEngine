#include "TextureFactory.h"

TexturePtr TextureFactory::Create_1D_Texture_Immutable(int width, int levels, Texture_Format format)
{
	TexturePtr texture(new Texture(Texture_Target::Texture_1D, format, false));
	glTexStorage1D(Texture::GLToTextureTarget(texture->target()), levels, Texture::GLToTextureFormat(texture->format()), width);
	return texture;
}

TexturePtr TextureFactory::Create_1D_Texture_Mutable(int width, int level, Texture_Format format)
{
	TexturePtr texture(new Texture(Texture_Target::Texture_1D, format, false));
	glTexImage1D(Texture::GLToTextureTarget(texture->target()), level, )
	return texture;
}

TexturePtr TextureFactory::Create_1D_Array_Texture_Immutable(int width, int size, int levels, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_1D_Array_Texture_Mutable(int width, int size, int levels, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_2D_Texture_Immutable(int width, int height, int levels, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_2D_Texture_Mutable(int width, int height, int levels, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_2D_Array_Texture_Immutable(int width, int height, int size, int levels, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_2D_Array_Texture_Mutable(int width, int height, int size, int levels, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_2D_MultiSample_Texture_Immutable(int width, int height, int levels, int samples, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_2D_MultiSample_Texture_Mutable(int width, int height, int levels, int samples, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_2D_Array_MultiSample_Texture_Immutable(int width, int height, int size, int levels, int samples, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_2D_Array_MultiSample_Texture_Mutable(int width, int height, int size, int levels, int samples, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_3D_Texture_Immutable(int width, int height, int depth, int levels, int samples, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_3D_Texture_Mutable(int width, int height, int depth, int levels, int samples, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_Cube_Texture_Immutable(int width, int height, int levels, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_Cube_Texture_Mutable(int width, int height, int levels, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_Cube_Array_Texture_Immutable(int width, int height, int size, int levels, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_Cube_Array_Texture_Mutable(int width, int height, int size, int levels, Texture_Format format)
{

}

TexturePtr TextureFactory::Create_Rectangle_Texture_Immutable(int width, int height, int levels, Texture_Format format)
{

}
