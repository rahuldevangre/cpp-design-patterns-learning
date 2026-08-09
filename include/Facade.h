#pragma once

#include <iostream>
#include <string>

namespace Facade
{

    // Facade
    // Intent: Provide a unified interface to a set of interfaces in a subsystem.
    // Facade defines a higher-level interface that makes the subsystem easier to use.
    // When to use: when you want to simplify a complex subsystem for a client.

    class SubsystemA
    {
    public:
        std::string operationA() const
        {
            return "SubsystemA operation";
        }
    };

    class SubsystemB
    {
    public:
        std::string operationB() const
        {
            return "SubsystemB operation";
        }
    };

    class SubsystemC
    {
    public:
        std::string operationC() const
        {
            return "SubsystemC operation";
        }
    };

    // SystemFacade provides a simple interface to a set of subsystems.
    class SystemFacade
    {
    public:
        std::string performFullOperation() const
        {
            SubsystemA a;
            SubsystemB b;
            SubsystemC c;
            return a.operationA() + " + " + b.operationB() + " + " + c.operationC();
        }
    };

    inline void run()
    {
        std::cout << "Facade:\n";
        SystemFacade facade;
        std::cout << "  " << facade.performFullOperation() << "\n\n";
    }
}
