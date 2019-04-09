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
GL::Shader<T>::Shader(std::string& route)
  : m_route{route}, m_data{} {
  init();
}

template <unsigned int T>
GL::Shader<T>::Shader(std::string&& route)
  : m_route{route}, m_data{} {
  init();
}

template <unsigned int T>
GL::Shader<T>::~Shader() {
  glDeleteShader(m_data);
}

template <unsigned int T>
void GL::Shader<T>::compile() {
  glCompileShader(m_data);

  int result;
  int info_log_length;

  glGetShaderiv(m_data, GL_COMPILE_STATUS, &result);
  glGetShaderiv(m_data, GL_INFO_LOG_LENGTH, &info_log_length);
  if (info_log_length > 0) {
    std::string error_message{};
    error_message.resize(static_cast<unsigned long>(info_log_length + 1));

    glGetShaderInfoLog(m_data, info_log_length, nullptr, (GLchar*)(error_message.data()));
    errorCallback(0, error_message.data());
  }
}

template <unsigned int T>
unsigned int GL::Shader<T>::data() const {
  if (!m_data) {
    errorCallback(0, "Shader should be compiled before to get data.");
    return 0;
  }
  return m_data;
}

// // Todo 가져온 쉐이더 코드를 수정하면 실제 파일도 수정되게 만들기
// template <unsigned int T>
// std::string GL::Shader<T>::getShaderCode() {
//   return static_cast<std::string>(const_cast<const GL::Shader<T>&>(*this).getShaderCode());
// }

template <unsigned int T>
const std::string GL::Shader<T>::getShaderCode() const {
  std::string shader_code;
  std::ifstream shader_stream{m_route.c_str()};

  if (shader_stream.is_open()) {
    std::stringstream sstr;

    sstr << shader_stream.rdbuf();
    shader_code = sstr.str();

    shader_stream.close();
  } else {
    errorCallback(0, "Can't read shader's source file");
    return nullptr;
  }

  return shader_code;
}

template <unsigned int T>
void GL::Shader<T>::init() {
  m_data = glCreateShader(T);

  const std::string shader_code{std::move(getShaderCode())};
  const char* shader_code_c = shader_code.data();
  glShaderSource(m_data, 1, &shader_code_c, nullptr);
}

#endif

