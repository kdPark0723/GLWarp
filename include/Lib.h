//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_INTERNALGRAPHICLIB_H
#define GLWARPER_INTERNALGRAPHICLIB_H

#include <GL/gl3w.h>

namespace gl {

template<typename Integer>
constexpr GLenum getGLenum(Integer value) {
  return static_cast<GLenum>(value);
}

template<typename Integer>
constexpr GLshort getGLshort(Integer value) {
  return static_cast<GLshort>(value);
}

template<typename Integer>
constexpr GLint getGLint(Integer value) {
  return static_cast<GLint>(value);
}

template<typename Integer>
constexpr GLuint getGLuint(Integer value) {
  return static_cast<GLuint>(value);
}

template<typename FloatingPoint>
constexpr GLfloat getGLfloat(FloatingPoint value) {
  return static_cast<GLfloat>(value);
}

template<typename FloatingPoint>
constexpr GLdouble getGLdouble(FloatingPoint value) {
  return static_cast<GLdouble>(value);
}

}

#endif //GLWARPER_INTERNALGRAPHICLIB_H
