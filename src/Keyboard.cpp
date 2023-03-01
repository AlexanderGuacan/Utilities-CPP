#include "Keyboard.hpp"
#include <conio.h>

int Keyboard::readKey() {
    int keyPressed{ _getch() };
    return (keyPressed == 0 || keyPressed == 224) ? 256 + _getch() : keyPressed;
}

bool Keyboard::hasPressedkey() {
    return _kbhit();
}