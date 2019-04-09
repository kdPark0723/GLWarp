//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_PROGRAM_INC_H
#define GLWARPER_PROGRAM_INC_H

#include "../include/Program.h"

#include "../include/InternalGraphicLib.h"

gl::Program::Program() {
  mData = static_cast<unsigned int>(glCreateProgram());
}
gl::Program::~Program() {
  glDeleteProgram(static_cast<GLuint>(mData));
}

void gl::Program::link() {
  glLinkProgram(static_cast<GLuint>(mData));
}
void gl::Program::use() {
  glUseProgram(static_cast<GLuint>(mData));
}

template<unsigned int type>
gl::Program &gl::Program::attach(gl::Shader<type> &shader) {
  glAttachShader(static_cast<GLuint>(mData), static_cast<GLuint>(shader.data()));

  return *this;
}

#endif