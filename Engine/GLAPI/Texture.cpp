#include "Texture.h"

#include <exception>

#pragma region Public_Methods

Texture::Texture(Texture_Target target, Texture_Format format, bool isMutable):
GlObject(),
_target(target),
_format(format),
_isMutable(isMutable)
{
	GLenum glTarget = GLToTextureTarget(_target);
	glGenTextures(1, &_glName);
	glBindTexture(glTarget, _glName);
}

Texture::~Texture()
{
	glDeleteTextures(1, &_glName);
}

Texture_Format Texture::format() const
{
	return _format;
}

Texture_Target Texture::target() const
{
	return _target;
}

bool Texture::isMutable() const
{
	return _isMutable;
}

void Texture::setDepthMode(Texture_Parameter::Depth_Texture_Mode mode)
{
	GLenum param;

	switch (mode)
	{
	case Texture_Parameter::Depth_Texture_Mode::Red:
		param = GL_RED;
		break;
	case Texture_Parameter::Depth_Texture_Mode::Luminance:
		param = GL_LUMINANCE;
		break;
	case Texture_Parameter::Depth_Texture_Mode::Intensity:
		param = GL_INTENSITY;
		break;
	case Texture_Parameter::Depth_Texture_Mode::Alpha:
		param = GL_ALPHA;
		break;
	default:
		throw(new std::exception("Wrong Depth Texture Mode"));
		break;
	}

	_setParameteri(GL_DEPTH_TEXTURE_MODE, param);
}

void Texture::setDepthStencilMode(Texture_Parameter::Depth_Stencil_Texture_Mode mode)
{
	GLenum param;

	switch (mode)
	{
	case Texture_Parameter::Depth_Stencil_Texture_Mode::Depth_Component:
		param = GL_DEPTH_COMPONENT;
		break;
	case Texture_Parameter::Depth_Stencil_Texture_Mode::Stencil_Index:
		param = GL_STENCIL_INDEX;
		break;
	default:
		throw(new std::exception("Wrong Depth Stencil Texture Mode"));
		break;
	}

	_setParameteri(GL_DEPTH_STENCIL_TEXTURE_MODE, param);
}

void Texture::setGenerateMipMap(bool generate)
{
	_setParameteri(GL_MIPMAP, (int)generate);
}

void Texture::setBaseLevel(unsigned int value)
{
	_setParameteri(GL_TEXTURE_BASE_LEVEL, (int)value);
}

void Texture::setBorderColor(float red, float green, float blue, float alpha)
{
	float *array = new float[4];
	array[0] = red; array[1] = green;
	array[2] = blue; array[3] = alpha;

	_setParameterfv(GL_TEXTURE_BORDER_COLOR, array);
	delete[] array;
}

void Texture::setCompareMode(Texture_Parameter::Texture_Compare_Mode mode)
{
	GLenum param;

	switch (mode)
	{
	case Texture_Parameter::Texture_Compare_Mode::None:
		param = GL_NONE;
		break;
	case Texture_Parameter::Texture_Compare_Mode::Compare_Ref_To_Texture:
		param = GL_COMPARE_REF_TO_TEXTURE;
		break;
	default:
		throw(new std::exception("Wrong Texture Compare Mode"));
		break;
	}

	_setParameteri(GL_TEXTURE_COMPARE_MODE, param);
}

void Texture::setCompareFunction(Texture_Parameter::Compare_Function function)
{
	GLenum param;

	switch (function)
	{
	case Texture_Parameter::Compare_Function::Lequal:
		param = GL_LEQUAL;
		break;
	case Texture_Parameter::Compare_Function::Gequal:
		param = GL_GEQUAL;
		break;
	case Texture_Parameter::Compare_Function::Less:
		param = GL_LESS;
		break;
	case Texture_Parameter::Compare_Function::Greater:
		param = GL_GREATER;
		break;
	case Texture_Parameter::Compare_Function::Equal:
		param = GL_EQUAL;
		break;
	case Texture_Parameter::Compare_Function::NotEqual:
		param = GL_NOTEQUAL;
		break;
	case Texture_Parameter::Compare_Function::Always:
		param = GL_ALWAYS;
		break;
	case Texture_Parameter::Compare_Function::Never:
		param = GL_NEVER;
		break;
	default:
		throw(new std::exception("Wrong Texture Compare Function"));
		break;
	}

	_setParameteri(GL_TEXTURE_COMPARE_FUNC, param);
}

