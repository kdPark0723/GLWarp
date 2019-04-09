//
// Created by siyualbak on 19. 4. 7.
//

#include "include/Initializer.h"

#include "../include/InternalGraphicLib.h"
#include <GLFW/glfw3.h>

#include "../include/ErrorHandel.h"

GL::Initializer::Initializer(int major_version, int minor_version)
  : m_info{major_version, minor_version}, m_is_inited_window_system{false}, m_is_inited_gl_loader{false} {
}

GL::Initializer::~Initializer() {
  if (m_is_inited_window_system)
    glfwTerminate();
}

void GL::Initializer::initWindowSystem() {
  if (m_is_inited_window_system)
    return;

  if (!glfwInit()) {
    errorCallback(0, "Failed to initialize GLFW.");
    return;
  }

  glfwSetErrorCallback(errorCallback);

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_info.major_version);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_info.minor_version);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  m_is_inited_window_system = true;
}
void GL::Initializer::initGLLoader() {
  if (m_is_inited_gl_loader)
    return;

  if (gl3wInit()) {
    errorCallback(0, "Failed to initialize gl3w.");
    return;
  }
  if (!gl3wIsSupported(m_info.major_version, m_info.minor_version)) {
    errorCallback(0, "This version not supported.");
    return;
  }

  m_is_inited_gl_loader = true;
}