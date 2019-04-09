//
// Created by siyualbak on 19. 4. 7.
//

#include "Renderer.h"

#include <iostream>
#include <cmath>
#include <TessellationEvaluationShader.h>
#include <TessellationControlShader.h>

#include "../include/InternalGraphicLib.h"
#include "../include/VertexShader.h"
#include "../include/FragmentShader.h"
#include "../include/TessellationControlShader.h"
#include "../include/TessellationEvaluationShader.h"
#include "../include/ColorBuffer.h"

Renderer::Renderer(gl::Window &window)
  : gl::Renderer{window}, mProgram{}, mTriangle{} {

  gl::VertexShader vertexShader{"./shaders/vertexShader.vert"};
  vertexShader.compile();
  gl::FragmentShader fragmentShader{"./shaders/fragmentShader.frag"};
  fragmentShader.compile();
  gl::TessellationControlShader tessellationControlShader{"./shaders/tessellationControlShader.tesc"};
  tessellationControlShader.compile();
  gl::TessellationEvaluationShader tessellationEvaluationShader{"./shaders/tessellationEvaluationShader.tese"};
  tessellationControlShader.compile();

  mProgram.attach(vertexShader)
    .attach(fragmentShader)
    .attach(tessellationControlShader)
    .attach(tessellationEvaluationShader)
    .link();

  mTriangle.bind();

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

}

Renderer::~Renderer() = default;

void Renderer::render(double currentTime) {
  const float color[] = {static_cast<float>(std::sin(currentTime)) * 0.5f + 0.5f,
                         static_cast<float>(std::cos(currentTime)) * 0.5f + 0.5f,
                         .0f, 1.0f};
  gl::colorBuffer().clear(color);

  mProgram.use();

  gl::Vertex<float, 4> vertex = {static_cast<float>(std::sin(currentTime)) * 0.5f,
                                 static_cast<float>(std::cos(currentTime)) * 0.6f,
                                 .0f, .0f};
  vertex.attribute(0);
  vertex.attribute(1);

  gl::Arrays<GL_PATCHES>::getInstance().draw(0, 3);
}
