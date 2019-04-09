//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_BUFFER_INC_H
#define GLWARPER_BUFFER_INC_H

#include "../include/Buffer.h"

#include "../include/InternalGraphicLib.h"

template<unsigned int T>
gl::Buffer<T>::Buffer()
  : BaseObject<Buffer<T>>{} {
}

template<unsigned int T>
template<size_t N>
void gl::Buffer<T>::clear(const float (&value)[N]) {
  const GLfloat *pValue = value;
  glClearBufferfv(static_cast<GLenum>(T), static_cast<GLint>(BaseObject<Buffer<T>>::mObjectId), pValue);
}

#endif //GLWARPER_BUFFER_INC_H
