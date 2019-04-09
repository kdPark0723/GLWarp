//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_BUFFER_H
#define GLWARPER_BUFFER_H

#include <glob.h>

#include "Singleton.h"

namespace gl {

// Todo 인터페이스 개선!!!
template<unsigned int T>
class Buffer : public designPatterns::Singleton<Buffer<T>> {
 public:
  inline Buffer();
  inline virtual ~Buffer() = default;

  template<size_t N>
  void clear(const float (&value)[N]);

 private:
  unsigned int mData;
};

#include "../src/Buffer-inc.h"

}

#endif //GLWARPER_BUFFER_H
