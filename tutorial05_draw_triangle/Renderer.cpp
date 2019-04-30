//
// Created by siyualbak on 19. 4. 7.
//

#include "Renderer.h"

#include <iostream>
#include <cmath>

#include "../include/Lib.h"
#include "../include/VertexShader.h"
#include "../include/FragmentShader.h"
#include "../include/ColorBuffer.h"

Renderer::Renderer(gl::Window &window)
  : gl::Renderer{window}, mProgram{}, mTriangle{} {

  gl::VertexShader vertexShader{"./shaders/simpleVertexShader.glsl"};
  vertexShader.compile();
  gl::FragmentShader fragmentShader{"./shaders/simpleFragmentShader.glsl"};
  fragmentShader.compile();

  mProgram.attach(vertexShader)
    .attach(fragmentShader)
    .link();

  mTriangle.bind();

}

Renderer::~Renderer() = default;

void Renderer::render(double) {
  static const float black[] = {0.0f, 0.0f, 0.0f, 1.0f};
  gl::colorBuffer().clear(black);

  mProgram.use();

  gl::Arrays<GL_TRIANGLES>::getInstance().draw(0, 3);
}
