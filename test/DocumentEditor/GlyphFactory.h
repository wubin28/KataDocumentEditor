#ifndef GlyphFactory_h
#define GlyphFactory_h
#include "Character.h"
#include <memory>
using std::shared_ptr;

const size_t NCHARCODES = 128;

class GlyphFactory {
public:
    GlyphFactory(); 
    ~GlyphFactory(); 
    shared_ptr<Character> getCharObj(char c); 
private:
    shared_ptr<Character> _characters[NCHARCODES];
};

#endif