//
// Created by siyualbak on 19. 4. 9.
//

#ifndef GLWARPER_PATCHER_H
#define GLWARPER_PATCHER_H

#include "utils.h"

namespace gl {

template<unsigned int T>
class Parcher {
 public:
  inline void patchParameter(int value);
};

using VertexPatcher = Parcher<GL_PATCH_VERTICES>;

}

#include "../src/Point-inc.h"

#endif //GLWARPER_PATCHER_H
