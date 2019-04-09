//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_ERRORHANDEL_H
#define GLWARPER_ERRORHANDEL_H

#include <string>

namespace gl {

enum Error {
  GLFW,
  GL3W,
  GL,
};

// Todo 인터페이스 개선!!
inline void errorHandle(int error, const std::string &description);

}

#include "../src/ErrorHandel-inc.h"

#endif //GLWARPER_ERRORHANDEL_H
