#pragma once

#ifndef ID_VERIFIER_HPP
#define ID_VERIFIER_HPP

#include <string_view>

class IdVerifier {
    public:
        /**
         * @brief Verify if ecuatorian id is valid
         * 
         * @param id Series of numbers consisting of 10 digits
         * @return true If is a valid id
         * @return false If not is a valid id
         */
        static bool ecuatorian(std::string_view id);
};

#endif