//
// Created by siyualbak on 19. 4. 9.
//

#ifndef GLWARPER_VERTEX_INC_H
#define GLWARPER_VERTEX_INC_H

#include "../include/Vertex.h"

#include "../include/InternalGraphicLib.h"
#include "../include/ErrorHandel.h"

#include <iostream>

namespace gl {

template<typename T, size_t Size>
Vertex<T, Size>::Vertex()
  : mStorage{} {
}

template<typename T, size_t Size>
Vertex<T, Size>::Vertex(T &x)
  : mStorage{x} {
}
template<typename T, size_t Size>
Vertex<T, Size>::Vertex(T &x, T &y)
  : mStorage{x, y} {
}
template<typename T, size_t Size>
Vertex<T, Size>::Vertex(T &x, T &y, T &z)
  : mStorage{x, y, z} {
}
template<typename T, size_t Size>
Vertex<T, Size>::Vertex(T &x, T &y, T &z, T &w)
  : mStorage{x, y, z, w} {
}

template<typename T, size_t Size>
Vertex<T, Size>::Vertex(T &&x)
  : mStorage{x} {
}
template<typename T, size_t Size>
Vertex<T, Size>::Vertex(T &&x, T &&y)
  : mStorage{x, y} {
}
template<typename T, size_t Size>
Vertex<T, Size>::Vertex(T &&x, T &&y, T &&z)
  : mStorage{x, y, z} {
}
template<typename T, size_t Size>
Vertex<T, Size>::Vertex(T &&x, T &&y, T &&z, T &&w)
  : mStorage{x, y, z, w} {
}

template<typename T, size_t Size>
void Vertex<T, Size>::attribute(int) {
  errorHandle(Error::GL, "This vertex's format isn't defined.");
}

template<>
void Vertex<int, 4>::attribute(int index) {
  glVertexAttrib4iv(static_cast<GLuint>(index), static_cast<GLint *>(mStorage.data()));
}

template<>
void Vertex<short, 1>::attribute(int index) {
  glVertexAttrib1sv(static_cast<GLuint>(index), static_cast<GLshort *>(mStorage.data()));
}
template<>
void Vertex<short, 2>::attribute(int index) {
  glVertexAttrib2sv(static_cast<GLuint>(index), static_cast<GLshort *>(mStorage.data()));
}
template<>
void Vertex<short, 3>::attribute(int index) {
  glVertexAttrib3sv(static_cast<GLuint>(index), static_cast<GLshort *>(mStorage.data()));
}
template<>
void Vertex<short, 4>::attribute(int index) {
  glVertexAttrib4sv(static_cast<GLuint>(index), static_cast<GLshort *>(mStorage.data()));
}

template<>
void Vertex<float, 1>::attribute(int index) {
  glVertexAttrib1fv(static_cast<GLuint>(index), static_cast<GLfloat *>(mStorage.data()));
}
template<>
void Vertex<float, 2>::attribute(int index) {
  glVertexAttrib2fv(static_cast<GLuint>(index), static_cast<GLfloat *>(mStorage.data()));
}
template<>
void Vertex<float, 3>::attribute(int index) {
  glVertexAttrib3fv(static_cast<GLuint>(index), static_cast<GLfloat *>(mStorage.data()));
}
template<>
void Vertex<float, 4>::attribute(int index) {
  glVertexAttrib4fv(static_cast<GLuint>(index), static_cast<GLfloat *>(mStorage.data()));
}

template<>
void Vertex<double, 1>::attribute(int index) {
  glVertexAttrib1dv(static_cast<GLuint>(index), static_cast<GLdouble *>(mStorage.data()));
}
template<>
void Vertex<double, 2>::attribute(int index) {
  glVertexAttrib2dv(static_cast<GLuint>(index), static_cast<GLdouble *>(mStorage.data()));
}
template<>
void Vertex<double, 3>::attribute(int index) {
  glVertexAttrib3dv(static_cast<GLuint>(index), static_cast<GLdouble *>(mStorage.data()));
}
template<>
void Vertex<double, 4>::attribute(int index) {
  glVertexAttrib4dv(static_cast<GLuint>(index), static_cast<GLdouble *>(mStorage.data()));
}

}

#endif //GLWARPER_VERTEX_INC_H
