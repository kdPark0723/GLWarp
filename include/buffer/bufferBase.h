//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_BUFFERBASE_H
#define GLWARPER_BUFFERBASE_H

#include <cstddef>

#include "lowGL.h"

#include "bufferDataAdapter.h"
#include "bufferTypeSupposerAdapter.h"

namespace gl {
namespace buffer {

class bufferBase {
 public:
  enum class Usage {
    StreamDraw = GL_STREAM_DRAW,
    StreamRead = GL_STREAM_READ,
    StreamCopy = GL_STREAM_COPY,

    StaticDraw = GL_STATIC_DRAW,
    StaticRead = GL_STATIC_READ,
    StaticCopy = GL_STATIC_COPY,

    DynamicDraw = GL_DYNAMIC_DRAW,
    DynamicRead = GL_DYNAMIC_READ,
    DynamicCopy = GL_DYNAMIC_COPY,
  };

  inline bufferBase() = default;
  inline virtual ~bufferBase() = default;

  inline virtual void alloc(size_t size, Usage usage) = 0;
  inline virtual void alloc(const DataAdapter &data, Usage usage) = 0;

  inline virtual void update(const DataAdapter &data, int offset) = 0;

  inline virtual void *map(Usage usage) = 0;
  inline virtual void unmap() = 0;

  inline virtual void clear(const TypeSupposerAdapter &data) = 0;
  inline virtual void clear(const TypeSupposerAdapter &data, int offset) = 0;
};

}
}

#endif //GLWARPER_BUFFERBASE_H
