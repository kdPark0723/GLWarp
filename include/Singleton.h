//
// Created by siyualbak on 19. 4. 8.
//

#ifndef GLWARPER_SINGLETON_H
#define GLWARPER_SINGLETON_H

namespace gl {

// Todo 인터페이스 개선, 싱글톤 객체 삭제 만들기, 멀티 쓰레드 지원
template <typename Derived>
class Singleton {
 public:
  inline static Derived& getInstance() {
    static Derived instance{};

    return instance;
  }

  Singleton() = default;
  virtual ~Singleton() = default;
};

}

#endif //GLWARPER_SINGLETON_H
