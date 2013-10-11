#ifndef DocumentEditorFacade_h
#define DocumentEditorFacade_h

#include <string>

class DocumentEditorFacade {
public:
    DocumentEditorFacade(unsigned rowMax = 0, unsigned colMax = 0, std::string s = ""):
        rowMax(rowMax), colMax(colMax), contents(s) {
    }
    void setColor(unsigned rowIndex, unsigned colIndex, unsigned length, std::string color) {
    }

    // Hello world demo.
    int sayOne() {
        return 1;
    }
    std::string sayHello() {
        return "Hello!";
    }
private:
    unsigned rowMax;
    unsigned colMax;
    std::string contents;
};

#endif