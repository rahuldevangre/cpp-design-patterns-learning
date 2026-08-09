#include "Factory.h"
#include "Composite.h"
#include "Decorator.h"
#include "Facade.h"
#include "ChainOfResponsibility.h"
#include "Command.h"
#include "Observer.h"
#include "State.h"
#include "Strategy.h"
#include "TemplateMethod.h"

int main() {
    Factory::run();
    Composite::run();
    Decorator::run();
    Facade::run();
    Chain::run();
    Command::run();
    Observer::run();
    State::run();
    Strategy::run();
    TemplateMethod::run();
    return 0;
}
