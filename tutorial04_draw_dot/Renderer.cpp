//
// Created by siyualbak on 19. 4. 7.
//

#include "Renderer.h"

#include <iostream>
#include <cmath>

#include "../include/InternalGraphicLib.h"
#include "../include/VertexShader.h"
#include "../include/FragmentShader.h"
#include "../include/ColorBuffer.h"
#include "../include/Point.h"

Renderer::Renderer(gl::Window &window)
  : gl::Renderer{window}, mProgram{}, mPoint{} {

  gl::VertexShader vertexShader{"./shaders/simpleVertexShader.vertexshader"};
  vertexShader.compile();
  gl::FragmentShader fragmentShader{"./shaders/simpleFragmentShader.fragmentshader"};
  fragmentShader.compile();

  mProgram.attach(vertexShader)
    .attach(fragmentShader)
    .link();

  mPoint.bind();

  gl::point().size(40.0f);
}

Renderer::~Renderer() = default;

void Renderer::render(double) {
  static const float black[] = {0.0f, 0.0f, 0.0f, 1.0f};
  gl::colorBuffer().clear(black);

  mProgram.use();

  gl::Arrays<GL_POINTS>::getInstance().draw(0, 1);
}
