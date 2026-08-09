#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace Composite
{

    // Composite
    // Intent: Compose objects into tree structures to represent part-whole hierarchies.
    // Composite lets clients treat individual objects and compositions uniformly.
    // When to use: when you need to work with groups of objects and single objects
    // through the same interface.

    // Component declares the interface for leaf and composite objects.
    class Component
    {
    public:
        virtual ~Component() = default;
        virtual void operation(int indent = 0) const = 0;
    };

    // Leaf represents end objects in the composition.
    class Leaf : public Component
    {
        std::string name_;

    public:
        explicit Leaf(std::string name) : name_(std::move(name)) {}
        void operation(int indent = 0) const override
        {
            std::cout << std::string(indent, ' ') << name_ << "\n";
        }
    };

    // CompositeNode holds children and implements the tree structure.
    class CompositeNode : public Component
    {
        std::string name_;
        std::vector<std::shared_ptr<Component>> children_;

    public:
        explicit CompositeNode(std::string name) : name_(std::move(name)) {}

        void add(std::shared_ptr<Component> child)
        {
            children_.push_back(std::move(child));
        }

        void operation(int indent = 0) const override
        {
            std::cout << std::string(indent, ' ') << name_ << "\n";
            for (const auto &child : children_)
            {
                child->operation(indent + 2);
            }
        }
    };

    inline void run()
    {
        std::cout << "Composite:\n";
        auto root = std::make_shared<CompositeNode>("root");
        auto branch1 = std::make_shared<CompositeNode>("branch1");
        auto branch2 = std::make_shared<CompositeNode>("branch2");

        branch1->add(std::make_shared<Leaf>("leaf1"));
        branch1->add(std::make_shared<Leaf>("leaf2"));
        branch2->add(std::make_shared<Leaf>("leaf3"));

        root->add(branch1);
        root->add(branch2);
        root->operation();
        std::cout << '\n';
    }
}
