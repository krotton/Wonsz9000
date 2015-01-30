// Input - manages input events.

#pragma once

#include "essentials.hpp"


namespace wonsz9000
{
    class Input
    {
    public:
		// Register handler functions for ASCII or special keys.
        void add_handler(
            unsigned char const key,
			std::function<void(unsigned char const key)> const up_func);
        void add_special_handler(
            std::vector<int> const keys,
			std::function<void(int const key)> const up_func);

		// Execute an appropriate handler function.
		void handle_up(unsigned char const ascii_key) const;
		void handle_special_up(int const special_key) const;

	private:
		// ASCII key handlers:
		std::map<unsigned char, std::function<void(unsigned char const key)>> ascii_handlers_;

		// Special key handlers:
		std::map<int, std::function<void(int const key)>> special_handlers_;
    };
}

