#include "Integer.hpp"
#include <cmath>
#include <iostream>

int Integer::digits(int value) {
    if (value == 0)
        return 1;

    if (value < 0)
        value *= -1;

    int count{};

    while (value > 0) {
        ++count;
        value /= 10;
    }

    return count;
}

std::string Integer::toString(int value) {
    int digitsOfValue{ digits(value) };
    std::string string{};

    if (value < 0) {
        value *= -1;
        string.push_back('-');
    }

    while (digitsOfValue > 0) {
        char digit{ static_cast<char>(value / std::pow(10, digitsOfValue - 1) + '0') };
        string.push_back(digit);
        value %= static_cast<int>(std::pow(10, digitsOfValue - 1));
        --digitsOfValue;
    }

    return string;
}

std::string Integer::toString(float value) {
    bool haveDecimals{ std::abs(value) > std::abs(static_cast<int>(value)) };

    if (!haveDecimals)
        return toString(static_cast<int>(value));

    bool isNegative{ value < 0 };

    std::string string{ isNegative ? "-" + toString(static_cast<int>(value)) : toString(static_cast<int>(value)) };

    if (isNegative)
        value *= -1;

    float decimals{ value - static_cast<int>(value) };
    while (haveDecimals) {
        decimals *= 10;
        haveDecimals = decimals > static_cast<int>(decimals);
    }

    return string + '.' + toString(static_cast<int>(decimals));
}