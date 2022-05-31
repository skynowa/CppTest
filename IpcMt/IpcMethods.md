# IpcMethods

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
