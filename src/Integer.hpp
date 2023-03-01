#pragma once

#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <string>

class Integer {
    private:

    public:
        /**
         * @brief Returns amount of digits of value
         * 
         * @param value Integer to count his digits
         * @return int Amount of digits
         */
        static int digits(int value);

        /**
         * @brief Returns the string representation of value
         * 
         * @param value Value to transform
         * @return std::string Value like string
         */
        static std::string toString(int value);

        /**
         * @brief Returns the string representation of value
         * 
         * @param value Value to transform
         * @return std::string Value like string
         */
        static std::string toString(float value);
};

#endif