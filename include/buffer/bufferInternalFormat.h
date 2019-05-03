//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_BUFFERINTERNALFORMAT_H
#define GLWARPER_BUFFERINTERNALFORMAT_H

#include "lowGL.h"

namespace gl {
namespace buffer {

struct InternalFormat {
  enum class Types {
    R8 = GL_R8,
    R16 = GL_R16,
    R16F = GL_R16F,
    R32F = GL_R32F,
    R8I = GL_R8I,
    R16I = GL_R16I,
    R32I = GL_R32I,
    R8UI = GL_R8UI,
    R16UI = GL_R16UI,
    R32UI = GL_R32UI,
//    R32U = GL_R32U,

    RG8 = GL_RG8,
    RG16 = GL_RG16,
    RG16F = GL_RG16F,
    RG32F = GL_RG32F,
    RG8I = GL_RG8I,
    RG16I = GL_RG16I,
    RG32I = GL_RG32I,
    RG8UI = GL_RG8UI,
    RG16UI = GL_RG16UI,
    RG32UI = GL_RG32UI,

    RGB8 = GL_RGB8,
    RGB16I = GL_RGB16I,
    RGB32F = GL_RGB32F,
    RGB32I = GL_RGB32I,
    RGB8I = GL_RGB8I,
    RGB32UI = GL_RGB32UI,

    RGBA8 = GL_RGBA8,
    RGBA16 = GL_RGBA16,
    RGB16UI = GL_RGB16UI,
    RGBA16F = GL_RGBA16F,
    RGBA32F = GL_RGBA32F,
    RGBA8I = GL_RGBA8I,
    RGBA16I = GL_RGBA16I,
    RGBA32I = GL_RGBA32I,
    RGBA8UI = GL_RGBA8UI,
    RGBA16UI = GL_RGBA16UI,
    RGBA32UI = GL_RGBA32UI,
  };

  template<typename T, int N>
  constexpr static InternalFormat get();

  Types type;
};

}
}

#include "src/buffer/bufferInternalFormat-inc.h"

#endif //GLWARPER_BUFFERINTERNALFORMAT_H
