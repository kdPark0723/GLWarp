#include "../include/Window.h"
#include "Renderer.h"

int main() {
  GL::Window window{"Fill Window Red", 1024, 768};
  Renderer renderer{window};

  renderer.run();

  return 0;
}


