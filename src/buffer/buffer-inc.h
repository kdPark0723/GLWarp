//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_BUFFER_INC_H
#define GLWARPER_BUFFER_INC_H

#include <buffer/buffer.h>

#include "buffer/buffer.h"

gl::buffer::Buffer::Buffer() {
  glGenBuffers(1, &name);
}

gl::buffer::Buffer::~Buffer() {
  glDeleteBuffers(1, &name);
}

void gl::buffer::Buffer::bind(gl::buffer::Target target) {
  glBindBuffer(util::getGLenum(target.type), name);
}

void gl::buffer::Buffer::alloc(size_t size, gl::buffer::bufferBase::Usage usage) {
  glNamedBufferData(name, util::getGLsizeiptr(size), nullptr, util::getGLenum(usage));
}

void gl::buffer::Buffer::alloc(const gl::buffer::DataAdapter &data, gl::buffer::bufferBase::Usage usage) {
  glNamedBufferData(name, util::getGLsizeiptr(data.size), data.data, util::getGLenum(usage));
}

void gl::buffer::Buffer::update(const gl::buffer::DataAdapter &data, int offset) {
  glNamedBufferSubData(name, offset, util::getGLsizeiptr(data.size), data.data);
}

void *gl::buffer::Buffer::map(gl::buffer::bufferBase::Usage usage) {
  return glMapNamedBuffer(name, util::getGLenum(usage));
}

void gl::buffer::Buffer::unmap() {
  glUnmapNamedBuffer(name);
}

void gl::buffer::Buffer::clear(const gl::buffer::TypeSupposerAdapter &data) {
  glClearNamedBufferSubData(name,
                            util::getGLenum(data.internalFormat.type),
                            0,
                            util::getGLsizeiptr(data.size),
                            util::getGLenum(data.format.type),
                            util::getGLenum(data.type.type),
                            data.data);
}

void gl::buffer::Buffer::clear(const gl::buffer::TypeSupposerAdapter &data, int offset) {
  glClearNamedBufferSubData(name,
                            util::getGLenum(data.internalFormat.type),
                            util::getGLintptr(offset),
                            util::getGLsizeiptr(data.size),
                            util::getGLenum(data.format.type),
                            util::getGLenum(data.type.type),
                            data.data);
}

#endif //GLWARPER_BUFFER_INC_H
