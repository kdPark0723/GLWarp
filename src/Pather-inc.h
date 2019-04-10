//
// Created by siyualbak on 19. 4. 9.
//

#ifndef GLWARPER_PATHER_INC_H
#define GLWARPER_PATHER_INC_H

#include "../include/Patcher.h"

template<unsigned int T>
void gl::Parcher<T>::patchParameter(int value) {
  glPatchParameteri(getGLenum(T), getGLint(value));
}

#endif //GLWARPER_PATHER_INC_H
