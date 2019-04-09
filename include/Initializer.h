//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_INITIALIZER_H
#define GLWARPER_INITIALIZER_H

#include "Singleton.h"

namespace GL {

class Initializer : public DesignPatterns::Singleton<Initializer> {
 public:
  struct Info {
    int major_version;
    int minor_version;
  };

  explicit Initializer(int major_version = 4, int minor_version = 3);
  ~Initializer() override;

  void initWindowSystem();
  void initGLLoader();

 private:
  Info m_info;

  bool m_is_inited_window_system;
  bool m_is_inited_gl_loader;
};

}

#endif //GLFWPROJECWARPER_INITIALIZER_H
