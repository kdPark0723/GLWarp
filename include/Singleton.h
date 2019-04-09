//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_SINGLETON_H
#define GLWARPER_SINGLETON_H

namespace gl {

template <typename Derived>
class Singleton {
 public:
  inline static Derived& getInstance() {
    static Derived instance{};

    return instance;
  }

 protected:
  Singleton() = default;
  virtual ~Singleton() = default;
};

}

#endif //GLWARPER_SINGLETON_H
