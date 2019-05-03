//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_BUFFERINTERNALFORMAT_INC_H
#define GLWARPER_BUFFERINTERNALFORMAT_INC_H

#include "buffer/bufferInternalFormat.h"

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<signed char, 1>() {
  return gl::buffer::InternalFormat{Types::R8I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<signed char, 2>() {
  return gl::buffer::InternalFormat{Types::RG8I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<signed char, 3>() {
  return gl::buffer::InternalFormat{Types::RGB8I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<signed char, 4>() {
  return gl::buffer::InternalFormat{Types::RGBA8I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned char, 1>() {
  return gl::buffer::InternalFormat{Types::R8};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned char, 2>() {
  return gl::buffer::InternalFormat{Types::RG8};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned char, 3>() {
  return gl::buffer::InternalFormat{Types::RGB8};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned char, 4>() {
  return gl::buffer::InternalFormat{Types::RGBA8};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<short, 1>() {
  return gl::buffer::InternalFormat{Types::R16I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<short, 2>() {
  return gl::buffer::InternalFormat{Types::RG16I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<short, 3>() {
  return gl::buffer::InternalFormat{Types::RGB16I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<short, 4>() {
  return gl::buffer::InternalFormat{Types::RGBA16I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned short, 1>() {
  return gl::buffer::InternalFormat{Types::R16UI};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned short, 2>() {
  return gl::buffer::InternalFormat{Types::RG16UI};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned short, 3>() {
  return gl::buffer::InternalFormat{Types::RGB16UI};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned short, 4>() {
  return gl::buffer::InternalFormat{Types::RGBA16UI};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<int, 1>() {
  return gl::buffer::InternalFormat{Types::R32I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<int, 2>() {
  return gl::buffer::InternalFormat{Types::RG32I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<int, 3>() {
  return gl::buffer::InternalFormat{Types::RGB32I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<int, 4>() {
  return gl::buffer::InternalFormat{Types::RGBA32I};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned int, 1>() {
  return gl::buffer::InternalFormat{Types::R32UI};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned int, 2>() {
  return gl::buffer::InternalFormat{Types::RG32UI};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned int, 3>() {
  return gl::buffer::InternalFormat{Types::RGB32UI};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<unsigned int, 4>() {
  return gl::buffer::InternalFormat{Types::RGBA32UI};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<float, 1>() {
  return gl::buffer::InternalFormat{Types::R32F};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<float, 2>() {
  return gl::buffer::InternalFormat{Types::RG32F};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<float, 3>() {
  return gl::buffer::InternalFormat{Types::RGB32F};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<float, 4>() {
  return gl::buffer::InternalFormat{Types::RGBA32F};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<double, 1>() {
  return gl::buffer::InternalFormat{Types::R32F};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<double, 2>() {
  return gl::buffer::InternalFormat{Types::RG32F};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<double, 3>() {
  return gl::buffer::InternalFormat{Types::RGB32F};
}

template<>
constexpr gl::buffer::InternalFormat gl::buffer::InternalFormat::get<double, 4>() {
  return gl::buffer::InternalFormat{Types::RGBA32F};
}

#endif //GLWARPER_BUFFERINTERNALFORMAT_INC_H
