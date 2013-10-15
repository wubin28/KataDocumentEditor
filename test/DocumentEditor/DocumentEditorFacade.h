#ifndef DocumentEditorFacade_h
#define DocumentEditorFacade_h

#include <string>
#include "Character.h"
#include "GlyphFactory.h"
using std::size_t;
using std::string;

const size_t ROW_COUNT = 3;
const size_t COL_COUNT = 40;

class DocumentEditorFacade {
public:
    DocumentEditorFacade(string contents); 
    void setColor(size_t rowIndex, size_t colIndex, size_t length, string color); 
    void drawScreen(); 
    string getColor(size_t rowIndex, size_t colIndex);
    string getScreenDrawnResult(size_t rowIndex, size_t colIndex); 
private:
    char screenChars[ROW_COUNT][COL_COUNT];
    string screenColors[ROW_COUNT][COL_COUNT];
    string screenDrawnResult[ROW_COUNT][COL_COUNT];
    GlyphFactory glyphFactory;
};

#endif