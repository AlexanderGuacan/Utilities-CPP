#include "MenuGraphic.hpp"
#include <iostream>

void MenuGraphic::printMenu() const {
    Console::setCursorPosition(m_row, m_column);
    Console::textForegroundColor(m_titleColor);
    std::cout << m_title;

    printSelectedOption();

    for (std::size_t i{ 0 }; i < m_options.size(); ++i) {
        if (static_cast<short>(i + 1ull) == m_optionSelected)
            continue;
        
        Console::setCursorPosition(m_row + i + 1ull, m_column);
        std::cout << m_options.at(i);
    }

    Console::setCursorPosition(m_row + m_optionSelected, m_column);
}

void MenuGraphic::printSelectedOption() const {
    Console::setCursorPosition(m_row + m_optionSelected, m_column);
    Console::textForegroundColor(m_selectedOptionColor);
    std::cout << m_options.at(m_optionSelected - 1);
    Console::textForegroundColor(m_unselectedOptionColor);
    Console::setCursorPosition(m_row + m_optionSelected, m_column);
}

void MenuGraphic::updateOption(Keyboard::Key direction) {
    switch (direction) {
        case Keyboard::Key::up:
            if (m_optionSelected <= 1)
                break;
            
            std::cout << m_options.at(m_optionSelected - 1);
            --m_optionSelected;
            printSelectedOption();
            break;

        case Keyboard::Key::down:
            if (m_optionSelected >= static_cast<short>(m_options.size()))
                break;

            std::cout << m_options.at(m_optionSelected - 1);
            ++m_optionSelected;
            printSelectedOption();
            break;
            
        default:
            break;
    }
}

MenuGraphic::MenuGraphic(std::string_view title, std::initializer_list<std::string_view> options) : m_title{ title } {
    for (const auto& option : options)
        m_options.push_back(option);
}

void MenuGraphic::setPosition(short row, short column) {
    m_row = row;
    m_column = column;
}

void MenuGraphic::setTitleColor(Console::Color color) {
    m_titleColor = color;
}

void MenuGraphic::setUnselectedOptionColor(Console::Color color) {
    m_unselectedOptionColor = color;
}

void MenuGraphic::setSelectedOptionColor(Console::Color color) {
    m_selectedOptionColor = color;
}

short MenuGraphic::play() {
    Console::enableANSICode();
    Console::cursorVisibility(false);
    printMenu();

    while (true) {
        while (!Keyboard::hasPressedkey()) {}

        Keyboard::Key keyPressed{ static_cast<Keyboard::Key>(Keyboard::readKey()) };

        if (keyPressed == Keyboard::Key::enter) {
            Console::setCursorPosition(m_row + m_options.size() + 1, 0);
            Console::cursorVisibility(true);
            Console::textForegroundColor(Console::Color::white);
            return m_optionSelected;
        }

        updateOption(keyPressed);
    }
    
}