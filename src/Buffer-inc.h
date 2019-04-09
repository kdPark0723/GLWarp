//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_BUFFER_INC_H
#define GLWARPER_BUFFER_INC_H

#include "../include/Buffer.h"

#include "../include/InternalGraphicLib.h"

template<unsigned int T>
GL::Buffer<T>::Buffer()
  :m_data{0} {
}

template<unsigned int T>
template<size_t N>
void GL::Buffer<T>::clear(const float (&value)[N]) {
  const GLfloat* value_p = value;
  glClearBufferfv(static_cast<GLenum>(T), static_cast<GLint>(m_data), value_p);
}

#endif //GLWARPER_BUFFER_INC_H
