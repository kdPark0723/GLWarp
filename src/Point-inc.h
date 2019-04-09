//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_POINT_INC_H
#define GLWARPER_POINT_INC_H

#include "../include/Point.h"

#include "../include/InternalGraphicLib.h"

void gl::Point::size(float size) {
  glPointSize(static_cast<GLfloat>(size));
}

gl::Point &point() {
  return gl::Point::getInstance();
}

#endif //GLWARPER_POINT_INC_H
