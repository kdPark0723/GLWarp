//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_VERTEXARRAY_INC_H
#define GLWARPER_VERTEXARRAY_INC_H

#include "../include/VertexArray.h"

#include "../include/Lib.h"

template<size_t N>
gl::VertexArray<N>::VertexArray() {
  glGenVertexArrays(static_cast<GLenum>(N), &mData);
}
template<size_t N>
gl::VertexArray<N>::~VertexArray() {
  glDeleteVertexArrays(static_cast<GLenum>(N), &mData);
}
template<size_t N>
void gl::VertexArray<N>::bind() {
  glBindVertexArray(static_cast<GLenum>(mData));
}

template<unsigned int Mode>
void gl::Arrays<Mode>::draw(int first, size_t count) {
  glDrawArrays(static_cast<GLenum>(Mode), static_cast<GLint>(first), static_cast<GLsizei>(count));
}
#endif
