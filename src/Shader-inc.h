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
  : mRoute{route}, mData{} {
  init();
}

template <unsigned int T>
gl::Shader<T>::Shader(std::string &&route)
  : mRoute{route}, mData{} {
  init();
}

template <unsigned int T>
gl::Shader<T>::~Shader() {
  glDeleteShader(mData);
}

template <unsigned int T>
void gl::Shader<T>::compile() {
  glCompileShader(mData);

  int result;
  int info_log_length;

  glGetShaderiv(mData, GL_COMPILE_STATUS, &result);
  glGetShaderiv(mData, GL_INFO_LOG_LENGTH, &info_log_length);
  if (info_log_length > 0) {
    std::string error_message{};
    error_message.resize(info_log_length + 1);

    glGetShaderInfoLog(mData, info_log_length, nullptr, (GLchar *) (error_message.data()));
    errorHandle(Error::GL, error_message);
  }
}

template <unsigned int T>
unsigned int gl::Shader<T>::data() const {
  if (!mData) {
    errorHandle(Error::GL, "Shader should be compiled before to get data.");
    return 0;
  }
  return mData;
}

// // Todo 가져온 쉐이더 코드를 수정하면 실제 파일도 수정되게 만들기
// template <unsigned int T>
// std::string gl::Shader<T>::getShaderCode() {
//   return static_cast<std::string>(const_cast<const gl::Shader<T>&>(*this).getShaderCode());
// }

template <unsigned int T>
const std::string gl::Shader<T>::getShaderCode() const {
  std::string shaderCode;
  std::ifstream shaderStream{mRoute.c_str()};

  if (shaderStream.is_open()) {
    std::stringstream sstr;

    sstr << shaderStream.rdbuf();
    shaderCode = sstr.str();

    shaderStream.close();
  } else {
    errorHandle(Error::GL, "Can't read shader's source file");
    return nullptr;
  }

  return shaderCode;
}

template <unsigned int T>
void gl::Shader<T>::init() {
  mData = glCreateShader(T);

  const std::string shaderCode{std::move(getShaderCode())};
  const char *pShaderCode = shaderCode.data();
  glShaderSource(mData, 1, &pShaderCode, nullptr);
}

#endif

