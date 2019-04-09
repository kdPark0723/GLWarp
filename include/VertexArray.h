//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_VERTEXARRAY_H
#define GLWARPER_VERTEXARRAY_H

#include "Singleton.h"

namespace gl {

template <size_t N>
class VertexArray {
 public:
  inline VertexArray();
  inline ~VertexArray();

  inline void bind();

 private:
  unsigned int mData{};
};

// Todo 인터페이스 개선 하기!!!
template <unsigned int Mode>
class Arrays : public designPatterns::Singleton<Arrays<Mode>> {
 public:
  void draw(int first, size_t count);
};

}

#include "../src/VertexArray-inc.h"

#endif //GLWARPER_VERTEXARRAY_H
