#include "String.hpp"
#include "Character.hpp"
#include <cmath>
#include <exception>

int String::parseInteger(std::string_view string) {
    if (string.size() == 0)
        return 0;
        
    const bool isNegative{ string[0] == '-' };
    int value{};
    short integers{ static_cast<short>(string.size() - (isNegative ? 1ull : 0ull)) };

    for (std::size_t i{ isNegative ? 1ull : 0ull }; i < string.size(); ++i) {
        if (!Character::isDigit(string[i]))
            throw "Isn't an integer string";

        value += (string[i] - '0') * std::pow(10, integers - 1);

        --integers;
    }

    return isNegative ? -value : value;
}

float String::parseFloating(std::string_view string) {
    if (string.size() == 0)
        return 0;

    const bool isNegative{ string[0] == '-' };
    const std::size_t dotPosition{ string.find('.') };
    const bool hasDecimals{ dotPosition < string.size() };

    std::string integerPart{};
    std::string decimalPart{};
    
    if (hasDecimals) {
        integerPart = string.substr(isNegative ? 1ull : 0ull, dotPosition - (isNegative ? 1ull : 0ull));
        decimalPart = string.substr(dotPosition + 1ull, string.size() - dotPosition - 1ull);
    } else {
        integerPart = string.substr(isNegative ? 1ull : 0ull, string.size() - (isNegative ? 1ull : 0ull));
        decimalPart = "0";
    }
    
    int integers{ parseInteger(integerPart) };
    int decimals{ parseInteger(decimalPart) };

    return (integers + (decimals == 0 ? decimals : decimals / std::pow(10, decimalPart.size()))) * (isNegative ? -1 : 1);
}

float String::valueOf(std::string_view string) {
    if (string.find('.') != string.npos)
        return parseFloating(string);

    return parseInteger(string);
}

std::string String::toLowerCase(std::string_view string) {
    std::string lowerString{};
    lowerString.reserve(string.size());

    for (const auto& character : string)
        lowerString.push_back(Character::toLowerCase(character));

    return lowerString;
}

std::string String::toUpperCase(std::string_view string) {
    std::string upperString{};
    upperString.reserve(string.size());

    for (const auto& character : string)
        upperString.push_back(Character::toUpperCase(character));

    return upperString;
}

std::string String::capitalize(std::string_view string) {
    std::string wordCapitalized{ Character::toUpperCase(string[0]) };

    for (std::size_t i{ 1 }; i < string.size(); ++i)
        wordCapitalized.push_back(Character::toLowerCase(string[i]));

    return wordCapitalized;
}

bool String::isDigit(std::string_view string) {
    for (const auto& character : string) {
        if (!Character::isDigit(character))
            return false;
    }

    return true;
}

bool String::isAlphabetic(std::string_view string) {
    for (const auto& character : string) {
        if (!Character::isAlphabetic(character))
            return false;
    }

    return true;
}

bool String::isAlphanumeric(std::string_view string) {
    for (const auto& character : string) {
        if (!Character::isAlphanumeric(character))
            return false;
    }

    return true;
}

bool String::isBlank(std::string_view string) {
    for (const auto& character : string) {
        if (!Character::isBlank(character))
            return false;
    }

    return true;
}

std::list<std::string> String::split(std::string_view string, char token) {
    std::list<std::string> stringSplit{};

    std::string_view::iterator iterator{ string.begin() };

    while (iterator != string.end()) {
        std::string substring{};

        while (*iterator != token && iterator != string.end()) {
            substring.push_back(*iterator);
            ++iterator;
        }

        stringSplit.push_back(substring);
            
        if (iterator == string.end())
            break;

        ++iterator;
    }

    return stringSplit;
}

std::string String::lstrip(std::string_view string, char characterToDelete) {
    std::size_t left{};
    auto iterator{ string.begin() };

    while (*iterator == characterToDelete) {
        ++left;
        ++iterator;
    }

    return static_cast<std::string>(string.substr(left, string.size() - left));
}

std::string String::rstrip(std::string_view string, char characterToDelete) {
    std::size_t right{};
    auto reverseIterator{ string.rbegin() };

    while (*reverseIterator == characterToDelete) {
        ++right;
        ++reverseIterator;
    }

    return static_cast<std::string>(string.substr(0, string.size() - right));
}

std::string String::strip(std::string_view string, char characterToDelete) {
    std::size_t left{};
    std::size_t right{};
    auto iterator{ string.begin() };
    auto reverseIterator{ string.rbegin() };

    while (*iterator == characterToDelete || *reverseIterator == characterToDelete) {

        if (*iterator == characterToDelete) {
            ++left;
            ++iterator;
        }

        if (*reverseIterator == characterToDelete) {
            ++right;
            ++reverseIterator;
        }
    }

    return static_cast<std::string>(string.substr(left, string.size() - left - right));
}