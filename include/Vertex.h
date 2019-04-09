//
// Created by siyualbak on 19. 4. 9.
//

#ifndef GLWARPER_VERTEX_H
#define GLWARPER_VERTEX_H

#include <cstddef>

namespace gl {

template<typename T, size_t Size>
struct Vertex {
  T mVertex[Size];

  inline void attribute(int index);
};

}

#include "../src/Vertex-inc.h"

#endif //GLWARPER_VERTEX_H