void Texture::setLODBias(float value)
{
	_setParameterf(GL_TEXTURE_LOD_BIAS, value);
}

void Texture::setMagFilter(Texture_Parameter::Mag_Filter filter)
{
	GLenum param;

	switch (filter)
	{
	case Texture_Parameter::Mag_Filter::Nearest:
		param = GL_NEAREST;
		break;
	case Texture_Parameter::Mag_Filter::Linear:
		param = GL_LINEAR;
		break;
	default:
		throw(new std::exception("Wrong Texture Mag Filter"));
		break;
	}

	_setParameteri(GL_TEXTURE_MAG_FILTER, param);
}

void Texture::setMaxLevel(int value)
{
	_setParameteri(GL_TEXTURE_MAX_LEVEL, value);
}

void Texture::setMaxLOD(float value)
{
	_setParameterf(GL_TEXTURE_MAX_LOD, value);
}

void Texture::setMinFilter(Texture_Parameter::Min_Filter filter)
{
	GLenum param;

	switch (filter)
	{
	case Texture_Parameter::Min_Filter::Nearest:
		param = GL_NEAREST;
		break;
	case Texture_Parameter::Min_Filter::Linear:
		param = GL_LINEAR;
		break;
	case Texture_Parameter::Min_Filter::Nearest_MipMap_Nearest:
		param = GL_NEAREST_MIPMAP_NEAREST;
		break;
	case Texture_Parameter::Min_Filter::Nearest_MipMap_Linear:
		param = GL_NEAREST_MIPMAP_LINEAR;
		break;
	case Texture_Parameter::Min_Filter::Linear_MipMap_Nearest:
		param = GL_LINEAR_MIPMAP_NEAREST;
		break;
	case Texture_Parameter::Min_Filter::Linear_MipMap_Linear:
		param = GL_LINEAR_MIPMAP_LINEAR;
		break;
	default:
		throw(new std::exception("Wrong Texture Min Filter"));
		break;
	}

	_setParameteri(GL_TEXTURE_MIN_FILTER, param);
}

void Texture::setMinLOD(float value)
{
	_setParameterf(GL_TEXTURE_MIN_LOD, value);
}

void Texture::setPriority(float value)
{
	_setParameterf(GL_TEXTURE_PRIORITY, value);
}

void Texture::setSwizzleR(Texture_Parameter::Swizzle swizzle)
{
	GLenum param;

	switch (swizzle)
	{
	case Texture_Parameter::Swizzle::Red:
		param = GL_RED;
		break;
	case Texture_Parameter::Swizzle::Green:
		param = GL_GREEN;
		break;
	case Texture_Parameter::Swizzle::Blue:
		param = GL_BLUE;
		break;
	case Texture_Parameter::Swizzle::Alpha:
		param = GL_ALPHA;
		break;
	case Texture_Parameter::Swizzle::Zero:
		param = GL_ZERO;
		break;
	case Texture_Parameter::Swizzle::One:
		param = GL_ONE;
		break;
	default:
		throw(new std::exception("Wrong Texture Swizzle R"));
		break;
	}

	_setParameteri(GL_TEXTURE_SWIZZLE_R, param);
}

void Texture::setSwizzleG(Texture_Parameter::Swizzle swizzle)
{
	GLenum param;

	switch (swizzle)
	{
	case Texture_Parameter::Swizzle::Red:
		param = GL_RED;
		break;
	case Texture_Parameter::Swizzle::Green:
		param = GL_GREEN;
		break;
	case Texture_Parameter::Swizzle::Blue:
		param = GL_BLUE;
		break;
	case Texture_Parameter::Swizzle::Alpha:
		param = GL_ALPHA;
		break;
	case Texture_Parameter::Swizzle::Zero:
		param = GL_ZERO;
		break;
	case Texture_Parameter::Swizzle::One:
		param = GL_ONE;
		break;
	default:
		throw(new std::exception("Wrong Texture Swizzle G"));
		break;
	}

	_setParameteri(GL_TEXTURE_SWIZZLE_G, param);
}

