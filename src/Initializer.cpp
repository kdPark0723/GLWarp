//
// Created by siyualbak on 19. 4. 7.
//

#include "include/Initializer.h"

#include "../include/InternalGraphicLib.h"
#include <GLFW/glfw3.h>
#include <sstream>

#include "../include/ErrorHandel.h"

void glfwErrorHandle(int error, const char *description) {
  std::stringstream stringStream{};
  stringStream << "[Code: " << error << "]" << description;

  gl::errorHandle(gl::Error::GLFW, stringStream.str());
}

gl::Initializer::Initializer(int majorVersion, int minorVersion)
  : mInfo{majorVersion, minorVersion}, mIsInitedWindowSystem{false}, mIsInitedGlLoader{false} {
}

gl::Initializer::~Initializer() {
  if (mIsInitedWindowSystem)
    glfwTerminate();
}

void gl::Initializer::initWindowSystem() {
  if (mIsInitedWindowSystem)
    return;

  if (!glfwInit()) {
    errorHandle(0, "Failed to initialize GLFW.");
    return;
  }

  glfwSetErrorCallback(glfwErrorHandle);

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, mInfo.majorVersion);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, mInfo.minorVersion);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  mIsInitedWindowSystem = true;
}
void gl::Initializer::initGLLoader() {
  if (mIsInitedGlLoader)
    return;

  if (gl3wInit()) {
    errorHandle(Error::GL3W, "Failed to initialize gl3w.");
    return;
  }
  if (!gl3wIsSupported(mInfo.majorVersion, mInfo.minorVersion)) {
    errorHandle(Error::GL3W, "This version not supported.");
    return;
  }

  mIsInitedGlLoader = true;
}