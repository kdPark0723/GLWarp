//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_INITIALIZER_H
#define GLWARPER_INITIALIZER_H

#include "Singleton.h"

namespace gl {

class Initializer : public gl::Singleton<Initializer> {
 public:
  struct Info {
    int majorVersion;
    int minorVersion;
  };

  explicit Initializer(int majorVersion = 4, int minorVersion = 3);
  ~Initializer() override;

  void initWindowSystem();
  void initGLLoader();

 private:
  Info mInfo;

  bool mIsInitedWindowSystem;
  bool mIsInitedGlLoader;
};

inline Initializer& initializer();

}

#include "../src/Initializer-inc.h"

#endif //GLFWPROJECWARPER_INITIALIZER_H
