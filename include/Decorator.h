#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace Decorator
{

    // Decorator
    // Intent: Attach additional responsibilities to an object dynamically.
    // Decorator provides a flexible alternative to subclassing for extending behavior.
    // When to use: when you want to add features to individual objects at runtime.

    // The component interface defines operations for the concrete component and decorators.
    class VisualComponent
    {
    public:
        virtual ~VisualComponent() = default;
        virtual std::string draw() const = 0;
    };

    // A simple concrete component.
    class TextView : public VisualComponent
    {
    public:
        std::string draw() const override
        {
            return "TextView";
        }
    };

    // Base decorator stores a reference to a component.
    class DecoratorBase : public VisualComponent
    {
    protected:
        std::shared_ptr<VisualComponent> m_component;

    public:
        explicit DecoratorBase(std::shared_ptr<VisualComponent> component)
            : m_component(std::move(component)) {}
    };

    // Concrete decorators add responsibilities dynamically.
    class BorderDecorator : public DecoratorBase
    {
    public:
        explicit BorderDecorator(std::shared_ptr<VisualComponent> component)
            : DecoratorBase(std::move(component)) {}

        std::string draw() const override
        {
            return m_component->draw() + " + border";
        }
    };

    class ScrollDecorator : public DecoratorBase
    {
    public:
        explicit ScrollDecorator(std::shared_ptr<VisualComponent> component)
            : DecoratorBase(std::move(component)) {}

        std::string draw() const override
        {
            return m_component->draw() + " + scroll";
        }
    };

    inline void run()
    {
        std::cout << "Decorator:\n";
        auto widget = std::make_shared<TextView>();
        auto decorated = std::make_shared<ScrollDecorator>(
            std::make_shared<BorderDecorator>(widget));
        std::cout << "  " << decorated->draw() << "\n\n";
    }
}
