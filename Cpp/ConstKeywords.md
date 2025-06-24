# Const keywords

🧠 C++ Cheatsheet: `constexpr` vs `const` vs `constinit`

## 📌 Comparison Table

| Feature                               | `const`               | `constexpr`                      | `constinit`                       |
|---------------------------------------|------------------------|----------------------------------|------------------------------------|
| Mutability                            | ❌ No                  | ❌ No                           | ✅ Yes                             |
| Compile-time evaluation               | ❌ Not guaranteed      | ✅ Always                        | ✅ Initialization only             |
| Where it can be used                  | Anywhere               | Anywhere (with restrictions)     | Global or `static` variables only  |
| Usable in `static_assert`             | ❌ No                  | ✅ Yes                          | ❌ No                              |
| Avoids runtime initialization         | ❌ No                  | ✅ Yes                          | ✅ Yes                             |
| Usable in templates                   | ❌ No                  | ✅ Yes                          | ❌ No                              |

---

## 🟦 `const`

- Declares an **immutable value**
- May be initialized at runtime
- Not necessarily known at compile time

```cpp
const int a = runtime_func(); // OK
a = 10;                       // ❌ Error: const
```

---

## 🟩 `constexpr`

- Value is **guaranteed** to be evaluated at compile time
- Variable is **immutable**
- Can be used in `static_assert`, templates, array sizes, etc.

```cpp
constexpr int square(int x) { return x * x; }

constexpr int a = square(5);
static_assert(a == 25);

int arr[a]; // OK
```

---

## 🟨 `constinit`

- Declares that a variable will be **initialized at compile time**
- Value can be **mutable**
- Only valid for global or `static` variables
- Prevents the **"static initialization order fiasco"**

```cpp
constinit int counter = 0;
counter = 42;  // OK — not const

constinit int invalid; // ❌ Error: must be initialized

// ❌ Invalid inside functions:
void foo() {
    constinit int local = 1; // Error
}
```

---

## 💣 The "static initialization order fiasco"

```cpp
// A.cpp
Logger loggerA("A");

// B.cpp
extern Logger loggerA;
Logger loggerB("B", &loggerA); // might use an uninitialized loggerA
```

🔐 Solution:
- Use `constinit`
- Or use a function-local `static` variable:

```cpp
Logger& getLogger() {
    static Logger instance("A"); // lazy and safe
    return instance;
}
```

---

## ✅ When to use what?

| You need...                                            | Use           |
|--------------------------------------------------------|----------------|
| A constant value known to the compiler                 | `constexpr`    |
| An immutable value, not necessarily compile-time       | `const`        |
| A mutable value initialized at compile-time            | `constinit`    |
