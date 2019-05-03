//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_BUFFERTYPE_H
#define GLWARPER_BUFFERTYPE_H

#include "lowGL.h"

namespace gl {
namespace buffer {

struct Type {
  enum class Types {
    Byte = GL_BYTE,
    Unsigned_Byte = GL_UNSIGNED_BYTE,
    Short = GL_SHORT,
    Unsigned_Short = GL_UNSIGNED_SHORT,
    Int = GL_INT,
    Unsigned_Int = GL_UNSIGNED_INT,
    Float = GL_FLOAT,
    Double = GL_DOUBLE,
  };

  template<typename T>
  constexpr static Type get();

  Types type;
};

}
}

#include "src/buffer/bufferType-inc.h"

#endif //GLWARPER_BUFFERTYPE_H
