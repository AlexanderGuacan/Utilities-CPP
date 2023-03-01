#pragma once

#ifndef MARQUEE_HPP
#define MARQUEE_HPP

#include <string>

class Marquee {
    private:
        const std::string m_phrase{};
        const short m_row{};
        const short m_startColumn{};
        const short m_endColumn{};
        bool m_isPause{ false };
        bool m_isActive{ true };

    public:

        /**
         * @brief Constructor
         * 
         * @param phrase String to print on console
         * @param row Row where the phrase will be placed
         * @param startColumn Column from which to start printing the phrase
         * @param spacesFromEndCharacter Number of positions that the message will move to the right and where the message will start to disappear
         */
        Marquee(const std::string_view phrase, short row = 0, short startColumn = 0, short spacesFromEndCharacter = 10);

        /**
         * @brief Starts loop to print phrase
         * 
         */
        void print();

        /**
         * @brief Pauses loop to print phrase. This function only can call when use threads
         * 
         */
        void pause();

        /**
         * @brief Resumes loop to print phrase. This function only can call when use threads
         * 
         */
        void resume();

        /**
         * @brief Stops loop to print phrase. This function only can call when use threads
         * 
         */
        void stop();
};

#endif