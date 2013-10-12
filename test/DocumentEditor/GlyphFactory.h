#ifndef GlyphFactory_h
#define GlyphFactory_h
#include "Character.h"

const size_t NCHARCODES = 128;

class GlyphFactory {
public:
    GlyphFactory(); 
    ~GlyphFactory(); 
    Character *getCharObj(char c); 
private:
    Character *_characters[NCHARCODES];
};

#endif