#include <iostream>

// Абстракція, представляє інтерфейс для низькорівневих модулів
class IDependency {
public:
    virtual void performAction() const = 0;
};

// Низькорівневий модуль, який реалізує конкретний спосіб виконання дії
class LowLevelDependency : public IDependency {
public:
    void performAction() const override {
        std::cout << "Low-level action performed" << std::endl;
    }
};

// Високорівневий модуль, який використовує абстракцію
class HighLevelModule {
private:
    IDependency& dependency;

public:
    // Залежність вводиться через конструктор
    HighLevelModule(IDependency& dep) : dependency(dep) {}

    // Метод викликає метод абстракції
    void executeAction() const {
        std::cout << "High-level module is executing an action." << std::endl;
        dependency.performAction(); // Виклик методу абстракції
    }
};

int main() {
    LowLevelDependency lowLevelDependency;
    HighLevelModule highLevelModule(lowLevelDependency); // Високорівневий модуль отримує абстракцію

    highLevelModule.executeAction(); // Виклик методу високорівневого модуля

    return 0;
}
