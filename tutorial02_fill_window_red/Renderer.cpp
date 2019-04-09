//
// Created by siyualbak on 19. 4. 7.
//

#include "Renderer.h"

#include <GL/gl3w.h>
#include <iostream>

Renderer::Renderer(gl::Window &window) : gl::Renderer{window} {

}

void Renderer::render(double) {
  static const GLfloat RED[] = {1.0f, .0f, .0f, 1.0f};
  glClearBufferfv(GL_COLOR, 0, RED);
}
