# When to use pointers, references and values

## Variables (including member variables)

- Prefer `const`.
- Prefer stack allocations (i.e. values rather than pointers or references).
- When heap allocation is necessary (e.g for polymorphism), prefer smart
  pointers to automatically handle lifespan and ownership.

    - Use `std::unique_ptr` for objects that should live until the end of scope.
    - Use `std::shared_ptr` for reference counting.
    - Use `std::weak_ptr` to safely access potentially deleted objects managed by
      `std::shared_ptr` and to avoid circular dependencies.

- When raw pointers are necessary (e.g. to simply handle memory addresses, when
  ownership is irrelevant or when a legacy ABI requires it):

    - Use `gsl::not_null` to allow the assumption that a pointer is never null.
    - Use `gsl::owner` to make ownership explicit.
    - Use `std::observer_ptr` to make non-ownership explicit.
    - Use `gsl::span` to pass arrays along with their sizes.

## Parameters

- Prefer `const`.
- For primitive types, prefer values.
- For non-primitive types, prefer const references.
- For out-parameters, prefer non-const references.
- When handling memory addresses and not ownership, prefer raw pointers.
- To transfer ownership, use smart pointers.

## Return values

- Prefer values.
- For assignment operators, return by non-const reference.
- When handling memory addresses and not ownership, prefer raw pointers.
- To transfer ownership, use smart pointers.

## FAQ

- [-] https://www.cppstories.com/2013/02/smart-pointers-gotchas/
