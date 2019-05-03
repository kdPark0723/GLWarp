//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_INITIALIZER_H
#define GLWARPER_INITIALIZER_H

#include "Singleton.h"

namespace gl {

class Initializer {
 public:
  struct Info {
    int majorVersion;
    int minorVersion;
  };

  static void init();

  void initWindowSystem();
  void initGLLoader();
  void initGL();

};

#include "../src/Initializer-inc.h"

#endif //GLFWPROJECWARPER_INITIALIZER_H
