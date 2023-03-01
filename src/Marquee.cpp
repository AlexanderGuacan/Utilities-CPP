#include "Marquee.hpp"
#include "Console.hpp"
#include <iostream>

Marquee::Marquee(const std::string_view phrase, short row, short startColumn, short spacesFromEndCharacter) : m_phrase{ phrase }, m_row{ row }, m_startColumn{ startColumn }, m_endColumn{ static_cast<short>(startColumn + phrase.size() + spacesFromEndCharacter) } {
    Console::enableANSICode();
}

void Marquee::print() {
    bool isFirstRound{ true };
    short currentColumn{ static_cast<short>(m_startColumn + 1) };
    std::size_t finalCharacters{ 1 };

    while (m_isActive) {
        while(m_isPause) {}

        if (isFirstRound) {
            Console::setCursorPosition(m_row, m_startColumn);
            std::cout << m_phrase.substr(m_phrase.size() - finalCharacters, finalCharacters);

            ++finalCharacters;

            if (finalCharacters > m_phrase.size()) {
                isFirstRound = false;
                finalCharacters = 1;
            }

        } else if (static_cast<short>(m_phrase.size() + currentColumn) <= m_endColumn + 1) {
            Console::setCursorPosition(m_row, currentColumn);
            std::cout << "\b " << m_phrase;

            ++currentColumn;

        } else if (currentColumn <= m_endColumn) {
            Console::setCursorPosition(m_row, currentColumn);
            std::cout << "\b " << m_phrase.substr(0, m_phrase.size() - finalCharacters);

            Console::setCursorPosition(m_row, m_startColumn);
            std::cout << m_phrase.substr(m_phrase.size() - finalCharacters, finalCharacters);

            ++currentColumn;
            ++finalCharacters;

        } else {
            Console::setCursorPosition(m_row, currentColumn);
            std::cout << "\b ";

            Console::setCursorPosition(m_row, m_startColumn);
            std::cout << m_phrase;

            currentColumn = m_startColumn + 1;
            finalCharacters = 1;
        }

        Console::wait(500);
    }
    
}

void Marquee::pause() {
    m_isPause = true;
}

void Marquee::resume() {
    m_isPause = false;
}

void Marquee::stop() {
    m_isActive = false;
}