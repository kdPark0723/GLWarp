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

GL::Window::Window(std::string& title, int window_width, int window_height)
  : m_info {} {
  m_info.title = title;
  m_info.window_width = window_width;
  m_info.window_height = window_height;

  Initializer::getInstance().initWindowSystem();
  init();
  Initializer::getInstance().initGLLoader();
}
GL::Window::Window(std::string&& title, int window_width, int window_height)
  : m_info {} {
  m_info.title = title;
  m_info.window_width = window_width;
  m_info.window_height = window_height;

  Initializer::getInstance().initWindowSystem();
  init();
  Initializer::getInstance().initGLLoader();
}

GL::Window::~Window() {
  glfwDestroyWindow(static_cast<GLFWwindow*>(m_window));
}

int GL::Window::getWigth() const noexcept {
  return m_info.window_width;
}
int GL::Window::getHeight() const noexcept {
  return m_info.window_height;
}
void GL::Window::setWigth(int width) noexcept {
  m_info.window_width = width;
}
void GL::Window::setHeight(int height) noexcept {
  m_info.window_height = height;
}

void *GL::Window::getWindowContext() {
  return m_window;
}

void GL::Window::update() {
  // 버퍼들을 교체
  glfwSwapBuffers(static_cast<GLFWwindow*>(m_window));
  glfwPollEvents();
}

bool GL::Window::isClose() {
  return glfwGetKey(static_cast<GLFWwindow*>(m_window), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
    glfwWindowShouldClose(static_cast<GLFWwindow*>(m_window)) == 0;
}

void GL::Window::init() {
  m_window = glfwCreateWindow(m_info.window_width, m_info.window_height, m_info.title.c_str(), nullptr, nullptr);
  if (m_window == nullptr) {
    errorCallback(0, "Failed to open GLFW window. If you have an Intel GPU, they are not 4.3 compatible.");
    return;
  }
  glfwMakeContextCurrent(static_cast<GLFWwindow*>(m_window));

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(static_cast<GLFWwindow*>(m_window), GLFW_STICKY_KEYS, GL_TRUE);
}

#endif