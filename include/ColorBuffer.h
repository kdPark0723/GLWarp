//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_COLORBUFFER_H
#define GLWARPER_COLORBUFFER_H

#include "Buffer.h"

namespace GL {

using ColorBuffer = Buffer<static_cast<unsigned int>(GL_COLOR)>;

}

#endif //GLWARPER_COLORBUFFER_H
