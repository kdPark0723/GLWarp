//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_TUTORIAL05_RENDERER_H
#define GLWARPER_TUTORIAL05_RENDERER_H

#include "../include/Renderer.h"
#include "../include/Program.h"
#include "../include/VertexArray.h"

class Renderer : public GL::Renderer {
 public:
  explicit Renderer(GL::Window& window);
  ~Renderer() override;

  void render(double current_time) override;
 private:
  GL::Program m_program;
  GL::VertexArray<1> m_triangle;
};

#endif //GLFWPROJECWARPER_RENDERER_H
