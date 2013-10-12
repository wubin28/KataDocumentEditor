#ifndef DocumentEditorFacade_h
#define DocumentEditorFacade_h

#include <string>
#include <cstddef>
#include <iostream>
#include "Character.h"
#include "GlyphFactory.h"
using std::size_t;
using std::string;
using std::cout;

const size_t ROW_COUNT = 3;
const size_t COL_COUNT = 40;

class DocumentEditorFacade {
public:
    DocumentEditorFacade(string contents = "") {
        for (size_t i = 0; i != ROW_COUNT; ++i) {
            for (size_t j = 0; j != COL_COUNT; ++j) {
                if ((i * COL_COUNT + j) < contents.size()) {
                    screenChars[i][j] = contents[i * COL_COUNT + j];
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
        for (auto &row : screenDrawnResult) {
            for (auto &col : row) {
                col = "*";
            }
        }
    }
    void setColor(size_t rowIndex, size_t colIndex, size_t length, string color) {
        for (size_t i = 0; i != length; i++) {
            screenColors[rowIndex][colIndex + i] = color;
        }
    }
    void drawScreen() {
        for (size_t i = 0; i != ROW_COUNT; ++i) {
            for (size_t j = 0; j != COL_COUNT; ++j) {
                Character *charObj = glyphFactory.getCharObj(screenChars[i][j]);
                screenDrawnResult[i][j] = charObj->draw(screenColors[i][j]);
                charObj = nullptr;
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
    char screenChars[ROW_COUNT][COL_COUNT];
    string screenColors[ROW_COUNT][COL_COUNT];
    string screenDrawnResult[ROW_COUNT][COL_COUNT];
    GlyphFactory glyphFactory;
};

#endif