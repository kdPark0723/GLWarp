//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_ERRORHANDEL_INC_H
#define GLWARPER_ERRORHANDEL_INC_H

#include "../include/ErrorHandel.h"

#include <stdexcept>
#include <string>

void gl::errorHandle(int error, const std::string &description) {
  std::string errorDescription{"Error["};
  switch (error) {
    case Error::GL:errorDescription.append("GL");
      break;
    case Error::GL3W:errorDescription.append("GL3W");
      break;
    case Error::GLFW:errorDescription.append("GLFW");
      break;
    default:errorDescription.append("Undefined");
      break;
  }
  errorDescription.append("]: ");
  errorDescription.append(description);

  throw std::runtime_error{errorDescription};
}

#endif