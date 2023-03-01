#pragma once

#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
#include <functional>

/**
 * @brief Controlled characters input of different data types
 *
 */
class Input {
    private:

    public:
        /**
         * @brief Enters numeric characters (0-9) and include the negative sign '-' if hasSign variable is true
         * 
         * @param message String to print before to input characters
         * @param maxDigits Maximum digits to enter. Negative sign don't count like digit
         * @param minDigits Minimum digits to enter for a valid value. Negative sign don't count like digit
         * @param hasSign Enable or disable to enter negative sign
         * @return int Digits entered transform to int value
         */
        int integer(std::string_view message, short maxDigits, short minDigits = 1, bool hasSign = true);

        /**
         * @brief Enters numeric characters (0-9), include negative sign '-' and decimal separator '.' if hasSign variable is true and minDigits is greather than zero, respectively.
         * 
         * @param message String to print before to input characters
         * @param maxDigits Maximum digits of integer part to enter. Negative sign and decimal separator don't count like digit
         * @param maxDecimals Maximum digit of decimal part to enter. Negative sign and decimal separator don't count like digit
         * @param minDigits Minimum digits of integer part for a valid value. The minimum number of decimal amount must also be entered in order to take the value as valid.
         * @param minDecimals Minimum digits of decimal part for a valid value. The minimum number of digits amount of integer part must also be entered in order to take the value as valid.
         * @param hasSign Enable or disable to enter negative sign
         * @return float Digits entered transform to float value
         */
        float floating(std::string_view message, short maxDigits, short maxDecimals, short minDigits = 1, short minDecimals = 0, bool hasSign = true);

        /**
         * @brief Enters specific characters through pointer to function that indicates allowed characters
         *
         * @param message String to print before to input data
         * @param isAllowedCharacter Callable object with the rules for an allowed character. Example:
         * auto uppercaseCharacter{ [](unsigned char character) -> bool { return character >= 'A' && character <= 'Z'; } };. In this lambda function indicates that only can enter uppercase characters
         * @param maxCharacters Maximum characters to enter in string
         * @param minCharacters Minimum characters to enter for a valid string
         * @return std::string String with characters entered
         */
        std::string string(std::string_view message, std::function<bool(unsigned char character)> isAllowedCharacter, short maxCharacters, short minCharacters = 1);

        /**
         * @brief Enters numeric characters (0-9) and return it like a string. Also can enable space character
         * 
         * @param message String to print before to input data
         * @param maxDigits Maximum digits to enter in string
         * @param minDigits Minimum digits to enter for a valid string
         * @param space Enable or disable space character
         * @return std::string String with digits entered
         */
        std::string digits(std::string_view message, short maxDigits, short minDigits = 1, bool space = false);

        /**
         * @brief Enters alphabetic characters [a-zA-Z]. Can enable space character
         * 
         * @param message String to print before to input data
         * @param maxCharacters Maximum characters to enter in string
         * @param minCharacters Minimum characters to enter for a valid string
         * @param space Enable or disable space character
         * @return std::string String with characters entered
         */
        std::string alphabetic(std::string_view message, short maxCharacters, short minCharacters = 1, bool space = false);

        /**
         * @brief Enters alphabetic characters [a-zA-Z]. Can enable space character
         * 
         * @param message String to print before to input data
         * @param maxCharacters Maximum characters to enter in string
         * @param minCharacters Minimum characters to enter for a valid string
         * @param space Enable or disable space character
         * @return std::string String with characters entered
         */
        std::string alphanumeric(std::string_view message, short maxCharacters, short minCharacters = 1, bool space = false);
};

#endif