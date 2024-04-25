#pragma once
#include <iostream>
#include <string>

class Enemy_
{
	public:
		Enemy_() { std::cout << "	DEBUG: A enemy was created!" << std::endl; }
		~Enemy_() { std::cout << "	DEBUG: A enemy was destroyed!" << std::endl; }
		std::string m_name_;
	private:
	protected:
};
