#pragma once

#include <iostream>
#include <memory>

namespace State
{

    class Context;
    class ConcreteStateB;

    // State
    // Intent: Allow an object to alter its behavior when its internal state changes.
    // The object will appear to change its class.
    // When to use: when an object must change behavior at runtime depending on its state.

    // State declares an interface for handling a request.
    class State
    {
    public:
        virtual ~State() = default;
        virtual void handle(Context &context) = 0;
    };

    // Context keeps a reference to a State object.
    class Context
    {
        std::unique_ptr<State> state_;

    public:
        explicit Context(std::unique_ptr<State> state) : state_(std::move(state)) {}

        void setState(std::unique_ptr<State> state)
        {
            state_ = std::move(state);
        }

        void request()
        {
            state_->handle(*this);
        }
    };

    class ConcreteStateA : public State
    {
    public:
        void handle(Context &context) override
        {
            std::cout << "  StateA handling request and switching to StateB\n";
            context.setState(std::make_unique<ConcreteStateB>());
        }
    };

    class ConcreteStateB : public State
    {
    public:
        void handle(Context &context) override
        {
            std::cout << "  StateB handling request and switching to StateA\n";
            context.setState(std::make_unique<ConcreteStateA>());
        }
    };

    inline void run()
    {
        std::cout << "State:\n";
        Context context(std::make_unique<ConcreteStateA>());
        context.request();
        context.request();
        context.request();
        std::cout << '\n';
    }
}
