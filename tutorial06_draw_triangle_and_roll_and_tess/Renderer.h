//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_TUTORIAL05_RENDERER_H
#define GLWARPER_TUTORIAL05_RENDERER_H

#include "../include/Renderer.h"
#include "../include/Program.h"
#include "../include/VertexArray.h"

class Renderer : public gl::Renderer {
 public:
  explicit Renderer(gl::Window &window);
  ~Renderer() override;

  void render(double currentTime) override;
 private:
  gl::Program mProgram;
  gl::VertexArray<1> mTriangle;
};

#endif //GLFWPROJECWARPER_RENDERER_H
