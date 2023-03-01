#pragma once

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

class Keyboard {
    public:
        enum Key : const unsigned int {
            backspace = 8,
            enter = 13,
            escape = 27,
            espace = 32,
            up = 328,
            left = 331,
            right = 333,
            down = 336
        };

        /**
         * @brief Returns ascii code of key pressed on keyboard
         * 
         * @return int Ascii code of key pressed
         */
        static int readKey();

        /**
         * @brief Returns the state of buffer if has pressed a key
         * 
         * @return true If has pressed a key
         * @return false If not has pressed a key
         */
        static bool hasPressedkey();
};

#endif