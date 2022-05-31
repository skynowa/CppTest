# IPC & MT - Inter Process / Thread Communication

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

- [ ] Suspisiuos wakeup
- [ ] notify one/all

## Debug

- [ ] Deadlock - resolve methods
- [ ] Debug/fix methods

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
