#include <iostream>
#include <string>

// ����������� ����� ���������
class HighlightStrategy {
public:
    virtual void highlightKeywords(std::string text) = 0;
};

// ���������� ��������� ��� ��������� �������� ���� � ����� C++
class CppHighlightStrategy : public HighlightStrategy {
public:
    void highlightKeywords(std::string text) override {
        // ������ ��������� �������� ���� ��� ������ C++
        std::cout << "Highlighting C++ keywords in the text: " << text << std::endl;
    }
};

// ���������� ��������� ��� ��������� �������� ���� � ����� Python
class PythonHighlightStrategy : public HighlightStrategy {
public:
    void highlightKeywords(std::string text) override {
        // ������ ��������� �������� ���� ��� ������ Python
        std::cout << "Highlighting Python keywords in the text: " << text << std::endl;
    }
};

// ��������, ������������ ��������� ��� ��������� �������� ����
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
