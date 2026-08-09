# C++ Design Patterns Collection

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

**Repository:** https://github.com/rahuldevangre/cpp-design-patterns-learning

A learning-focused C++ repository demonstrating common design patterns.
All examples are implemented in header-only form to make the code easy to read
and reuse for study.

## Project description

This repo contains self-contained, header-only implementations of ten classic
design patterns. Each pattern includes a short theoretical explanation at the
top of the header and a runnable example in `src/main.cpp`.

## Patterns included

These examples are implemented as individual header-only patterns in `include/`.

- Factory Method
- Composite
- Decorator
- Facade
- Chain of Responsibility
- Command
- Observer
- State
- Strategy
- Template Method

## Project structure

- `include/` — header-only pattern examples with theory and implementation
- `src/main.cpp` — single executable that runs all pattern demos
- `CMakeLists.txt` — build configuration for the example executable

## Why header-only?

This repo is designed for learning:
- each pattern is self-contained in its own header
- inline implementations make it easy to follow the design
- no separate `.cpp` implementation files are required for the examples

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Run

```bash
./design_patterns_examples
```

## Contributing

Feel free to add more patterns or improve the existing examples with
additional comments and variations.

## License

MIT License
