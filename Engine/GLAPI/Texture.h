#pragma once

#include "GlObject.h"
#include "DataFormat.h"

enum class Texture_Target
{
	Texture_1D,
	Texture_1D_ARRAY,
	Texture_2D,
	Texture_2D_Array,
	Texture_2D_MultiSample,
	Texture_2D_MultiSample_Array,
	Texture_3D,
	Texture_Cube,
	Texture_Cube_Array,
	Texture_Rectangle,
	Texture_Buffer
};

namespace Texture_Parameter
{
	enum class Name
	{
		Depth_Texture_Mode, Depth_Stencil_Texture_Mode,
		Generate_MipMap, Texture_Base_Level,
		Texture_Border_Color, Texture_Compare_Mode,
		Texture_Compare_Function, Texture_LOD_Bias,
		Texture_Mag_Filter, Texture_Max_Level,
		Texture_Max_LOD, Texture_Min_Filter,
		Texture_Min_LOD, Texture_Priority,
		Texture_Swizzle_R, Texture_Swizzle_G,
		Texture_Swizzle_B, Texture_Swizzle_A,
		Texture_Swizzle_RGBA, Texture_Wrap_S,
		Texture_Wrap_T, Texture_Wrap_R,
	};

	enum class Depth_Texture_Mode
	{
		Red, Luminance, Intensity, Alpha,
	};

	enum class Depth_Stencil_Texture_Mode
	{
		Depth_Component, Stencil_Index,
	};

	enum class Mag_Filter
	{
		Nearest, Linear,
	};

	enum class Min_Filter
	{
		Nearest, Linear, Nearest_MipMap_Nearest,
		Nearest_MipMap_Linear, Linear_MipMap_Nearest,
		Linear_MipMap_Linear,
	};

	enum class Texture_Compare_Mode
	{
		None, Compare_Ref_To_Texture,
	};

	enum class Compare_Function
	{
		Lequal, Gequal,
		Less, Greater,
		Equal, NotEqual,
		Always, Never,
	};

	enum class Swizzle
	{
		Red, Green, Blue, Alpha, Zero, One,
	};

	enum class Wrap_Mode
	{
		Clamp, Clamp_To_Edge, Repeat,
		Clamp_To_Border, Mirrored_Repeat, Mirror_Clamp_To_Edge,
	};
}

class Texture : public GlObject
{
	friend class TextureFactory;

public:

	static GLenum GLToTextureTarget(Texture_Target target);

	void setDepthMode(Texture_Parameter::Depth_Texture_Mode mode);
	void setDepthStencilMode(Texture_Parameter::Depth_Stencil_Texture_Mode mode);
	void setGenerateMipMap(bool generate);
	void setBaseLevel(unsigned int value);
	void setBorderColor(float red, float green, float blue, float alpha);
	void setCompareMode(Texture_Parameter::Texture_Compare_Mode mode);
	void setCompareFunction(Texture_Parameter::Compare_Function function);
	void setLODBias(float value);
	void setMagFilter(Texture_Parameter::Mag_Filter filter);
	void setMaxLevel(int value);
	void setMaxLOD(float value);
	void setMinFilter(Texture_Parameter::Min_Filter filter);
	void setMinLOD(float value);
	void setPriority(float value);
	void setSwizzleR(Texture_Parameter::Swizzle swizzle);
	void setSwizzleG(Texture_Parameter::Swizzle swizzle);
	void setSwizzleB(Texture_Parameter::Swizzle swizzle);
	void setSwizzleA(Texture_Parameter::Swizzle swizzle);
	void setSwizzleRGBA(Texture_Parameter::Swizzle swizzleR, Texture_Parameter::Swizzle swizzleG, Texture_Parameter::Swizzle swizzleB, Texture_Parameter::Swizzle swizzleA);
	void setWrapS(Texture_Parameter::Wrap_Mode mode);
	void setWrapT(Texture_Parameter::Wrap_Mode mode);
	void setWrapR(Texture_Parameter::Wrap_Mode mode);

	~Texture();


	Texture_Format format() const;
	Texture_Target target() const;
	bool isMutable() const;
	
private:
	Texture(Texture_Target target, Texture_Format format, bool isMutable);

	void _setParameteri(GLenum pname, GLint param);
	void _setParameterf(GLenum pname, GLfloat param);
	void _setParameteriv(GLenum pname, GLint *params);
	void _setParameterfv(GLenum pname, GLfloat *params);

	Texture_Target _target;
	Texture_Format _format;
	bool _isMutable;
};

typedef std::shared_ptr<Texture> TexturePtr;