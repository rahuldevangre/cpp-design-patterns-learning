#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace Factory {

// Factory Method
// Intent: Define an interface for creating an object, but let subclasses decide which
// concrete class to instantiate. Factory Method lets a class defer instantiation to
// subclasses and supports open/closed behavior.
// When to use: when object creation logic should be separated from object usage,
// or when the exact type depends on runtime conditions.

// Abstract product defines the interface for objects created by the factory.
class Product {
public:
    virtual ~Product() = default;
    virtual std::string name() const = 0;
};

// Concrete products provide specialized behavior.
class ConcreteProductA : public Product {
public:
    std::string name() const override { return "ConcreteProductA"; }
};

class ConcreteProductB : public Product {
public:
    std::string name() const override { return "ConcreteProductB"; }
};

// Creator declares the factory method that returns a Product.
class Creator {
public:
    virtual ~Creator() = default;
    virtual std::unique_ptr<Product> createProduct() const = 0;
};

// Concrete creators instantiate the appropriate concrete product.
class CreatorA : public Creator {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProductA>();
    }
};

class CreatorB : public Creator {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProductB>();
    }
};

inline void run() {
    std::cout << "Factory Method:\n";
    std::vector<std::unique_ptr<Creator>> creators;
    creators.push_back(std::make_unique<CreatorA>());
    creators.push_back(std::make_unique<CreatorB>());

    for (const auto& creator : creators) {
        auto product = creator->createProduct();
        std::cout << "  Created " << product->name() << "\n";
    }
    std::cout << '\n';
}
}
