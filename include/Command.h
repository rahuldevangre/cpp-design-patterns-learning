#pragma once

#include <iostream>
#include <memory>
#include <vector>

namespace Command
{

    // Command
    // Intent: Encapsulate a request as an object, allowing parameterization of clients
    // with queues, logs, and support for undoable operations.
    // When to use: when you need to decouple requester from executor, or support
    // reversible operations and request history.

    // Command declares an interface for executing requests.
    class Command
    {
    public:
        virtual ~Command() = default;
        virtual void execute() = 0;
    };

    // Receiver knows how to perform the actual work.
    class Receiver
    {
    public:
        void actionA()
        {
            std::cout << "  Receiver: action A\n";
        }
        void actionB()
        {
            std::cout << "  Receiver: action B\n";
        }
    };

    class ConcreteCommandA : public Command
    {
        Receiver &receiver_;

    public:
        explicit ConcreteCommandA(Receiver &receiver) : receiver_(receiver) {}
        void execute() override
        {
            receiver_.actionA();
        }
    };

    class ConcreteCommandB : public Command
    {
        Receiver &receiver_;

    public:
        explicit ConcreteCommandB(Receiver &receiver) : receiver_(receiver) {}
        void execute() override
        {
            receiver_.actionB();
        }
    };

    // Invoker executes commands and can store history.
    class Invoker
    {
        std::vector<std::unique_ptr<Command>> history_;

    public:
        void executeCommand(std::unique_ptr<Command> command)
        {
            command->execute();
            history_.push_back(std::move(command));
        }
    };

    inline void run()
    {
        std::cout << "Command:\n";
        Receiver receiver;
        Invoker invoker;
        invoker.executeCommand(std::make_unique<ConcreteCommandA>(receiver));
        invoker.executeCommand(std::make_unique<ConcreteCommandB>(receiver));
        std::cout << '\n';
    }
}
