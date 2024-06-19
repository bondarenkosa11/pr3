#include <iostream>
#include <string>
#include <vector>

// Абстрактный класс TextEditor
class TextEditor {
public:
    virtual void createFile() = 0;
    virtual void editFile() = 0;
    virtual void printFile() = 0;
    virtual void highlightKeywords() = 0;

    void templateMethod() {
        createFile();
        editFile();
        highlightKeywords();
        printFile();
    }
};

// Конкретный класс для текстового редактора с поддержкой подсветки ключевых слов
class KeywordHighlightingTextEditor : public TextEditor {
public:
    void createFile() override {
        std::cout << "Creating a text file" << std::endl;
    }

    void editFile() override {
        std::cout << "Editing the text file" << std::endl;
    }

    void printFile() override {
        std::cout << "Printing the text file" << std::endl;
    }

    void highlightKeywords() override {
        std::cout << "Highlighting keywords in the text file" << std::endl;
    }
};

int main() {
    TextEditor* editor = new KeywordHighlightingTextEditor();
    editor->templateMethod();

    delete editor;

    return 0;
}
