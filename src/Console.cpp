#include "Console.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void Console::enableANSICode() {
    std::system(" ");
}

void Console::saveCursorPosition() {
    std::cout << "\e[s";
}

void Console::restoreCursorPosition() {
    std::cout << "\e[u";
}

void Console::setCursorPosition(short row, short column) {
    std::cout << "\e[" << row + 1 << ';' << column + 1 << 'H';
}

void Console::cursorVisibility(bool on) {
    std::cout << "\e[?25" << (on ? 'h' : 'l');
}

void Console::textForegroundColor(Color color) {
    std::cout << "\e[38;5;" << color << 'm';
}

void Console::textBackgroundColor(Color color) {
    std::cout << "\e[48;5;" << color << 'm';
}

void Console::clearScreen() {
    std::system("cls");
}

void Console::clearLine() {
    std::cout << "\e[2K\e[G";
}

void Console::clearLine(short row) {
    saveCursorPosition();
    setCursorPosition(row, 0);
    clearLine();
    restoreCursorPosition();
}

void Console::moveUpCursor(const short positions) {
    std::cout << "\e[" << positions << 'A';
}

void Console::moveDownCursor(const short positions) {
    std::cout << "\e[" << positions << 'B';
}

void Console::moveForwardCursor(const short positions) {
    std::cout << "\e[" << positions << 'C';
}

void Console::moveBackwardCursor(const short positions) {
    std::cout << "\e[" << positions << 'D';
}

void Console::resize(const short rows, const short columns) {
    std::system(std::string{ "mode con cols=" + std::to_string(columns) + " lines=" + std::to_string(rows) }.c_str());
}

void Console::wait(short milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Console::pause() {
    std::system("pause > nul");
}