#pragma once

#include <iostream>
#include <string>

namespace TemplateMethod {

// Template Method
// Intent: Define the skeleton of an algorithm in a base class, deferring some
// steps to subclasses. Template Method lets subclasses redefine certain steps
// without changing the algorithm's structure.
// When to use: when multiple variants of an algorithm share common structure.

class AbstractClass {
public:
    virtual ~AbstractClass() = default;

    void templateMethod() const {
        baseOperation1();
        requiredOperation();
        baseOperation2();
    }

protected:
    void baseOperation1() const {
        std::cout << "  AbstractClass: baseOperation1\n";
    }

    void baseOperation2() const {
        std::cout << "  AbstractClass: baseOperation2\n";
    }

    virtual void requiredOperation() const = 0;
};

class ConcreteClass1 : public AbstractClass {
protected:
    void requiredOperation() const override {
        std::cout << "  ConcreteClass1: requiredOperation\n";
    }
};

class ConcreteClass2 : public AbstractClass {
protected:
    void requiredOperation() const override {
        std::cout << "  ConcreteClass2: requiredOperation\n";
    }
};

inline void run() {
    std::cout << "Template Method:\n";
    ConcreteClass1 c1;
    ConcreteClass2 c2;
    c1.templateMethod();
    c2.templateMethod();
    std::cout << '\n';
}
}
