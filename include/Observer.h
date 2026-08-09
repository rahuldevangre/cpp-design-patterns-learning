#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace Observer
{

    // Observer
    // Intent: Define a one-to-many dependency so that when one object changes state,
    // all its dependents are notified and updated automatically.
    // When to use: when changes to one object should automatically propagate to others.

    // Observer declares the update interface for receiving subject changes.
    class Observer
    {
    public:
        virtual ~Observer() = default;
        virtual void update(int state) = 0;
    };

    // Subject maintains a list of observers and notifies them.
    class Subject
    {
        std::vector<Observer *> observers_;
        int state_ = 0;

    public:
        void attach(Observer *observer)
        {
            observers_.push_back(observer);
        }

        void detach(Observer *observer)
        {
            observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
        }

        void setState(int state)
        {
            state_ = state;
            for (auto *observer : observers_)
            {
                observer->update(state_);
            }
        }
    };

    class ConcreteObserverA : public Observer
    {
    public:
        void update(int state) override
        {
            std::cout << "  ObserverA: state updated to " << state << "\n";
        }
    };

    class ConcreteObserverB : public Observer
    {
    public:
        void update(int state) override
        {
            std::cout << "  ObserverB: state updated to " << state << "\n";
        }
    };

    inline void run()
    {
        std::cout << "Observer:\n";
        Subject subject;
        ConcreteObserverA a;
        ConcreteObserverB b;
        subject.attach(&a);
        subject.attach(&b);
        subject.setState(1);
        subject.setState(2);
        std::cout << '\n';
    }
}
