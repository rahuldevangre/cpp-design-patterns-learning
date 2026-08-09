#pragma once

#include <iostream>
#include <memory>

namespace Chain
{

    // Chain of Responsibility
    // Intent: Avoid coupling the sender of a request to its receiver by giving more than
    // one object a chance to handle the request. Chain several handlers and pass the
    // request along the chain until one handles it.
    // When to use: when multiple objects can handle a request and the handler isn't known
    // in advance.

    // Handler declares the interface for processing requests and chaining.
    class Handler
    {
    protected:
        std::shared_ptr<Handler> next_;

    public:
        virtual ~Handler() = default;
        void setNext(std::shared_ptr<Handler> next)
        {
            next_ = std::move(next);
        }
        virtual void handle(int request) const
        {
            if (next_)
            {
                next_->handle(request);
            }
        }
    };

    class LowHandler : public Handler
    {
    public:
        void handle(int request) const override
        {
            if (request < 10)
            {
                std::cout << "  LowHandler handled " << request << "\n";
            }
            else
            {
                Handler::handle(request);
            }
        }
    };

    class MidHandler : public Handler
    {
    public:
        void handle(int request) const override
        {
            if (request < 20)
            {
                std::cout << "  MidHandler handled " << request << "\n";
            }
            else
            {
                Handler::handle(request);
            }
        }
    };

    class HighHandler : public Handler
    {
    public:
        void handle(int request) const override
        {
            if (request < 30)
            {
                std::cout << "  HighHandler handled " << request << "\n";
            }
            else
            {
                std::cout << "  Request " << request << " was not handled\n";
            }
        }
    };

    inline void run()
    {
        std::cout << "Chain of Responsibility:\n";
        auto low = std::make_shared<LowHandler>();
        auto mid = std::make_shared<MidHandler>();
        auto high = std::make_shared<HighHandler>();
        low->setNext(mid);
        mid->setNext(high);

        for (int request : {5, 14, 25, 35})
        {
            low->handle(request);
        }
        std::cout << '\n';
    }
}
