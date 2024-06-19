#include <iostream>
#include <string>

// Абстрактный класс Стратегии
class HighlightStrategy {
public:
    virtual void highlightKeywords(std::string text) = 0;
};

// Конкретная стратегия для подсветки ключевых слов в файле C++
class CppHighlightStrategy : public HighlightStrategy {
public:
    void highlightKeywords(std::string text) override {
        // Логика подсветки ключевых слов для файлов C++
        std::cout << "Highlighting C++ keywords in the text: " << text << std::endl;
    }
};

// Конкретная стратегия для подсветки ключевых слов в файле Python
class PythonHighlightStrategy : public HighlightStrategy {
public:
    void highlightKeywords(std::string text) override {
        // Логика подсветки ключевых слов для файлов Python
        std::cout << "Highlighting Python keywords in the text: " << text << std::endl;
    }
};

// Контекст, использующий стратегию для подсветки ключевых слов
class TextEditor {
private:
    HighlightStrategy* highlightStrategy;
public:
    TextEditor(HighlightStrategy* strategy) : highlightStrategy(strategy) {}

    void setHighlightStrategy(HighlightStrategy* strategy) {
        highlightStrategy = strategy;
    }

    void highlightText(std::string text) {
        highlightStrategy->highlightKeywords(text);
    }
};

int main() {
    CppHighlightStrategy cppStrategy;
    PythonHighlightStrategy pythonStrategy;

    TextEditor editor(&cppStrategy);
    editor.highlightText("This is a C++ file");

    editor.setHighlightStrategy(&pythonStrategy);
    editor.highlightText("This is a Python file");

    return 0;
}
