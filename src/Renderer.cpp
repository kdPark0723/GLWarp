//
// Created by siyualbak on 19. 4. 7.
//

#include "../include/Renderer.h"

#include "../include/InternalGraphicLib.h"

GL::Renderer::Renderer(Window& window)
  : m_window{&window}, m_frame{} {

}
GL::Renderer::~Renderer() = default;

void GL::Renderer::run() {
  std::chrono::system_clock::time_point start_time = std::chrono::system_clock::now();
  std::chrono::system_clock::time_point frame_start_time = std::chrono::system_clock::now();
  std::chrono::duration<double> current_time{};
  std::chrono::duration<double> frame_current_time{};

  unsigned int frame = 0;

  do {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    current_time = now - start_time;
    frame_current_time = now - frame_start_time;

    frame++;
    if (frame_current_time.count() >= 1.0) {
      m_frame = 1000.0 / static_cast<double>(frame);
      frame_start_time = now;
      frame = 0;
    }

    render(current_time.count());
    m_window->update();

  } while (m_window->isClose());
}

void GL::Renderer::render(double current_time) {

}

