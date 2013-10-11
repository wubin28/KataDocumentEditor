#ifndef DocumentEditorFacade_h
#define DocumentEditorFacade_h

#include <string>
#include <cstddef>
using std::size_t;

const size_t rowCnt = 3, colCnt = 40;
char screenChars[rowCnt][colCnt] = {'*'};
std::string screenColor[rowCnt][colCnt] = {"black"};

class DocumentEditorFacade {
public:
    DocumentEditorFacade(std::string s = ""):
        contents(s) {
    }
    void setColor(unsigned rowIndex, unsigned colIndex, unsigned length, std::string color) {
        for (unsigned i = 0; i != length - 1; i++) {
            screenColor[rowIndex][colIndex + i] = color;
        }
    }
    void drawScreen() {
    }
    std::string getColor(unsigned rowIndex, unsigned colIndex) {
        return "red";
    }

    // Hello world demo.
    int sayOne() {
        return 1;
    }
    std::string sayHello() {
        return "Hello!";
    }
private:
    std::string contents;
};

#endif