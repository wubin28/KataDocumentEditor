#include "DocumentEditorFacade.h"

DocumentEditorFacade::DocumentEditorFacade(string contents = "") {
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

void DocumentEditorFacade::setColor(size_t rowIndex, size_t colIndex, size_t length, string color) {
    for (size_t i = 0; i != length; i++) {
        screenColors[rowIndex][colIndex + i] = color;
    }
}

void DocumentEditorFacade::drawScreen() {
    for (size_t i = 0; i != ROW_COUNT; ++i) {
        for (size_t j = 0; j != COL_COUNT; ++j) {
            Character *charObj = glyphFactory.getCharObj(screenChars[i][j]);
            screenDrawnResult[i][j] = charObj->draw(screenColors[i][j]);
            charObj = nullptr;
        }
    }
}

string DocumentEditorFacade::getColor(size_t rowIndex, size_t colIndex) {
    return screenColors[rowIndex][colIndex];
}

string DocumentEditorFacade::getScreenDrawnResult(size_t rowIndex, size_t colIndex) {
    return screenDrawnResult[rowIndex][colIndex];
}

