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

---

## 2026-03-25
**Work:** Tokenizer implementation
- Implemented `tokenize()` to scan input into tokens (integers, operators, parentheses).
- Skips whitespace and groups multi-digit integers.
- Emits unknown characters as tokens so validators can reject later.
- Added optional `DEBUG_TOKENS` output in `main()` (disabled by default).

**Testing:**
- `3 + 4 * 2`
- `(3 + 4) * 2`
- `3 4 2 * +`

**Commit:** 82a3277 (Day 2: implement tokenizer + DEBUG_TOKENS

---

## 2026-03-26
**Work:** Postfix validator
- Implemented `isValidPostfix()` using stack-depth simulation.
- Rejects parentheses and invalid tokens.
- Valid postfix must end with stack depth 1.

**Testing:**
- Valid: `3 4 +`, `3 4 2 * +`
- Invalid: `3 + 4`, `3 4 + +`

**Commit:** 
