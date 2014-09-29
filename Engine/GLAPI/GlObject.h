#pragma once

#include <GL\glew.h>
#include <memory>

class GlObject
{
public:
	GLuint GlName() const;

protected:
	GLuint _glName;
};

typedef std::shared_ptr<GlObject> GlObjectPtr;