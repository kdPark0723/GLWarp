//
// Created by siyualbak on 19. 4. 9.
//

#ifndef GLWARPER_COLORBUFFER_INC_H
#define GLWARPER_COLORBUFFER_INC_H

#include "../include/ColorBuffer.h"

gl::ColorBuffer &colorBuffer() {
  gl::ColorBuffer::getInstance();
}

#endif //GLWARPER_COLORBUFFER_INC_H
