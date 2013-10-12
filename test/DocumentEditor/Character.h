#ifndef Character_h
#define Character_h

#include <string>
using std::string;

class Character {
public:
    Character(char c = ' '):
        character(c) {
    }
    ~Character() {
    }
    char getCharacter() {
        return character;
    }
    string draw(string color) {
        return string(1, character) + "-" + color;
    }
private:
    char character;
};

#endif