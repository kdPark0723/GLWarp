//
// Created by siyualbak on 19. 4. 10.
//

#ifndef GLWARPER_POLYGON_INC_H
#define GLWARPER_POLYGON_INC_H

#include "../include/Polygon.h"

#include "Lib.h"

inline void mode(unsigned int face, unsigned int mode);
inline void offset(float factor, float units);

void gl::Polygon::mode(unsigned int face, unsigned int mode) {
  glPolygonMode(getGLenum(face), getGLenum(mode));
}

void gl::Polygon::offset(float factor, float units) {
  glPolygonOffset(getGLfloat(factor), getGLfloat(units));
}

#endif //GLWARPER_POLYGON_INC_H
