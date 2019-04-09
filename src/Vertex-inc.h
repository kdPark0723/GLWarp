//
// Created by siyualbak on 19. 4. 9.
//

#ifndef GLWARPER_VERTEX_INC_H
#define GLWARPER_VERTEX_INC_H

#include "../include/Vertex.h"

#include "../include/InternalGraphicLib.h"
#include "../include/ErrorHandel.h"

template<typename T, size_t Size>
void gl::Vertex<T, Size>::attribute(int) {
  errorHandle(Error::GL, "This vertex's format isn't defined.");
}

template<>
struct gl::Vertex<int, 4> {
  int mVertex[4];

  inline void attribute(int index) {
    glVertexAttrib4iv(static_cast<GLuint>(index), static_cast<GLint *>(mVertex));
  }
};

template<>
struct gl::Vertex<short, 1> {
  short mVertex[1];

  inline void attribute(int index) {
    glVertexAttrib1sv(static_cast<GLuint>(index), static_cast<GLshort *>(mVertex));
  }
};
template<>
struct gl::Vertex<short, 2> {
  short mVertex[2];

  inline void attribute(int index) {
    glVertexAttrib2sv(static_cast<GLuint>(index), static_cast<GLshort *>(mVertex));
  }
};
template<>
struct gl::Vertex<short, 3> {
  short mVertex[3];

  inline void attribute(int index) {
    glVertexAttrib3sv(static_cast<GLuint>(index), static_cast<GLshort *>(mVertex));
  }
};
template<>
struct gl::Vertex<short, 4> {
  short mVertex[4];

  inline void attribute(int index) {
    glVertexAttrib4sv(static_cast<GLuint>(index), static_cast<GLshort *>(mVertex));
  }
};

template<>
struct gl::Vertex<double, 1> {
  double mVertex[1];

  inline void attribute(int index) {
    glVertexAttrib1dv(static_cast<GLuint>(index), static_cast<GLdouble *>(mVertex));
  }
};
template<>
struct gl::Vertex<double, 2> {
  double mVertex[2];

  inline void attribute(int index) {
    glVertexAttrib2dv(static_cast<GLuint>(index), static_cast<GLdouble *>(mVertex));
  }
};
template<>
struct gl::Vertex<double, 3> {
  double mVertex[3];

  inline void attribute(int index) {
    glVertexAttrib3dv(static_cast<GLuint>(index), static_cast<GLdouble *>(mVertex));
  }
};
template<>
struct gl::Vertex<double, 4> {
  double mVertex[4];

  inline void attribute(int index) {
    glVertexAttrib4dv(static_cast<GLuint>(index), static_cast<GLdouble *>(mVertex));
  }
};

template<>
struct gl::Vertex<float, 1> {
  float mVertex[1];

  inline void attribute(int index) {
    glVertexAttrib1fv(static_cast<GLuint>(index), static_cast<GLfloat *>(mVertex));
  }
};
template<>
struct gl::Vertex<float, 2> {
  float mVertex[2];

  inline void attribute(int index) {
    glVertexAttrib2fv(static_cast<GLuint>(index), static_cast<GLfloat *>(mVertex));
  }
};
template<>
struct gl::Vertex<float, 3> {
  float mVertex[3];

  inline void attribute(int index) {
    glVertexAttrib3fv(static_cast<GLuint>(index), static_cast<GLfloat *>(mVertex));
  }
};
template<>
struct gl::Vertex<float, 4> {
  float mVertex[4];

  inline void attribute(int index) {
    glVertexAttrib4fv(static_cast<GLuint>(index), static_cast<GLfloat *>(mVertex));
  }
};

#endif //GLWARPER_VERTEX_INC_H
