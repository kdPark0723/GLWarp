//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_ERRORHANDEL_INC_H
#define GLWARPER_ERRORHANDEL_INC_H

#include "../include/ErrorHandel.h"

#include <stdexcept>
#include <string>

void GL::errorCallback(int error, const char* description) {
  std::string error_description{"GL Error: "};
  error_description.append(description);

  throw std::runtime_error{error_description};
}

#endif