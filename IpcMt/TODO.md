# IPC & MT - Inter Process / Thread Communication

## Intellias

- [ ] [Multithreading Fundamentals](https://www.youtube.com/watch?v=gOvrMLEsPhQ)
- [ ] [Examples] https://github.com/vnikolai/cpp_examples/tree/main/multithreading

## Java

- [ ] [50+ Java Threads Interview Questions And Answers](https://javaconceptoftheday.com/java-threads-interview-questions-and-answers/)

## POSIX

- [ ] POSIX primitives
- [ ] pthread_spin_*

## STD

- [ ] C++ standart sync primitives
- [ ] std::future

## Thread

- [ ] Что такое поток? Создание потока. Параллельное выполнение кода.
- [ ] Потоки с параметрами. Передача параметров в поток.
- [ ] Получение результата работы функции из потока по ссылке
- [ ] Лямбда выражения и возврат результата выполнения потока
- [ ] Потоки и методы класса

## Mutex

- [ ] Что такое mutex и как его использовать. Синхронизация потоков.
- [ ] Recursive_mutex. Рекурсивный мьютекс
- [ ] lock_guard mutex
- [ ] std::unique_lock mutex

## Condition variable

- [ ] Points, pitfalls
- [ ] Suspisiuos wakeup
- [ ] notify one/all

## Debug

- [ ] [Топ 20 ошибок при работе с многопоточностью на С++ и способы избежать их](https://habr.com/ru/post/443406/)
- [ ] Deadlock - resolve methods
- [ ] Debug/fix methods

## Etc

- [ ] race-condition / fix
- [ ] мьютексом vs семафором
- [ ] atomic operation
- [ ] Concurrency - что такое

## IPC Methods

- Pipe
- FIFO
- Socket
- ShareMemory + Semaphores
- Memory mapped file
- Msg queue (Unix)
- Signal
- File

boost.interprocess

You should be able to combine Boost.ASIO (for async sockets I/O)
with Boost.Signals (for Observer pattern) or Boost.Signals2 (threadsafe version of Boost.Signals)
to achieve what you want.

## Video

- [ ] [006. Многопоточность в С++ – Максим Бусел](https://www.youtube.com/watch?v=-TuJP8pUBW0)

## Junior

- Что вам известно о многопоточности?
- Что общего и различного в процессах и потоках?
- Как синхронизировать передачи информации между потоками?
- Какая разница между мьютексом и семафором?
- Что такое deadlock?
- Является ли С++ thread-safe?
- Что такое race-condition?
- Как избежать состояния гонки?
- Что такое атомарная операция?
- Как работать с std::mutex?

## Middle

- Является ли С++ thread-safe?
- В чем разница между многопоточностью и асинхронностью?
- Что такое многопоточность? Какую функциональность предоставляет С++ для разработки многопоточных
  приложений? Какие основные проблемы многопоточных приложений?
- Как передать информацию между несколькими процессами?
- Как синхронизировать между собой несколько процессов?
- Какие есть особенности работы с shared memory?
- Как работает spinlock?
- Какие вы знаете особенности использования recursive mutex?
- Расскажите о read-write mutex.
- Что такое race-condition? Взаимная блокировка? Что такое критическая секция?
- Как избежать состояния гонки?
- Чем отличается мьютекс от семафора?
- Какие примитивы синхронизации реализованы в C++? Преимущества lock_guard?
- Что случится, если exception выйдет за пределы потока? Какие инструменты есть для безопасной
  асинхронности в С++?
- Чем отличается std::launch::async от std::launch::deferred?
- Что такое атомарная операция? std::atomic?
- Как работать с std::conditional_variable?
- Как создать поток с помощью std::thread?
- На сколько потоков лучше разбить задачу? От чего это зависит?
- Как работать с std::async?
- Thread-safe гарантии контейнеров в С++? В чем недостаток интерфейса front() + pop_front()?

## Senior

- Расскажите о построении API, рассчитанных на многопоточное использование.
- В чем разница между kernel-level и user-level потоками?
- Что такое coroutine?
- Что делает спецификатор thread_local?
- Как реализовать синхронизацию в задаче producer-consumer?
- Як синхронизироваться между различными процессами?
