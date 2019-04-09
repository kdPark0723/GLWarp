//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_PROGRAM_INC_H
#define GLWARPER_PROGRAM_INC_H

#include "../include/Program.h"

#include "../include/InternalGraphicLib.h"

gl::Program::Program()
  : BaseObject<Program>{} {
  mObjectId = static_cast<unsigned int>(glCreateProgram());
}
gl::Program::~Program() {
  glDeleteProgram(static_cast<GLuint>(mObjectId));
}

void gl::Program::link() {
  glLinkProgram(static_cast<GLuint>(mObjectId));
}
void gl::Program::use() {
  glUseProgram(static_cast<GLuint>(mObjectId));
}

template<unsigned int type>
gl::Program &gl::Program::attach(gl::Shader<type> &shader) {
  glAttachShader(static_cast<GLuint>(mObjectId), static_cast<GLuint>(shader.getObjectId()));

  return *this;
}

#endif