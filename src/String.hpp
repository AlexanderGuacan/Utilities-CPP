#pragma once

#ifndef STRING_HPP
#define STRING_HPP

#include <string>
#include <list>

class String {
    private:
        /**
         * @brief Transforms a string with numeric characters to integer value
         * @exception Throw error when the string contains a character no numeric. Including '.'
         * @param string String with integer value
         * @return int Integer transformed from string
         */
        static int parseInteger(std::string_view string);

        /**
         * @brief Transforms a string with numeric characters to floating point value
         * @exception Throw error when the string contains a character no numeric. Excludes '.' only one time
         * @param string String with floating point value
         * @return float Floating point transformed from string
         */
        static float parseFloating(std::string_view string);
        
    public:
        /**
         * @brief Returns the numeric representation of string
         * 
         * @param string String that contains digits (0-9) or/and negative sign '-'.
         * @return float The floating value represented by the argument in decimal
         */
        static float valueOf(std::string_view string);

        /**
         * @brief Transform all characters in string to lowercase. If aren't [A-Za-z] then the characters keep same
         * 
         * @param string Any string
         * @return std::string String transformed to lowercase
         */
        static std::string toLowerCase(std::string_view string);
        /**
         * @brief Transform all characters in string to uppercase. If aren't [A-Za-z] then the characters keep same
         * 
         * @param string Any string
         * @return std::string String transformed to uppercase
         */
        static std::string toUpperCase(std::string_view string);

        /**
         * @brief Transforms the first character to upper case and the also characters to lowercase
         * 
         * @param string Word to transform to capitalize format
         * @return std::string String capitalized
         */
        static std::string capitalize(std::string_view string);

        /**
         * @brief Checks if all characters in string are digits
         * 
         * @param string Any string
         * @return true If all characters in string are digits
         * @return false If at least one the characters in string isn't digit
         */
        static bool isDigit(std::string_view string);
        
        /**
         * @brief Checks if all characters in string are alphabetics
         * 
         * @param string Any string
         * @return true If all characters in string are alphabetics
         * @return false If at least one the characters in string isn't alphabetic
         */
        static bool isAlphabetic(std::string_view string);
        
        /**
         * @brief Checks if all characters in string are alphanumerics
         * 
         * @param string Any string
         * @return true If all characters in string are alphanumerics
         * @return false If at least one the characters in string isn't alphanumeric
         */
        static bool isAlphanumeric(std::string_view string);

        /**
         * @brief Checks if all characters in string are blanks
         * 
         * @param string Any string
         * @return true If all characters in string are blanks
         * @return false If at least one the characters in string isn't blank
         */
        static bool isBlank(std::string_view string);

        /**
         * @brief Splits this string around matches of the given token
         * 
         * @param string An string to split
         * @param token Character that split strings. This token don't include in the split string
         * @return std::list<std::string> Splitted strings
         */
        static std::list<std::string> split(std::string_view string, char token);

        /**
         * @brief Returns a copy of string variable, deleting all specified character (characterToDelete) from begin of it
         * 
         * @param string Any string
         * @param characterToDelete Character match to delete from begin of string
         * @return std::string Substring deleting all matches of the character to be deleted from the beginning of the string
         */
        static std::string lstrip(std::string_view string, char characterToDelete);

        /**
         * @brief Returns a copy of string variable, deleting all specified character (characterToDelete) from end of it
         * 
         * @param string Any string
         * @param characterToDelete Character match to delete from end of string
         * @return std::string Substring deleting all matches of the character to be deleted from the ending of the string
         */
        static std::string rstrip(std::string_view string, char characterToDelete);

        /**
         * @brief Returns a copy of string variable, deleting all specified character (characterToDelete) from begin and end of it
         * 
         * @param string Any string
         * @param characterToDelete Character match to delete from begin and end of string
         * @return std::string Substring deleting all matches of the character to be deleted from the beginning and the ending of the string
         */
        static std::string strip(std::string_view string, char characterToDelete);
};

#endif