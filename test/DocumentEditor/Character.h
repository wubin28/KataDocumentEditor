#ifndef Character_h
#define Character_h

class Character {
public:
    Character(char c = ' '):
        character(c) {
    }
    char getCharacter() {
        return character;
    }
private:
    char character;
};

#endif