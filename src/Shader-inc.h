//
// Created by siyualbak on 19. 4. 7.
//

#ifndef GLWARPER_SHADER_INC_H
#define GLWARPER_SHADER_INC_H

#include "../include/Shader.h"

#include <fstream>
#include <sstream>
#include <string>

#include "../include/InternalGraphicLib.h"
#include "../include/ErrorHandel.h"

template <unsigned int T>
gl::Shader<T>::Shader(std::string &route)
  : BaseObject<Shader<T>>{}, mRoute{route} {
  init();
}

template <unsigned int T>
gl::Shader<T>::Shader(std::string &&route)
  : mRoute{route} {
  init();
}

template <unsigned int T>
gl::Shader<T>::~Shader() {
  glDeleteShader(BaseObject<Shader<T>>::mObjectId);
}

template <unsigned int T>
void gl::Shader<T>::compile() {
  glCompileShader(BaseObject<Shader<T>>::mObjectId);

  int result;
  int infoLogLength;

  glGetShaderiv(BaseObject<Shader<T>>::mObjectId, GL_COMPILE_STATUS, &result);
  glGetShaderiv(BaseObject<Shader<T>>::mObjectId, GL_INFO_LOG_LENGTH, &infoLogLength);

  if (infoLogLength > 0) {
    std::string errorMessage{};
    errorMessage.resize(infoLogLength + 1);

    glGetShaderInfoLog(BaseObject<Shader<T>>::mObjectId, infoLogLength, nullptr, (GLchar *) (errorMessage.data()));
    errorHandle(Error::GL, errorMessage);
  }
}

// // Todo 가져온 쉐이더 코드를 수정하면 실제 파일도 수정되게 만들기
//template <unsigned int T>
//std::string gl::Shader<T>::getShaderSource() {
//  return static_cast<std::string>(const_cast<const gl::Shader<T>&>(*this).getShaderSource());
//}

template <unsigned int T>
const std::string gl::Shader<T>::getShaderSource() const {
  std::string shaderSource;
  std::ifstream shaderStream{mRoute.c_str()};

  if (shaderStream.is_open()) {
    std::stringstream stringStream{};

    stringStream << shaderStream.rdbuf();
    shaderSource = stringStream.str();

    shaderStream.close();
  } else {
    errorHandle(Error::GL, "Can't read shader's source file");
    return nullptr;
  }

  return shaderSource;
}

template <unsigned int T>
void gl::Shader<T>::init() {
  BaseObject<Shader<T>>::mObjectId = glCreateShader(T);

  const std::string& shaderSource{getShaderSource()};
  const char *pShaderSource = shaderSource.data();
  glShaderSource(BaseObject<Shader<T>>::mObjectId, 1, &pShaderSource, nullptr);
}

#endif

