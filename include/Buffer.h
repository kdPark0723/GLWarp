//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_BUFFER_H
#define GLWARPER_BUFFER_H

#include "Utils.h"
#include "BaseObejct.h"

namespace gl {

class Buffer : public BaseObject<Buffer> {
 public:
  enum class Target {
    Array = GL_ARRAY_BUFFER,
    AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
    CopyRead = GL_COPY_READ_BUFFER,
    CopyWRITE = GL_COPY_WRITE_BUFFER,
    DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER,
    DrawIndirect = GL_DRAW_INDIRECT_BUFFER,
    ElementArray = GL_ELEMENT_ARRAY_BUFFER,
    PixelPack = GL_PIXEL_PACK_BUFFER,
    PixelUnpack = GL_PIXEL_UNPACK_BUFFER,
    Query = GL_QUERY_BUFFER,
    ShaderStorage = GL_SHADER_STORAGE_BUFFER,
    Texture = GL_TEXTURE_BUFFER,
    TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
    Uniform = GL_UNIFORM_BUFFER,
  };

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

  inline Buffer(size_t size = 0);
  inline virtual ~Buffer();

  inline void setSize(size_t size);

  inline void bind(Target target);
  inline void data(const GLvoid *data, Usage usage);
  inline void subData(int offset, const GLvoid *data);

 protected:
  size_t size;
  Target target;
  bool isBind;
};

}

#include "../src/Buffer-inc.h"

#endif //GLWARPER_BUFFER_H
