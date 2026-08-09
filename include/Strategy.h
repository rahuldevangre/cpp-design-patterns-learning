#pragma once

#include <iostream>
#include <memory>

namespace Strategy {

// Strategy
// Intent: Define a family of algorithms, encapsulate each one, and make them
// interchangeable. Strategy lets the algorithm vary independently from clients.
// When to use: when multiple variants of an algorithm are needed.

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual int execute(int a, int b) const = 0;
};

class AddStrategy : public Strategy {
public:
    int execute(int a, int b) const override {
        return a + b;
    }
};

class MultiplyStrategy : public Strategy {
public:
    int execute(int a, int b) const override {
        return a * b;
    }
};

class Context {
    std::unique_ptr<Strategy> strategy_;
public:
    explicit Context(std::unique_ptr<Strategy> strategy) : strategy_(std::move(strategy)) {}

    int executeStrategy(int a, int b) const {
        return strategy_->execute(a, b);
    }
};

inline void run() {
    std::cout << "Strategy:\n";
    Context addContext(std::make_unique<AddStrategy>());
    Context multiplyContext(std::make_unique<MultiplyStrategy>());
    std::cout << "  Add: " << addContext.executeStrategy(3, 4) << "\n";
    std::cout << "  Multiply: " << multiplyContext.executeStrategy(3, 4) << "\n\n";
}
}
