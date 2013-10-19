#include "GlyphFactory.h"
using std::make_shared;

GlyphFactory::GlyphFactory() {
    for (size_t i = 0; i != NCHARCODES; ++i) {
        _characters[i] = nullptr;
    }
}

GlyphFactory::~GlyphFactory() {
}

shared_ptr<Character> GlyphFactory::getCharObj(char c) {
    if (!_characters[c]) {
        _characters[c] = make_shared<Character>(c);
    }
    return _characters[c];
}
