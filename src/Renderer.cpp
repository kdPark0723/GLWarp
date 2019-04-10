//
// Created by siyualbak on 19. 4. 7.
//

#include "../include/Renderer.h"

#include "../include/Initializer.h"

gl::Renderer::Renderer(Window &window)
  : mWindow{&window}, mFrame{} {
  initializer().initGLLoader();
  initializer().initGL();
}
gl::Renderer::~Renderer() = default;

void gl::Renderer::run() {
  std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();
  std::chrono::system_clock::time_point frameStartTime = std::chrono::system_clock::now();
  std::chrono::duration<double> currentTime{};
  std::chrono::duration<double> frameCurrentTime{};

  unsigned int frame = 0;

  do {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    currentTime = now - startTime;
    frameCurrentTime = now - frameStartTime;

    frame++;
    if (frameCurrentTime.count() >= 1.0) {
      mFrame = 1000.0 / static_cast<double>(frame);
      frameStartTime = now;
      frame = 0;
    }

    render(currentTime.count());
    mWindow->update();

  } while (mWindow->isClose());
}

void gl::Renderer::render(double) {

}

