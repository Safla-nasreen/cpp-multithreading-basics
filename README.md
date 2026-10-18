# C++ Multithreading Basics

Personal learning project: five small C++ programs I wrote and ran on Linux (WSL, g++) while refreshing my multithreading skills. Each program shows one core idea, using a simple kitchen example (each thread is a cook).

## Programs

| File | Concept | What it shows |
|------|---------|---------------|
| `pthread.cpp` | `std::thread`, `join()` | Start a thread and wait for it to finish before `main` ends. |
| `cook_thread.cpp` | Passing arguments, two threads | Two threads run at the same time; the output order changes between runs. |
| `race.cpp` | Race condition | Two threads increment a shared counter 1,000,000 times each without protection. |
| `mutex.cpp` | `std::mutex`, `std::lock_guard` | The same counter, protected by a mutex. |
| `deadlock.cpp` | Deadlock and its fix | Two threads lock two mutexes; fixed by always locking in the same order. |

## Results from my runs

- **race.cpp:** expected 2,000,000, got 1,228,426, then 1,372,257, then 1,722,220. Updates were lost, and the result changed every run.
- **mutex.cpp:** 2,000,000 on every run.
- **deadlock.cpp:** with opposite lock order, the program froze. After changing both threads to lock `knife` then `board`, it finished and printed "kitchen closed".

## What I learned

- Every `std::thread` must be joined (or detached) before it goes out of scope.
- The order in which threads run is not guaranteed.
- `count++` is read, add, write, so it is not safe when two threads share it.
- `std::lock_guard` releases the mutex automatically at the end of its scope.
- Taking locks in the same order in every thread prevents deadlock.

## How to build and run

```
g++ race.cpp -o race -pthread
./race
```
