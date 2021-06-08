# STL Sort algos [todo]

## std::list::sort

- is guaranteed to be stable
  Notes: Stable: the relative order of the equivalent elements is preserved. If an exception is thrown the order of the elements in the list is indeterminate.

## std::sort

- Equivalent elements are not guaranteed to keep their original relative order

## std::stable_sort

- like sort, but preserves the relative order of the elements with equivalent values
- is for std::vector and other generic containers

## std::partial_sort

## std::partial_sort_copy

## std::sort_heap

## std::map

- sorted
- slower than std::unordered_map
- allow the direct iteration on subsets based on their order

## std::unordered_map

- not sorted
- faster than std::map
- less efficient for range iteration

O(n²) - если алгоритм обрабатывает входные данные размером n за время cn² (где c — константа),
    то говорят, что временная сложность такого алгоритма O(n²).
