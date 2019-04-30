//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_PROGRAM_INC_H
#define GLWARPER_PROGRAM_INC_H

#include "../include/Program.h"

#include "../include/Lib.h"

gl::Program::Program()
  : BaseObject<Program>{} {
  name = static_cast<unsigned int>(glCreateProgram());
}
gl::Program::~Program() {
  glDeleteProgram(getGLuint(name));
}

void gl::Program::link() {
  glLinkProgram(getGLuint(name));
}
void gl::Program::use() {
  glUseProgram(getGLuint(name));
}

template<unsigned int type>
gl::Program &gl::Program::attach(gl::Shader<type> &shader) {
  // Todo 쉐이더가 컴파일 되었는지 확인은 프로그램 링크 할때 체크하게 옮길것!!
//  if (!shader.isCompiled()) {
//    errorHandle(Error::GL, "This Shader isn't compiled. Please compile shader.");
//    return *this;
//  }

  glAttachShader(getGLuint(name), getGLuint(shader.getName()));

  return *this;
}

#endif