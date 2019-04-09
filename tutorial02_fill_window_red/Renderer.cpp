//
// Created by siyualbak on 19. 4. 7.
//

#include "Renderer.h"

#include <GL/gl3w.h>
#include <iostream>

Renderer::Renderer(GL::Window &window) : GL::Renderer{window} {

}

void Renderer::render(double current_time) {
  static const GLfloat RED[] = {1.0f, .0f, .0f, 1.0f};
  glClearBufferfv(GL_COLOR, 0, RED);
}
