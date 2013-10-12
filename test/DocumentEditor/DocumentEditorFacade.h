#ifndef DocumentEditorFacade_h
#define DocumentEditorFacade_h

#include <string>
#include <cstddef>
#include "Character.h"
#include "GlyphFactory.h"
using std::size_t;
using std::string;

const size_t rowCnt = 3, colCnt = 40;
char screenChars[rowCnt][colCnt];
string screenColors[rowCnt][colCnt];
string screenDrawnResult[rowCnt][colCnt];

class DocumentEditorFacade {
public:
    DocumentEditorFacade(string contents = "") {
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
    void setColor(size_t rowIndex, size_t colIndex, size_t length, string color) {
        for (size_t i = 0; i != length; i++) {
            screenColors[rowIndex][colIndex + i] = color;
        }
    }
    void drawScreen() {
        for (size_t i = 0; i != rowCnt; ++i) {
            for (size_t j = 0; j != colCnt; ++j) {
                screenDrawnResult[i][j] = string(1, screenChars[i][j]) + "-" + screenColors[i][j];
            }
        }
    }
    string getColor(size_t rowIndex, size_t colIndex) {
        return screenColors[rowIndex][colIndex];
    }
    string getScreenDrawnResult(size_t rowIndex, size_t colIndex) {
        return screenDrawnResult[rowIndex][colIndex];
    }

    char getChar(size_t rowIndex, size_t colIndex) {
        return screenChars[rowIndex][colIndex];
    }
private:
    GlyphFactory glyphFactory;
};

#endif