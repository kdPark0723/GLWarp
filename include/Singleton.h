//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_SINGLETON_H
#define GLWARPER_SINGLETON_H

namespace DesignPatterns {

template <typename T>
class Singleton {
 public:
  inline static T& getInstance() {
    static T instance{};

    return instance;
  }

 protected:
  Singleton() = default;
  virtual ~Singleton() = default;
};

}

#endif //GLWARPER_SINGLETON_H
