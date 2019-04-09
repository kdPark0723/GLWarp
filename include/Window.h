//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_WINDOW_H
#define GLWARPER_WINDOW_H

#include <string>

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

#endif //GLWARPER_WINDOW_H
