//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_RENDERER_H
#define GLWARPER_RENDERER_H

#include <chrono>

#include "Window.h"

namespace gl {

class Renderer {
 public:
  explicit Renderer(Window& window);
  virtual ~Renderer();

  virtual void run();
  virtual void render(double currentTime);

 protected:
  Window *mWindow;

  double mFrame;
};

}

#endif //GLWARPER_RENDERER_H
