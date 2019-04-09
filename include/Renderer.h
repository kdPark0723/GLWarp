//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_RENDERER_H
#define GLWARPER_RENDERER_H

#include <chrono>

#include "Window.h"

namespace GL {

class Renderer {
 public:
  explicit Renderer(Window& window);
  virtual ~Renderer();

  virtual void run();
  virtual void render(double current_time);

 protected:
  Window* m_window;

  double m_frame;
};

}

#endif //GLWARPER_RENDERER_H
