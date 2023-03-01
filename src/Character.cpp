#include "Character.hpp"
#include <cmath>

bool Character::isDigit(char character) {
    return character >= '0' && character <= '9';
}

bool Character::isAlphabetic(char character) {
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}

bool Character::isAlphanumeric(char character) {
    return isDigit(character) || isAlphabetic(character);
}

bool Character::isBlank(char character) {
    return character == ' ';
}

char Character::toLowerCase(char character) {
    return character >= 'A' && character <= 'Z' ? character + ('a' - 'A') : character;
}

char Character::toUpperCase(char character) {
    return character >= 'a' && character <= 'z' ? character - ('a' - 'A') : character;
}