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
    DocumentEditorFacade(std::string contents = "") {
            for (size_t i = 0; i != rowCnt; ++i) {
                for (size_t j = 0; j != colCnt; ++j) {
                    if ((i * colCnt + j) < contents.size()) {
                        screenChars[i][j] = contents[i * colCnt + j];
                    } else {
                        screenChars[i][j] = ' ';
                    }
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
    char getChar(unsigned rowIndex, unsigned colIndex) {
        return screenChars[rowIndex][colIndex];
    }

};

#endif