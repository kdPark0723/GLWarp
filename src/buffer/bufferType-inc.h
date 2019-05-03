//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_BUFFERTYPE_INC_H
#define GLWARPER_BUFFERTYPE_INC_H

#include "buffer/bufferType.h"

template<>
constexpr gl::buffer::Type gl::buffer::Type::get<signed char>() {
  return gl::buffer::Type{Types::Byte};
}

template<>
constexpr gl::buffer::Type gl::buffer::Type::get<unsigned char>() {
  return gl::buffer::Type{Types::Unsigned_Byte};
}

template<>
constexpr gl::buffer::Type gl::buffer::Type::get<signed short>() {
  return gl::buffer::Type{Types::Short};
}

template<>
constexpr gl::buffer::Type gl::buffer::Type::get<unsigned short>() {
  return gl::buffer::Type{Types::Unsigned_Short};
}

template<>
constexpr gl::buffer::Type gl::buffer::Type::get<signed int>() {
  return gl::buffer::Type{Types::Int};
}

template<>
constexpr gl::buffer::Type gl::buffer::Type::get<unsigned int>() {
  return gl::buffer::Type{Types::Unsigned_Int};
}

template<>
constexpr gl::buffer::Type gl::buffer::Type::get<float>() {
  return gl::buffer::Type{Types::Float};
}

template<>
constexpr gl::buffer::Type gl::buffer::Type::get<double>() {
  return gl::buffer::Type{Types::Double};
}

#endif //GLWARPER_BUFFERTYPE_INC_H
