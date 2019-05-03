//
// Created by siyualbak on 19. 5. 3.
//

#ifndef GLWARPER_ERROR_H
#define GLWARPER_ERROR_H

namespace gl {
namespace error {

void checkGlError();

namespace internal {

void glfwErrorHandle(int error, const char *description);

}

}
}

#ifdef GL_DEBUG
#define GLWARPER_CHECK_GL_ERROR() gl::error::checkGlError();
#else
#define GLWARPER_CHECK_GL_ERROR()
#endif

#endif //GLWARPER_ERROR_H
