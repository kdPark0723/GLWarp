//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_ERRORHANDEL_H
#define GLWARPER_ERRORHANDEL_H

namespace GL {

// Todo 인터페이스 개선!!
inline void errorCallback(int error, const char* description);

}

#include "../src/ErrorHandel-inc.h"

#endif //GLWARPER_ERRORHANDEL_H
