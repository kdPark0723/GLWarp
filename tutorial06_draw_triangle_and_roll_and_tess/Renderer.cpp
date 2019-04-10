//
// Created by siyualbak on 19. 4. 7.
//

#include "Renderer.h"

#include <iostream>
#include <cmath>
#include <TessellationEvaluationShader.h>
#include <TessellationControlShader.h>

#include "../include/Lib.h"
#include "../include/VertexShader.h"
#include "../include/FragmentShader.h"
#include "../include/TessellationControlShader.h"
#include "../include/TessellationEvaluationShader.h"
#include "../include/ColorBuffer.h"
#include "../include/Polygon.h"

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
    .attach(tessellationControlShader)
    .attach(tessellationEvaluationShader)
    .attach(fragmentShader)
    .link();

  mTriangle.bind();

  gl::Polygon{}.mode(GL_FRONT_AND_BACK, GL_LINE);
}

Renderer::~Renderer() = default;

void Renderer::render(double currentTime) {
  static const float green[] = {0.0f, 0.25f, 0.0f, 1.0f};
  gl::colorBuffer().clear(green);

  mProgram.use();

  gl::Arrays<GL_PATCHES>::getInstance().draw(0, 3);
}
