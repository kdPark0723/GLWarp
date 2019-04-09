//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_POINT_H
#define GLWARPER_POINT_H

#include "Singleton.h"

namespace GL {

// 인터페이스 개선!!!
class Point : public DesignPatterns::Singleton<Point> {
 public:
  inline void size(float size);
};

#include "../src/Point-inc.h"

}

#endif //GLWARPER_POINT_H
