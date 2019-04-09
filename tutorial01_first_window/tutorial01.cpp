#include "../include/Window.h"
#include "../include/Renderer.h"

int main() {
  GL::Window window{"First Window", 1024, 768};
  GL::Renderer renderer{window};

  renderer.run();

  return 0;
}


