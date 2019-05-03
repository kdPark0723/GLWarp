//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_BUFFERFORMAT_H
#define GLWARPER_BUFFERFORMAT_H

#include "lowGL.h"

namespace gl {
namespace buffer {

struct Format {
  enum class Types {
    RED = GL_RED,
    RG = GL_RG,
    RGB = GL_RGB,
    RGBA = GL_RGBA,
  };

  template<int N>
  constexpr static Format get();

  Types type;
};

}
}

#include "src/buffer/bufferFormat-inc.h"

#endif //GLWARPER_BUFFERFORMAT_H
