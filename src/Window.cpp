//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLFWPROJECWARPER_WINDOW_INC_H
#define GLFWPROJECWARPER_WINDOW_INC_H

#include "../include/Window.h"

#include <chrono>
#include <GLFW/glfw3.h>

#include "../include/Initializer.h"
#include "../include/ErrorHandel.h"

gl::Window::Window(std::string &title, int windowWidth, int windowHeight)
  : mInfo{}, mWindow{} {
  mInfo.title = title;
  mInfo.windowWidth = windowWidth;
  mInfo.windowHeight = windowHeight;

  Initializer::getInstance().initWindowSystem();
  init();
  Initializer::getInstance().initGLLoader();
}
gl::Window::Window(std::string &&title, int windowWidth, int windowHeight)
  : mInfo{}, mWindow{} {
  mInfo.title = title;
  mInfo.windowWidth = windowWidth;
  mInfo.windowHeight = windowHeight;

  Initializer::getInstance().initWindowSystem();
  init();
  Initializer::getInstance().initGLLoader();
}

gl::Window::~Window() {
  glfwDestroyWindow(static_cast<GLFWwindow *>(mWindow));
}

int gl::Window::getWigth() const noexcept {
  return mInfo.windowWidth;
}
int gl::Window::getHeight() const noexcept {
  return mInfo.windowHeight;
}
void gl::Window::setWigth(int width) noexcept {
  mInfo.windowWidth = width;
}
void gl::Window::setHeight(int height) noexcept {
  mInfo.windowHeight = height;
}

void *gl::Window::getWindowContext() {
  return mWindow;
}

void gl::Window::update() {
  // 버퍼들을 교체
  glfwSwapBuffers(static_cast<GLFWwindow *>(mWindow));
  glfwPollEvents();
}

bool gl::Window::isClose() {
  return glfwGetKey(static_cast<GLFWwindow *>(mWindow), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
    glfwWindowShouldClose(static_cast<GLFWwindow *>(mWindow)) == 0;
}

void gl::Window::init() {
  mWindow = glfwCreateWindow(mInfo.windowWidth, mInfo.windowHeight, mInfo.title.c_str(), nullptr, nullptr);
  if (mWindow == nullptr) {
    errorHandle(0, "Failed to open GLFW window.");
    return;
  }
  glfwMakeContextCurrent(static_cast<GLFWwindow *>(mWindow));

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(static_cast<GLFWwindow *>(mWindow), GLFW_STICKY_KEYS, GL_TRUE);
}

#endif