#ifndef DocumentEditorFacade_h
#define DocumentEditorFacade_h

#include <string>
#include <cstddef>
using std::size_t;

const size_t rowCnt = 3, colCnt = 40;
char screenChars[rowCnt][colCnt];
std::string screenColors[rowCnt][colCnt];


class DocumentEditorFacade {
public:
    DocumentEditorFacade(std::string s = ""):
        contents(s) {
            for (auto &row : screenChars) {
                for (auto &col : row) {
                    col = '*';
                }
            }
            for (auto &row : screenColors) {
                for (auto &col : row) {
                    col = "black";
                }
            }
    }
    void setColor(unsigned rowIndex, unsigned colIndex, unsigned length, std::string color) {
        for (unsigned i = 0; i != length - 1; i++) {
            screenColors[rowIndex][colIndex + i] = color;
        }
    }
    void drawScreen() {
    }
    std::string getColor(unsigned rowIndex, unsigned colIndex) {
        return screenColors[rowIndex][colIndex];
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