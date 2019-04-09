//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLFWPROJECWARPER_WINDOW_H
#define GLFWPROJECWARPER_WINDOW_H

#include <string>

#include "Initializer.h"

namespace GL {

class Window {
 public:
  struct Info
  {
    std::string title;
    int window_width;
    int window_height;
  };

  Window(std::string& title, int window_width, int window_height);
  Window(std::string&& title, int window_width, int window_height);
  virtual ~Window();

  int getWigth() const noexcept;
  int getHeight() const noexcept;

  void setWigth(int width) noexcept;
  void setHeight(int height) noexcept;

  void* getWindowContext();

  virtual void update();
  bool isClose();

 protected:
  Info m_info;
  void* m_window;

  inline void init();
};

}

#endif //GLFWPROJECWARPER_WINDOW_H
