//
// Created by siyualbak on 19. 4. 7.
//

#include "Renderer.h"

#include <GL/gl3w.h>

#include <iostream>
#include <cmath>

Renderer::Renderer(gl::Window &window) : gl::Renderer{window} {
}

void Renderer::render(double current_time) {
  const GLfloat color[] = {static_cast<float>(std::sin(current_time)) * 0.5f + 0.5f,
                           static_cast<float>(std::cos(current_time)) * 0.5f + 0.5f,
                           .0f, 1.0f};
  glClearBufferfv(GL_COLOR, 0, color);
}
