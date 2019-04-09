//
// Created by siyualbak on 19. 4. 9.
//

#ifndef GLWARPER_INITIALIZER_INC_H
#define GLWARPER_INITIALIZER_INC_H

#include "../include/Initializer.h"

gl::Initializer& gl::initializer() {
  return gl::Initializer::getInstance();
}

#endif //GLWARPER_INITIALIZER_INC_H
