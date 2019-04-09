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

Renderer::Renderer(GL::Window &window)
  : GL::Renderer{window}, m_program{}, m_point{} {

  GL::VertexShader vertex_shader{"./shaders/simpleVertexShader.vertexshader"};
  vertex_shader.compile();
  GL::FragmentShader fragment_shader{"./shaders/simpleFragmentShader.fragmentshader"};
  fragment_shader.compile();

  m_program.attach(vertex_shader)
    .attach(fragment_shader)
    .link();

  m_point.bind();

  GL::Point::getInstance().size(40.0f);
}

Renderer::~Renderer() = default;

void Renderer::render(double current_time) {
  static const float black[] = {0.0f, 0.0f, 0.0f, 1.0f};
  GL::ColorBuffer::getInstance().clear(black);

  m_program.use();

  GL::Arrays<GL_POINTS>::getInstance().draw(0, 1);
}
