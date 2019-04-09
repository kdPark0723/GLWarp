#include <iostream>

#include "../include/Window.h"
#include "Renderer.h"

int main() {
  try {
    gl::Window window{"Draw dot", 1024, 768};
    Renderer renderer{window};

    renderer.run();
  } catch (std::exception& error) {
    std::cerr << error.what() << std::endl;

    std::cin.ignore();
    std::cin.get();
    return 0;
  }
  

  return 0;
}


