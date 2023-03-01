#include "IdVerifier.hpp"

bool IdVerifier::ecuatorian(std::string_view id) {
    if (id.size() != 10)
        return false;

    short oddSum{};

    for (std::size_t i{}; i < 9; i += 2) {
        short value{ static_cast<short>((id[i] - '0') * 2) };

        if (value > 9)
            value -= 9;

        oddSum += value;
    }

    short evenSum{};

    for (std::size_t i{ 1 }; i < 8; i += 2)
        evenSum += id[i] - '0';

    short digitVerificator{ static_cast<short>((evenSum + oddSum) % 10 == 0 ? 0 : 10 - ((evenSum + oddSum) % 10)) };

    return id[id.size() - 1] - '0' == digitVerificator;
}