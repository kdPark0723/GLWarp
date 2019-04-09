#include "../include/Window.h"
#include "../include/Renderer.h"

int main() {
  gl::Window window{"First Window", 1024, 768};
  gl::Renderer renderer{window};

  renderer.run();

  return 0;
}


