//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_COLORBUFFER_H
#define GLWARPER_COLORBUFFER_H

#include "Buffer.h"

namespace gl {

using ColorBuffer = Buffer<static_cast<unsigned int>(GL_COLOR)>;

inline ColorBuffer &colorBuffer();

}

#include "../src/ColorBuffer-inc.h"

#endif //GLWARPER_COLORBUFFER_H
