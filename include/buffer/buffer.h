//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_BUFFERBUFFER_H
#define GLWARPER_BUFFERBUFFER_H

#include "lowGL.h"

#include "bufferBase.h"
#include "bufferTarget.h"

namespace gl {
namespace buffer {

class Buffer : public bufferBase {
 public:
  inline Buffer();
  inline virtual ~Buffer();

  inline void bind(Target target);

  inline virtual void alloc(size_t size, Usage usage) override;
  inline virtual void alloc(const DataAdapter &data, Usage usage) override;

  inline virtual void update(const DataAdapter &data, int offset) override;

  inline virtual void *map(Usage usage) override;
  inline virtual void unmap() override;

  inline virtual void clear(const TypeSupposerAdapter &data) override;
  inline virtual void clear(const TypeSupposerAdapter &data, int offset) override;

 private:
  GLuint name;
};

}
}

#include "src/buffer/buffer-inc.h"

#endif //GLWARPER_BUFFER_H
