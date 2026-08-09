# C++ Design Patterns Collection

A learning-focused C++ repository demonstrating common design patterns.
All examples are implemented in header-only form to make the code easy to read
and reuse for study.

## Patterns included

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

- `include/patterns/` — header-only pattern examples with theory and implementation
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
