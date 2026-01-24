#include <iostream>
#include <memory>

class IKeyboard {
public:
    virtual ~IKeyboard() = default;
    virtual void type() const = 0;
};

class IMonitor {
public:
    virtual ~IMonitor() = default;
    virtual void display(const std::string& text) const = 0;
};

class MechanicalKeyboard : public IKeyboard {
public:
    void type() const override { std::cout << "기계식 키보드 입력\n"; }
};

class LEDMonitor : public IMonitor {
public:
    void display(const std::string& text) const override {
        std::cout << "LED 모니터 출력: " << text << '\n';
    }
};

class Computer {
    std::unique_ptr<IKeyboard> keyboard;
    std::unique_ptr<IMonitor> monitor;
public:
    Computer(std::unique_ptr<IKeyboard> k, std::unique_ptr<IMonitor> m)
        : keyboard(std::move(k)), monitor(std::move(m)) {}

    void run() {
        keyboard->type();
        monitor->display("Hello, Dependency Inversion!");
    }
};

int main() {
    auto keyboard = std::make_unique<MechanicalKeyboard>();
    auto monitor  = std::make_unique<LEDMonitor>();

    Computer pc(std::move(keyboard), std::move(monitor));
    pc.run();
}