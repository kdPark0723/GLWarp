//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_BUFFERTARGET_INC_H
#define GLWARPER_BUFFERTARGET_INC_H

#include "../../include/buffer/bufferTarget.h"

#include "../../include/utils.h"

gl::buffer::Target::Target(Types type)
  : type{type} {

}

gl::buffer::Target::~Target() {

}

void gl::buffer::Target::alloc(size_t size, gl::buffer::bufferBase::Usage usage) {
  glBufferData(gl::util::getGLenum(type), util::getGLsizeiptr(size), nullptr, util::getGLenum(usage));
}

void gl::buffer::Target::alloc(const gl::buffer::DataAdapter &data, gl::buffer::bufferBase::Usage usage) {
  glBufferData(gl::util::getGLenum(type), util::getGLsizeiptr(data.size), data.data, util::getGLenum(usage));
}

void gl::buffer::Target::update(const gl::buffer::DataAdapter &data, int offset) {
  glBufferSubData(gl::util::getGLenum(type), offset, util::getGLsizeiptr(data.size), data.data);
}

void *gl::buffer::Target::map(gl::buffer::bufferBase::Usage usage) {
  return glMapBuffer(gl::util::getGLenum(type), util::getGLenum(usage));
}

void gl::buffer::Target::unmap() {
  glUnmapBuffer(gl::util::getGLenum(type));
}

void gl::buffer::Target::clear(const gl::buffer::TypeSupposerAdapter &data) {
  glClearBufferSubData(gl::util::getGLenum(type),
                       util::getGLenum(data.internalFormat.type),
                       0,
                       util::getGLsizeiptr(data.size),
                       util::getGLenum(data.format.type),
                       util::getGLenum(data.type.type),
                       data.data);
}

void gl::buffer::Target::clear(const gl::buffer::TypeSupposerAdapter &data, int offset) {
  glClearBufferSubData(gl::util::getGLenum(type),
                       util::getGLenum(data.internalFormat.type),
                       util::getGLintptr(offset),
                       util::getGLsizeiptr(data.size),
                       util::getGLenum(data.format.type),
                       util::getGLenum(data.type.type),
                       data.data);
}

#endif //GLWARPER_BUFFERTARGET_INC_H
