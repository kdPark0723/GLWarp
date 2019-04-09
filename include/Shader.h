//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_SHADER_H
#define GLWARPER_SHADER_H

#include <string>

namespace GL {

template <unsigned int T>
class Shader {
 public:
  inline explicit Shader(std::string& route);
  inline explicit Shader(std::string&& route);
  inline virtual ~Shader();

  inline virtual void compile();
  inline unsigned int data() const;

 protected:
  std::string m_route;
  unsigned int m_data;

  const std::string getShaderCode() const;
  // std::string getShaderCode();
  virtual void init();
};

}

#include "../src/Shader-inc.h"

#endif //GLWARPER_SHADER_H
