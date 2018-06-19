// ece_201806219.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Arrangements.h"

static void f_print_shuffles(const std::vector<std::string> & shuffles)
{
	for (std::size_t i = 0; i < shuffles.size(); ++i)
		std::cout << "shuffle: " << shuffles[i]
		<< "(" << i << '/' << shuffles.size() << ")"
		<< std::endl;
}

static void f_test01()
{
	Arrangements a;

	const auto shuffles = a.panel_shuffles(3);
	f_print_shuffles(shuffles);
}


int main()
{
	f_test01();

    return 0;
}

