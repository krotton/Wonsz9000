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
            std::string const keys,
			std::function<void(char const key)> const down_func) {}
        void add_handler(
            std::string const keys,
            std::function<void(char const key)> const press_func,
			std::function<void(char const key)> const release_func) {}
        void add_handler(
            std::vector<int> const keys,
			std::function<void(char const key)> const down_func) {}
        void add_handler(
            std::vector<int> const keys,
            std::function<void(char const key)> const press_func,
			std::function<void(char const key)> const release_func) {}

		// Execute an appropriate handler function.
		void handle_up(unsigned char const ascii_key) {}
		void handle_up(int const special_key) {}
		void handle_down(unsigned char const ascii_key) {}
		void handle_down(int const special_key) {}
    };
}