void Texture::setSwizzleB(Texture_Parameter::Swizzle swizzle)
{
	GLenum param;

	switch (swizzle)
	{
	case Texture_Parameter::Swizzle::Red:
		param = GL_RED;
		break;
	case Texture_Parameter::Swizzle::Green:
		param = GL_GREEN;
		break;
	case Texture_Parameter::Swizzle::Blue:
		param = GL_BLUE;
		break;
	case Texture_Parameter::Swizzle::Alpha:
		param = GL_ALPHA;
		break;
	case Texture_Parameter::Swizzle::Zero:
		param = GL_ZERO;
		break;
	case Texture_Parameter::Swizzle::One:
		param = GL_ONE;
		break;
	default:
		throw(new std::exception("Wrong Texture Swizzle B"));
		break;
	}

	_setParameteri(GL_TEXTURE_SWIZZLE_B, param);
}

void Texture::setSwizzleA(Texture_Parameter::Swizzle swizzle)
{
	GLenum param;

	switch (swizzle)
	{
	case Texture_Parameter::Swizzle::Red:
		param = GL_RED;
		break;
	case Texture_Parameter::Swizzle::Green:
		param = GL_GREEN;
		break;
	case Texture_Parameter::Swizzle::Blue:
		param = GL_BLUE;
		break;
	case Texture_Parameter::Swizzle::Alpha:
		param = GL_ALPHA;
		break;
	case Texture_Parameter::Swizzle::Zero:
		param = GL_ZERO;
		break;
	case Texture_Parameter::Swizzle::One:
		param = GL_ONE;
		break;
	default:
		throw(new std::exception("Wrong Texture Swizzle A"));
		break;
	}

	_setParameteri(GL_TEXTURE_SWIZZLE_A, param);
}

void Texture::setSwizzleRGBA(Texture_Parameter::Swizzle swizzleR, Texture_Parameter::Swizzle swizzleG, Texture_Parameter::Swizzle swizzleB, Texture_Parameter::Swizzle swizzleA)
{
	setSwizzleR(swizzleR);
	setSwizzleG(swizzleG);
	setSwizzleB(swizzleB);
	setSwizzleA(swizzleA);
}

void Texture::setWrapS(Texture_Parameter::Wrap_Mode mode)
{
	GLenum param;

	switch (mode)
	{
	case Texture_Parameter::Wrap_Mode::Clamp:
		param = GL_CLAMP;
		break;
	case Texture_Parameter::Wrap_Mode::Clamp_To_Edge:
		param = GL_CLAMP_TO_EDGE;
		break;
	case Texture_Parameter::Wrap_Mode::Repeat:
		param = GL_REPEAT;
		break;
	case Texture_Parameter::Wrap_Mode::Clamp_To_Border:
		param = GL_CLAMP_TO_BORDER;
		break;
	case Texture_Parameter::Wrap_Mode::Mirrored_Repeat:
		param = GL_MIRRORED_REPEAT;
		break;
	case Texture_Parameter::Wrap_Mode::Mirror_Clamp_To_Edge:
		param = GL_MIRROR_CLAMP_TO_EDGE;
		break;
	default:
		throw(new std::exception("Wrong Texture Wrap Mode"));
		break;
	}

	_setParameteri(GL_TEXTURE_WRAP_S, param);
}

