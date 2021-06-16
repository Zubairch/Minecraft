#pragma once

#include <MC.h>

#ifdef MINECRAFT_DEBUG

#define ASSERT(x) if(!(x)) __debugbreak();

#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

#endif

#ifdef MINECRAFT_RELEASE

#define GLCall(x) x;

#endif 

static void WhatError(GLenum error) {

    printf("OpenGL Error | ");

    switch (error) {

    case GL_INVALID_ENUM:
        printf("GL_INVAILD_ENUM");
        break;

    case GL_INVALID_VALUE:
        printf("GL_INVAILD_VALUE");
        break;

    case GL_INVALID_OPERATION:
        printf("GL_INVAILD_OPERATION");
        break;

    case GL_INVALID_FRAMEBUFFER_OPERATION:
        printf("GL_INVALID_FRAMEBUFFER_OPERATION");
        break;

    case GL_OUT_OF_MEMORY:
        printf("GL_OUT_OF_MEMORY");
        break;

    case GL_STACK_UNDERFLOW:
        printf("GL_STACK_UNDERFLOW");
        break;

    case GL_STACK_OVERFLOW:
        printf("GL_STACK_OVERFLOW");
        break;
    }
}

static bool GLLogCall(const char* function, const char* path, int line) {

    GLenum error;

    while (error = glGetError()) {

        WhatError(error);
        printf(": %s %s : %d\n", function, path, line);
        return false;
    }
    return true;
}

static void GLClearError() {

    while (glGetError() != GL_NO_ERROR);
}

