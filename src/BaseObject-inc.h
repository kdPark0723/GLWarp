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
  : mObjectId{} {
  initializer().initGLLoader();
}

template<typename Derived>
unsigned int gl::BaseObject<Derived>::getObjectID() const {
  if (!mObjectId) {
    errorHandle(Error::GL, "This ID is not generated.");
    return 0;
  }

  return mObjectId;
}

#endif //GLWARPER_BASEOBJECT_INC_H
