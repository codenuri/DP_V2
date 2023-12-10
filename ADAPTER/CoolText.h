#pragma once
#include <iostream>
#include <string>

class CoolText 
{
	std::string text;
	std::string font_name;
	std::size_t font_size;
	// ...... 	
public:
	CoolText(const std::string& text) 
			: text(text) 
	{		
	}

	void show() { std::cout << text << std::endl;}
};