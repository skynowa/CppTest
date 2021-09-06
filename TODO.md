# TODO

## Review + Refactoring

- [ ] Книга Рефакторинг. Улучшение проекта существующего кода. Авторы - М Фаулер, К. Бек, Д. Брант (Символ) (мягк.)

## Docs

- Doxygen

## Backend

- https://dou.ua/lenta/columns/skills-outside-of-programming-languages/

## C++ modern

- https://github.com/AnthonyCalandra/modern-cpp-features
- https://github.com/NTimmons/ModernCPP_Examples

## Move

https://www.youtube.com/watch?v=oQDOqB1asNw
move - когда надо/можно/будет - performance
std::move - source

## Mask

## Smart - pointers

- pass as function param
- when and what use std::unique_ptr vs std::share_ptr, performance

## IPC & MT

- C++ standart sync primitives
- POSIX primitives
  - std::future
  - pthread_spin_*

- condition variable - Suspisiuos wakeup
- condition variable - notify one/all
- dead lock - resolve methods
- debug/fix methods

## DevOps

```shell
screen
man
telnet 127.0.0.1 12345
fgrep
```

## Dev tools

```shell
```

## Sys calls

```shell
strace [binary_path]
strace -p [pid]

ltrace -p [pid]
gda -p [pid]

# list opened descriptors
lsof -p [pid]
```

## Luxoft

- Smart pointers - 3/10, only theoretical knowledge about unique pointer.
- Move semantics - 2/10, no theoretical nor practical knowledge.
- stl containers - 7/10, good general knowledge of common containers.
- multithreading - 4/10, knows about mutexes, doesn't know what problems they cause and how to solve them.
- Linux - 4/10, no development experience for linux. Only knowledge from user POV.
- IPC - NA, no experience.
- UML - 6/10, knows about class diagram.
