#include "Character.h"

Character::Character(char c = ' '):
    character(c) {
}

char Character::getCharacter() {
    return character;
}

string Character::draw(string color) {
    return string(1, character) + "-" + color;
}