void Texture::setWrapT(Texture_Parameter::Wrap_Mode mode)
{
	GLenum param;

	switch (mode)
	{
	case Texture_Parameter::Wrap_Mode::Clamp:
		param = GL_CLAMP;
		break;
	case Texture_Parameter::Wrap_Mode::Clamp_To_Edge:
		param = GL_CLAMP_TO_EDGE;
		break;
	case Texture_Parameter::Wrap_Mode::Repeat:
		param = GL_REPEAT;
		break;
	case Texture_Parameter::Wrap_Mode::Clamp_To_Border:
		param = GL_CLAMP_TO_BORDER;
		break;
	case Texture_Parameter::Wrap_Mode::Mirrored_Repeat:
		param = GL_MIRRORED_REPEAT;
		break;
	case Texture_Parameter::Wrap_Mode::Mirror_Clamp_To_Edge:
		param = GL_MIRROR_CLAMP_TO_EDGE;
		break;
	default:
		throw(new std::exception("Wrong Texture Wrap Mode"));
		break;
	}

	_setParameteri(GL_TEXTURE_WRAP_T, param);
}

void Texture::setWrapR(Texture_Parameter::Wrap_Mode mode)
{
	GLenum param;

	switch (mode)
	{
	case Texture_Parameter::Wrap_Mode::Clamp:
		param = GL_CLAMP;
		break;
	case Texture_Parameter::Wrap_Mode::Clamp_To_Edge:
		param = GL_CLAMP_TO_EDGE;
		break;
	case Texture_Parameter::Wrap_Mode::Repeat:
		param = GL_REPEAT;
		break;
	case Texture_Parameter::Wrap_Mode::Clamp_To_Border:
		param = GL_CLAMP_TO_BORDER;
		break;
	case Texture_Parameter::Wrap_Mode::Mirrored_Repeat:
		param = GL_MIRRORED_REPEAT;
		break;
	case Texture_Parameter::Wrap_Mode::Mirror_Clamp_To_Edge:
		param = GL_MIRROR_CLAMP_TO_EDGE;
		break;
	default:
		throw(new std::exception("Wrong Texture Wrap Mode"));
		break;
	}

	_setParameteri(GL_TEXTURE_WRAP_R, param);
}

GLenum Texture::GLToTextureTarget(Texture_Target target)
{
	switch (target)
	{
	case Texture_Target::Texture_1D:
		return GL_TEXTURE_1D;
	case Texture_Target::Texture_1D_ARRAY:
		return GL_TEXTURE_1D_ARRAY;
	case Texture_Target::Texture_2D:
		return GL_TEXTURE_2D;
	case Texture_Target::Texture_2D_Array:
		return GL_TEXTURE_2D_ARRAY;
	case Texture_Target::Texture_2D_MultiSample:
		return GL_TEXTURE_2D_MULTISAMPLE;
	case Texture_Target::Texture_2D_MultiSample_Array:
		return GL_TEXTURE_2D_MULTISAMPLE_ARRAY;
	case Texture_Target::Texture_3D:
		return GL_TEXTURE_3D;
	case Texture_Target::Texture_Cube:
		return GL_TEXTURE_CUBE_MAP;
	case Texture_Target::Texture_Cube_Array:
		return GL_TEXTURE_CUBE_MAP_ARRAY;
	case Texture_Target::Texture_Rectangle:
		return GL_TEXTURE_RECTANGLE;
	case Texture_Target::Texture_Buffer:
		return GL_TEXTURE_BUFFER;
	default:
		throw(new std::exception("Wrong texture target"));
	}
}

#pragma endregion

#pragma region Protected_Methods

#pragma endregion

#pragma region Private_Methods

void Texture::_setParameteri(GLenum pname, GLint param)
{
	GLenum glTarget = GLToTextureTarget(_target);
	glBindTexture(glTarget, _glName);
	glTexParameteri(glTarget, pname, param);
}

void Texture::_setParameterf(GLenum pname, GLfloat param)
{
	GLenum glTarget = GLToTextureTarget(_target);
	glBindTexture(glTarget, _glName);
	glTexParameteri(glTarget, pname, param);
}

void Texture::_setParameterfv(GLenum pname, GLfloat *params)
{
	GLenum glTarget = GLToTextureTarget(_target);
	glBindTexture(glTarget, _glName);
	glTexParameterfv(glTarget, pname, params);
}

void Texture::_setParameteriv(GLenum pname, GLint *params)
{
	GLenum glTarget = GLToTextureTarget(_target);
	glBindTexture(glTarget, _glName);
	glTexParameteriv(glTarget, pname, params);
}

#pragma endregion