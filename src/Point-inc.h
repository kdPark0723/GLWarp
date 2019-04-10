//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_POINT_INC_H
#define GLWARPER_POINT_INC_H

#include "../include/Point.h"

#include "../include/gllib.h"

void gl::Point::size(float size) {
  glPointSize(getGLfloat(size));
}

gl::Point& gl::point() {
  return gl::Point::getInstance();
}

#endif //GLWARPER_POINT_INC_H
