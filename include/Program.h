//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_PROGRAM_H
#define GLWARPER_PROGRAM_H

#include "Shader.h"

namespace gl {

class Program {
 public:
  inline Program();
  inline ~Program();

  template <unsigned int type>
  inline Program& attach(Shader<type>& shader);
  inline void link();
  inline void use();

 private:
  unsigned int mData;
};

}

#include "../src/Program-inc.h"

#endif //GLWARPER_PROGRAM_H
