#include "patterns/Factory.h"
#include "patterns/Composite.h"
#include "patterns/Decorator.h"
#include "patterns/Facade.h"
#include "patterns/ChainOfResponsibility.h"
#include "patterns/Command.h"
#include "patterns/Observer.h"
#include "patterns/State.h"
#include "patterns/Strategy.h"
#include "patterns/TemplateMethod.h"

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
