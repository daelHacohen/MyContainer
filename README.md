# MyContainer Project

## Description

`MyContainer` is a generic, template-based C++ container that allows dynamic insertion and removal of elements that are **comparable** (e.g., integers, doubles, strings, etc.).  
The container also supports **six custom iterators**, each providing a unique traversal pattern.

This project was developed as part of a university course on **Systems Programming 2 (C++)**, focusing on the topics of:
- Templates
- Functors
- Containers
- Iterators

---

## File Structure

| File              | Description |
|-------------------|-------------|
| `MyContainer.hpp` | Main container class and all iterator classes |
| `main.cpp`        | Demonstration of the container's functionality |
| `test.cpp`        | Unit tests using the `doctest` library |
| `doctest.h`       | Header-only testing framework |
| `Makefile`        | Build automation for compiling, testing, and Valgrind analysis |

---

## Class Overview

### `MyContainer<T>`

A dynamic container that supports:
- `add(const T&)`: Adds an element to the container.
- `remove(const T&)`: Removes all instances of a value. Throws if not found.
- `size()`: Returns the number of elements.
- Overloaded `operator<<`: Prints the container contents.

### Iterators

Each iterator class supports `begin()` and `end()` functionality and allows traversal in a specific pattern:

| Iterator         | Description |
|------------------|-------------|
| `AscendingOrder` | From smallest to largest |
| `DescendingOrder`| From largest to smallest |
| `SideCrossOrder` | Alternates: smallest, largest, next-smallest, etc. |
| `ReverseOrder`   | Reverse of insertion order |
| `Order`          | Original insertion order |
| `MiddleOutOrder` | Starts from the middle, alternates left and right |

---

## Unit Testing

All functionality is tested using the `doctest` framework in `test.cpp`.  
Tests include:
- Basic container operations
- Each iterator on normal, empty, and single-element containers
- Tests for different types: `int`, `double`, `std::string`, `char`

To run tests:

```bash
make test
./test
```

---

## Usage & Build Instructions

### Build Main Program

```bash
make Main
./main
```

### Run Unit Tests

```bash
make test
./test
```

### Check for Memory Leaks with Valgrind

```bash
make valgrind
```

> This runs Valgrind on both `main` and `test` executables.

### Clean Build Artifacts

```bash
make clean
```

---

## Notes

- Namespace used: `dael_containers`
- Exception-safe: `remove()` throws if element not found.
- All iterators implement: `operator*`, `operator++`, `operator==`, `operator!=`

---

## Author

> Developed by Dael  
> Email: `dael12345@gmail.com`

---
