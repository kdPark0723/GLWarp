//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_BUFFERTYPESUPPOSERADAPTER_H
#define GLWARPER_BUFFERTYPESUPPOSERADAPTER_H

#include <cstddef>

#include "bufferDataAdapter.h"
#include "bufferInternalFormat.h"
#include "bufferFormat.h"
#include "bufferType.h"

namespace gl {
namespace buffer {

struct TypeSupposerAdapter : public DataAdapter {
  template<typename T>
  TypeSupposerAdapter(const T data)
    : DataAdapter(data), type{Type::get<T>()}, format{Format::get<1>()}, internalFormat{InternalFormat::get<T, 1>()} {}

  template<typename T, int N>
  TypeSupposerAdapter(const T (&data)[N])
    : DataAdapter(data), type{Type::get<T>()}, format{Format::get<N>()}, internalFormat{InternalFormat::get<T, N>()} {}

  Type type;
  Format format;
  InternalFormat internalFormat;
};

}
}

#endif //GLWARPER_BUFFERTYPESUPPOSERADAPTER_H
