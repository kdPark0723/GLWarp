//
// Created by siyualbak on 19. 4. 9.
//

#ifndef GLWARPER_BASEOBEJCT_H
#define GLWARPER_BASEOBEJCT_H

#include "utils.h"

namespace gl {

template <typename Derived>
class BaseObject {
 public:
  inline BaseObject();
  ~BaseObject() = default;

  inline unsigned int getName() const;

 protected:
  GLuint name;
};

}

#include "../src/BaseObject-inc.h"

#endif //GLWARPER_BASEOBEJCT_H
