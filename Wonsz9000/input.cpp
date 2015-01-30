// Input manager.

#include "essentials.hpp"

#include "input.hpp"

using namespace wonsz9000;


void Input::add_handler(unsigned char const key,
	std::function<void(unsigned char const key)> const up_func)
{
	ascii_handlers_.insert(
		std::make_pair(key, up_func)
	);
}

void Input::add_special_handler(std::vector<int> const keys,
	std::function<void(int const key)> const up_func)
{
	for (auto const key : keys)
	{
		special_handlers_.insert(
			std::make_pair(key, up_func)
		);
	}
}

void Input::handle_up(unsigned char const key) const
{
	try
	{
		auto func = ascii_handlers_.at(key);
		func(key);
	}
	catch (std::out_of_range const&)
	{
		// Ignore, no handler registered.
	}
}

void Input::handle_special_up(int const key) const
{
	try
	{
		auto func = special_handlers_.at(key);
		func(key);
	}
	catch (std::out_of_range const&)
	{
		// Ignore, no handler registered.
	}
}
