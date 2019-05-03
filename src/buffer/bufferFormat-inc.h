//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_BUFFERFORMAT_INC_H
#define GLWARPER_BUFFERFORMAT_INC_H

#include "buffer/bufferFormat.h"

template<>
constexpr gl::buffer::Format gl::buffer::Format::get<1>() {
  return gl::buffer::Format{Types::RED};
}

template<>
constexpr gl::buffer::Format gl::buffer::Format::get<2>() {
  return gl::buffer::Format{Types::RG};
}

template<>
constexpr gl::buffer::Format gl::buffer::Format::get<3>() {
  return gl::buffer::Format{Types::RGB};
}

template<>
constexpr gl::buffer::Format gl::buffer::Format::get<4>() {
  return gl::buffer::Format{Types::RGBA};
}

#endif //GLWARPER_BUFFERFORMAT_INC_H
