//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_SHADER_H
#define GLWARPER_SHADER_H

#include <string>

#include "BaseObejct.h"

namespace gl {

template <unsigned int T>
class Shader : public BaseObject<Shader<T>> {
 public:

  enum {
    Type = T
  };

  inline explicit Shader(std::string& route);
  inline explicit Shader(std::string&& route);
  inline virtual ~Shader();

  inline virtual void compile();
  inline bool isCompiled();

 protected:
  std::string mRoute;
  bool mIsCompiled;

  const std::string getShaderSource() const;
  // std::string getShaderSource();
  virtual void init();
};

}

#include "../src/Shader-inc.h"

#endif //GLWARPER_SHADER_H
