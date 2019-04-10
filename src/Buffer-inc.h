//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_BUFFER_INC_H
#define GLWARPER_BUFFER_INC_H

#include "../include/Buffer.h"

#include "../include/Lib.h"

template<unsigned int T>
gl::Buffer<T>::Buffer()
  : BaseObject<Buffer<T>>{} {
}

template<unsigned int T>
template<size_t N>
void gl::Buffer<T>::clear(const float (&value)[N]) {
  const GLfloat *pValue = value;
  glClearBufferfv(getGLenum(T), getGLint(BaseObject<Buffer<T>>::mObjectId), pValue);
}

#endif //GLWARPER_BUFFER_INC_H
