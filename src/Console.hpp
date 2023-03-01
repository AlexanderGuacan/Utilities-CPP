#pragma once

#ifndef CONSOLE_HPP
#define CONSOLE_HPP

class Console {
    public:
        enum Color : unsigned int {
            black,
            red,
            green,
            yellow,
            blue,
            magenta,
            cyan,
            white,
            gray,
            brightRed,
            brightGreen,
            brightYellow,
            brightBlue,
            brightMagenta,
            brightCyan,
            brightWhite
        };

        /**
         * @brief Allows consoles like cmd to identify the ansi code (an only call of this function is necessary for activate this behavior), if the console where the other functions of this class are going to be executed are powershell, calling this function is not necessary.
         */
        static void enableANSICode();

        /**
         * @brief Save the row and column value of current cursor position
         * 
         */
        static void saveCursorPosition();

        /**
         * @brief Set cursor position in the last save cursor position, if wasn't save cursor position before, default values are row = 0 and column = 0
         * 
         */
        static void restoreCursorPosition();

        /**
         * @brief Set the cursor position
         * 
         * @param row value between 0 and rows of current console window
         * @param column value between 0 and columns of current console window
         */
        static void setCursorPosition(short row, short column);

        /**
         * @brief Enables or disables the visibility of cursor on console
         * 
         * @param on True = show cursor, False = hide cursor
         */
        static void cursorVisibility(bool on);

        /**
         * @brief Changes the color of the text in the foreground but without affecting the text already printed
         * 
         * @param color Enumerate Color (8 bit)
         */
        static void textForegroundColor(Color color);

        /**
         * @brief Changes the color of the text in the background but without affecting the text already printed
         * 
         * @param color Enumerate Color (8 bit)
         */
        static void textBackgroundColor(Color color);

        /**
         * @brief Cleans all text printed on console and set cursor position on row = 0 and column = 0
         * 
         */
        static void clearScreen();

        /**
         * @brief Cleans the line on current position of cursor and set cursor position on row = current row and column = 0
         * 
         */
        static void clearLine();

        /**
         * @brief Cleans specified line on parameter but not modified current cursor position
         * 
         * @param row Line to clean
         */
        static void clearLine(short row);

        /**
         * @brief Moves the cursor up n rows from the current one. The position of its column is maintained
         * 
         * @param positions Rows that cursor moves to the up
         */
        static void moveUpCursor(const short positions = 1);


        /**
         * @brief Moves the cursor down n rows from the current one. The position of its column is maintained
         * 
         * @param positions Rows that cursor moves to the down
         */
        static void moveDownCursor(const short positions = 1);

        /**
         * @brief Moves the cursor n columns to the right within the column you are currently in.
         * 
         * @param positions Columns that cursor moves to the right
         */
        static void moveForwardCursor(const short positions = 1);

        /**
         * @brief Moves the cursor n columns to the left within the column you are currently in.
         * 
         * @param positions Columns that cursor moves to the left
         */
        static void moveBackwardCursor(const short positions = 1);

        /**
         * @brief Changes the size of console window
         * 
         * @param rows Maximum rows visible in the console window
         * @param columns Maximum columns visible in the console window
         */
        static void resize(const short rows, const short columns);

        /**
         * @brief Pauses program execution for a specified period of time
         * 
         * @param milliseconds Wait time
         */
        static void wait(short milliseconds);

        /**
         * @brief Pause execution of program until press any key
         * 
         */
        static void pause();
};

#endif