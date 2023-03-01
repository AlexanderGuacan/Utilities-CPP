#pragma once

#ifndef MENU_GRAPHIC_HPP
#define MENU_GRAPHIC_HPP

#include "Console.hpp"
#include "Keyboard.hpp"
#include <vector>
#include <string>
#include <initializer_list>

class MenuGraphic {
    private:
        std::string_view m_title{};
        std::vector<std::string_view> m_options{};
        short m_optionSelected{ 1 };
        short m_row{};
        short m_column{};
        Console::Color m_unselectedOptionColor{ Console::Color::white };
        Console::Color m_selectedOptionColor{ Console::Color::green };
        Console::Color m_titleColor{ Console::Color::red };

        /**
         * @brief Print completely the menu with colors specifieds
         * 
         */
        void printMenu() const;

        /**
         * @brief Print current option selected of options with m_selectedOptionColor specified
         * 
         */
        void printSelectedOption() const;

        /**
         * @brief Update m_optionSelected, increment or decrement value if press up or down key respectively
         * 
         * @param direction Key press on the keyboard. Is only valid when press up or down key
         */
        void updateOption(Keyboard::Key direction);

    public:

        /**
         * @brief Default constructor where indicates the title and options of menu
         * 
         * @param title Title of menu
         * @param options Options of menu
         */
        MenuGraphic(std::string_view title, std::initializer_list<std::string_view> options);

        /**
         * @brief Set the position from where start print title of menu and all options
         * 
         * @param row Initial row of title
         * @param column Initial column of title
         */
        void setPosition(short row, short column);

        /**
         * @brief Set the title color text
         * 
         * @param color Color option of enumerated object of class Console
         */
        void setTitleColor(Console::Color color);

        /**
         * @brief Set the unselected option color text
         * 
         * @param color Color option of enumerated object of class Console
         */
        void setUnselectedOptionColor(Console::Color color);

        /**
         * @brief Set the selected option color text
         * 
         * @param color Color option of enumerated object of class Console
         */
        void setSelectedOptionColor(Console::Color color);

        /**
         * @brief Start to print menu and detect the input of keyboard
         * 
         * @return short Option selected, value between 1 and numbers of options specified on constructor
         */
        short play();
};

#endif