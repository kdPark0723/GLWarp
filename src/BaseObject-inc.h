//
// Created by siyualbak on 19. 4. 9.
//

#ifndef GLWARPER_BASEOBJECT_INC_H
#define GLWARPER_BASEOBJECT_INC_H

#include "../include/BaseObejct.h"

#include "../include/Initializer.h"
#include "../include/ErrorHandel.h"

template<typename Derived>
gl::BaseObject<Derived>::BaseObject()
  : name{} {
  initializer().initGLLoader();
  initializer().initGL();
}

template<typename Derived>
unsigned int gl::BaseObject<Derived>::getName() const {
  if (!name) {
    errorHandle(Error::GL, "This name is not generated.");
    return 0;
  }

  return name;
}

#endif //GLWARPER_BASEOBJECT_INC_H
