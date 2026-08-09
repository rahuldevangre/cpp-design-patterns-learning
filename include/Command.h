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
        Receiver &m_receiver;

    public:
        explicit ConcreteCommandA(Receiver &receiver) : m_receiver(receiver) {}
        void execute() override
        {
            m_receiver.actionA();
        }
    };

    class ConcreteCommandB : public Command
    {
        Receiver &m_receiver;

    public:
        explicit ConcreteCommandB(Receiver &receiver) : m_receiver(receiver) {}
        void execute() override
        {
            m_receiver.actionB();
        }
    };

    // Invoker executes commands and can store history.
    class Invoker
    {
        std::vector<std::unique_ptr<Command>> m_history;

    public:
        void executeCommand(std::unique_ptr<Command> command)
        {
            command->execute();
            m_history.push_back(std::move(command));
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
