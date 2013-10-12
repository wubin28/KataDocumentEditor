#ifndef GlyphFactory_h
#define GlyphFactory_h
#include <iostream>
using std::endl;
using std::cout;

const size_t NCHARCODES = 128;

class GlyphFactory {
public:
    GlyphFactory() {
        for (size_t i = 0; i != NCHARCODES; ++i) {
            _characters[i] = nullptr;
        }
    }
    ~GlyphFactory() {
        for (size_t i = 0; i != NCHARCODES; ++i) {
            delete _characters[i];
            _characters[i] = nullptr;
        }
    }

    Character *getCharObj(char c) {
        if (!_characters[c]) {
            _characters[c] = new Character(c);
        }
        return _characters[c];
    }
private:
    Character *_characters[NCHARCODES];
};

#endif