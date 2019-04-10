//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_WINDOW_H
#define GLWARPER_WINDOW_H

#include <string>

namespace gl {

class Window {
 public:
  struct Info
  {
    std::string title;
    int windowWidth;
    int windowHeight;
  };

  Window(std::string& title, int windowWidth, int windowHeight);
  Window(std::string&& title, int windowWidth, int windowHeight);
  virtual ~Window();

  int getWigth() const noexcept;
  int getHeight() const noexcept;

  void reSize(int width, int height);

  void* getWindowContext();

  virtual void update();
  bool isClose();

 protected:
  Info mInfo;
  void* mWindow;

  inline void init();
};

}

#endif //GLWARPER_WINDOW_H
