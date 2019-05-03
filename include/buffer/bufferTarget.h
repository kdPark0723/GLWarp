//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_BUFFERTARGET_H
#define GLWARPER_BUFFERTARGET_H

#include "bufferBase.h"
#include "utils.h"

namespace gl {
namespace buffer {

class Target : public bufferBase {
 public:
  enum class Types {
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

  inline Target(Types type);
  inline virtual ~Target();

  inline virtual void alloc(size_t size, Usage usage) override;
  inline virtual void alloc(const DataAdapter &data, Usage usage) override;

  inline virtual void update(const DataAdapter &data, int offset) override;

  inline virtual void *map(Usage usage) override;
  inline virtual void unmap() override;

  inline virtual void clear(const TypeSupposerAdapter &data) override;
  inline virtual void clear(const TypeSupposerAdapter &data, int offset) override;

  Types type;
};

}
}

#include "../../src/buffer/bufferTarget-inc.h"

#endif //GLWARPER_BUFFERTARGET_H
