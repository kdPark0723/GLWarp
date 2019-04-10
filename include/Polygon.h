//
// Created by siyualbak on 19. 4. 10.
//

#ifndef GLWARPER_POLYGON_H
#define GLWARPER_POLYGON_H

namespace gl {

class Polygon {
 public:
  inline void mode(unsigned int face, unsigned int mode);
  inline void offset(float factor, float units);
};

#include "../src/Polygon-inc.h"

}

#endif //GLWARPER_POLYGON_H
