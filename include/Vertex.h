//
// Created by siyualbak on 19. 4. 9.
//

#ifndef GLWARPER_VERTEX_H
#define GLWARPER_VERTEX_H

#include <array>

namespace gl {

template<typename T, size_t Size>
class Vertex {
 public:
  inline Vertex();
  inline Vertex(T &x);
  inline Vertex(T &x, T &y);
  inline Vertex(T &x, T &y, T &z);
  inline Vertex(T &x, T &y, T &z, T &w);

  inline Vertex(T &&x);
  inline Vertex(T &&x, T &&y);
  inline Vertex(T &&x, T &&y, T &&z);
  inline Vertex(T &&x, T &&y, T &&z, T &&w);


  inline void attribute(int index);
 private:
  std::array<T, Size> mStorage;
};

}

#include "../src/Vertex-inc.h"

#endif //GLWARPER_VERTEX_H
