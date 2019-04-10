//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_PROGRAM_INC_H
#define GLWARPER_PROGRAM_INC_H

#include "../include/Program.h"

#include "../include/Lib.h"

gl::Program::Program()
  : BaseObject<Program>{} {
  mObjectId = static_cast<unsigned int>(glCreateProgram());
}
gl::Program::~Program() {
  glDeleteProgram(getGLuint(mObjectId));
}

void gl::Program::link() {
  glLinkProgram(getGLuint(mObjectId));
}
void gl::Program::use() {
  glUseProgram(getGLuint(mObjectId));
}

template<unsigned int type>
gl::Program &gl::Program::attach(gl::Shader<type> &shader) {
  glAttachShader(getGLuint(mObjectId), getGLuint(shader.getObjectId()));

  return *this;
}

#endif