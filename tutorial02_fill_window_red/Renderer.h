//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLFWPROJECWARPER_TUTORIAL02_RENDERER_H
#define GLFWPROJECWARPER_TUTORIAL02_RENDERER_H

#include "../include/Renderer.h"

class Renderer : public gl::Renderer {
 public:
  explicit Renderer(gl::Window &window);

  void render(double currentTime) override;
};

#endif //GLFWPROJECWARPER_RENDERER_H
