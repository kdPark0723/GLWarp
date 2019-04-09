//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLFWPROJECWARPER_TUTORIAL03_RENDERER_H
#define GLFWPROJECWARPER_TUTORIAL03_RENDERER_H

#include "../include/Renderer.h"

class Renderer : public GL::Renderer {
 public:
  explicit Renderer(GL::Window& window);

  virtual void render(double current_time);
};

#endif //GLFWPROJECWARPER_RENDERER_H
