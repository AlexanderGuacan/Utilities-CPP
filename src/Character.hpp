#pragma once

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character {
    public:
        /**
         * @brief Verify if character is between '0' and '9'
         * 
         * @param character 
         * @return true if between '0' and '9'
         * @return false if out of range between '0' and '9'
         */
        static bool isDigit(char character);

        /**
         * @brief Verify if character is between 'a' and 'z' or 'A' and 'Z'
         * 
         * @param character 
         * @return true if between 'a' and 'z' or 'A' and 'Z'
         * @return false if out of range between 'a' and 'z' or 'A' and 'Z'
         */
        static bool isAlphabetic(char character);

        /**
         * @brief Verify if character is numeric or alphabetic
         * 
         * @param character 
         * @return true if is numeric or alphabetic
         * @return false if not is numeric or alphabetic
         */
        static bool isAlphanumeric(char character);

        /**
         * @brief Verify if character is a blank character (' ')
         * 
         * @param character 
         * @return true 
         * @return false 
         */
        static bool isBlank(char character);

        /**
         * @brief Transforms alphabetic character from uppercase to lowercase. If alphabetic character is lowercase or not alphabetic, the caracter will not be modified
         * 
         * @param character 
         * @return char Character modified from uppercase to lowercase
         */
        static char toLowerCase(char character);

        /**
         * @brief Transforms alphabetic character from lowercase to uppercase. If alphabetic character is uppercase or not alphabetic, the caracter will not be modified
         * 
         * @param character 
         * @return char Character modified from lowercase to uppercase
         */
        static char toUpperCase(char character);
};

#endif