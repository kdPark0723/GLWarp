//
// Created by siyualbak on 19. 4. 9.
//

#ifndef GLWARPER_COLORBUFFER_INC_H
#define GLWARPER_COLORBUFFER_INC_H

#include "../include/ColorBuffer.h"

gl::ColorBuffer& gl::colorBuffer() {
  return gl::ColorBuffer::getInstance();
}

#endif //GLWARPER_COLORBUFFER_INC_H
