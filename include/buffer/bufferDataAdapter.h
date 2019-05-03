//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_BUFFERDATAADAPTER_H
#define GLWARPER_BUFFERDATAADAPTER_H

#include <cstddef>

namespace gl {
namespace buffer {

struct DataAdapter {
  template<typename T>
  DataAdapter(const T &data) : data{&data}, size{sizeof(T)} {}
  template<typename T, int N>
  DataAdapter(const T (&data)[N]) : data{data}, size{sizeof(T[N])} {}

  void *data;
  size_t size;
};

}
}

#endif //GLWARPER_BUFFERDATAADAPTER_H
