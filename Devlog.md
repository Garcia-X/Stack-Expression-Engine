# DEVLOG

## 2026-03-24
**Work:** Project setup + ArrayStack implementation
- Created new CMake C++ project in CLion.
- Added required files: `main.cpp`, `ArrayStack.h`, `DEVLOG.md`.
- Implemented `ArrayStack<T>` using `std::vector<T>` as the backing store.
- Design decision: `top()` and `pop()` throw `std::out_of_range` on empty stack.

**Testing:**
- Visual review of stack logic (push/pop/top/empty/size).
- Full build will be completed after TODO sections in `main.cpp` are implemented.

**Commit:** 3d62c2c8 (Day 1: project setup + ArrayStack implemented), 2ca003e (Day 1: remove IDE files from repo)