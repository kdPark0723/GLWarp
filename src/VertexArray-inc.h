//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_VERTEXARRAY_INC_H
#define GLWARPER_VERTEXARRAY_INC_H

#include "../include/VertexArray.h"

#include "../include/InternalGraphicLib.h"

template<size_t N>
GL::VertexArray<N>::VertexArray() {
  glGenVertexArrays(static_cast<GLenum>(N), static_cast<GLuint *>(&m_data));
}
template<size_t N>
GL::VertexArray<N>::~VertexArray() {
  glDeleteVertexArrays(static_cast<GLenum>(N), static_cast<GLuint *>(&m_data));
}
template<size_t N>
void GL::VertexArray<N>::bind() {
  glBindVertexArray(static_cast<GLenum>(m_data));
}

template<unsigned int Mode>
void GL::Arrays<Mode>::draw(int first, size_t count) {
  glDrawArrays(static_cast<GLenum>(Mode), static_cast<GLint>(first), static_cast<GLsizei>(count));
}
#endif
