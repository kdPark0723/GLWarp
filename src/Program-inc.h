//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_PROGRAM_INC_H
#define GLWARPER_PROGRAM_INC_H

#include "../include/Program.h"

#include "../include/InternalGraphicLib.h"

GL::Program::Program() {
  m_data = static_cast<unsigned int>(glCreateProgram());
}
GL::Program::~Program() {
  glDeleteProgram(static_cast<GLuint>(m_data));
}

void GL::Program::link() {
  glLinkProgram(static_cast<GLuint>(m_data));
}
void GL::Program::use() {
  glUseProgram(static_cast<GLuint>(m_data));
}

template<unsigned int type>
GL::Program &GL::Program::attach(GL::Shader<type> &shader) {
  glAttachShader(static_cast<GLuint>(m_data), static_cast<GLuint>(shader.data()));

  return *this;
}

#endif