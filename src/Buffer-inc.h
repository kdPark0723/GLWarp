//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_BUFFER_INC_H
#define GLWARPER_BUFFER_INC_H

#include "../include/Buffer.h"

#include "../include/ErrorHandel.h"

gl::Buffer::Buffer(size_t size)
  : size{size}, isBind{false} {
  glGenBuffers(1, &name);
}
gl::Buffer::~Buffer() {
  glDeleteBuffers(1, &name);
}

void gl::Buffer::setSize(size_t size) {
  this->size = size;
}

void gl::Buffer::bind(Buffer::Target target) {
  this->target = target;
  glBindBuffer(gl::getGLenum(target), name);
}

void gl::Buffer::data(const GLvoid *data, Buffer::Usage usage) {
  if (!isBind)
    gl::errorHandle(gl::Error::GL, "It is't bind.");
  glBufferData(gl::getGLenum(target), gl::getGLsizeiptr(size), data, gl::getGLenum(usage));
}

void gl::Buffer::subData(int offset, const GLvoid *data) {
  glBufferSubData(gl::getGLenum(target), offset, gl::getGLsizeiptr(size), data);
}

#endif //GLWARPER_BUFFER_INC_H
