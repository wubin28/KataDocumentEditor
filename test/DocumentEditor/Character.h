#ifndef Character_h
#define Character_h

#include <string>
using std::string;

class Character {
public:
    Character(char c);
    char getCharacter(); 
    string draw(string color); 
private:
    char character;
};

#endif