#include "Input.hpp"
#include "Keyboard.hpp"
#include "Character.hpp"
#include "String.hpp"
#include <cassert>
#include <iostream>

int Input::integer(std::string_view message, short maxDigits, short minDigits, bool hasSign) {
    assert(minDigits >= 1 && maxDigits <= 9);

    std::cout << message;

    std::string value{};
    value.reserve(maxDigits + hasSign ? 1 : 0);

    unsigned char keyPressed{};
    bool hasPressedEnter{ false };

    while (!hasPressedEnter || value.size() < static_cast<std::size_t>(minDigits)) {
        while (!Keyboard::hasPressedkey()) {}
        hasPressedEnter = (keyPressed = Keyboard::readKey()) == Keyboard::enter;

        if (Character::isDigit(keyPressed) && value.size() < static_cast<std::size_t>(maxDigits)) {
            value.push_back(keyPressed);
            std::cout << keyPressed;
        } else if (keyPressed == '-' && value.size() == 0 && hasSign) {
            ++maxDigits;
            ++minDigits;
            value.push_back(keyPressed);
            std::cout << keyPressed;
        } else if (keyPressed == Keyboard::backspace && value.size() > 0) {
            
            if (value.at(value.size() - 1) == '-') {
                --maxDigits;
                --minDigits;
            }

            value.pop_back();
            std::cout << "\b \b";
        }
    }

    std::cout << '\n';

    return String::parseInteger(value);
}

float Input::floating(std::string_view message, short maxDigits, short maxDecimals, short minDigits, short minDecimals, bool hasSign) {
    assert(minDigits >= 1 && maxDigits <= 38);

    std::cout << message;
    
    std::string value{};
    value.reserve(maxDigits + maxDecimals + hasSign ? 2 : 1);

    unsigned char keyPressed{};
    bool hasPressedEnter{ false };
    bool hasPressedDot{ false };

    while (!hasPressedEnter || value.size() <= static_cast<std::size_t>(minDigits + minDecimals)) {
        while (!Keyboard::hasPressedkey()) {}
        hasPressedEnter = (keyPressed = Keyboard::readKey()) == Keyboard::enter;

        if (Character::isDigit(keyPressed) && ((value.size() < static_cast<std::size_t>(maxDigits) && !hasPressedDot) || (value.size() - value.find('.') <= static_cast<std::size_t>(maxDecimals) && hasPressedDot))) {
            value.push_back(keyPressed);
            std::cout << keyPressed;
        } else if (keyPressed == '.' && !hasPressedDot && minDecimals > 0) {
            hasPressedDot = true;
            value.push_back(keyPressed);
            std::cout << keyPressed;
        } else if (keyPressed == '-' && value.size() == 0 && hasSign) {
            ++minDigits;
            ++maxDigits;
            value.push_back(keyPressed);
            std::cout << keyPressed;
        } else if (keyPressed == Keyboard::backspace && value.size() > 0) {
            if (value.at(value.size() - 1) == '.') {
                hasPressedDot = false;
            } else if (value.at(value.size() - 1) == '-') {
                --minDigits;
                --maxDigits;
            }

            value.pop_back();
            std::cout << "\b \b";
        }
    }

    std::cout << '\n';

    return String::parseFloating(value);
}

std::string Input::string(std::string_view message, std::function<bool(unsigned char character)> isAllowedCharacter, short maxCharacters, short minCharacters) {
    std::string text{};

    assert(minCharacters >= 1 && static_cast<std::size_t>(maxCharacters) < text.max_size());

    std::cout << message;

    text.reserve(maxCharacters);

    unsigned char keyPressed{};
    bool hasPressedEnter{ false };

    while (!hasPressedEnter || text.size() < static_cast<std::size_t>(minCharacters)) {
        while (!Keyboard::hasPressedkey()) {}

        hasPressedEnter = (keyPressed = Keyboard::readKey()) == Keyboard::enter;

        if (isAllowedCharacter(keyPressed) && text.size() < static_cast<std::size_t>(maxCharacters)) {
            text.push_back(keyPressed);
            std::cout << keyPressed;

        } else if (keyPressed == Keyboard::backspace && text.size() > 0) {
            text.pop_back();
            std::cout << "\b \b";
        }
    }

    std::cout << '\n';

    return text;
}

std::string Input::digits(std::string_view message, short maxDigits, short minDigits, bool space) {
    auto digits{ [=](unsigned char character) -> bool { return Character::isDigit(character) || (Character::isBlank(character) && space); } };
    return string(message, digits, maxDigits, minDigits);
}

std::string Input::alphabetic(std::string_view message, short maxCharacters, short minCharacters, bool space) {
    auto alphabeticCharacters{ [=](unsigned char character) -> bool { return Character::isAlphabetic(character) || (Character::isBlank(character) && space); } };
    return string(message, alphabeticCharacters, maxCharacters, minCharacters);
}

std::string Input::alphanumeric(std::string_view message, short maxCharacters, short minCharacters, bool space) {
    auto alphanumericCharacters{ [=](unsigned char character) -> bool { return Character::isAlphanumeric(character) || (Character::isBlank(character) && space); } };
    return string(message, alphanumericCharacters, maxCharacters, minCharacters);
}