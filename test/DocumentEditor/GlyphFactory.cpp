#include "GlyphFactory.h"

GlyphFactory::GlyphFactory() {
    for (size_t i = 0; i != NCHARCODES; ++i) {
        _characters[i] = nullptr;
    }
}

GlyphFactory::~GlyphFactory() {
    for (size_t i = 0; i != NCHARCODES; ++i) {
        delete _characters[i];
        _characters[i] = nullptr;
    }
}

Character *GlyphFactory::getCharObj(char c) {
    if (!_characters[c]) {
        _characters[c] = new Character(c);
    }
    return _characters[c];
}
