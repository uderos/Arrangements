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
	std::cout << "\n\n" << __FUNCTION__ << " BEGIN" << std::endl;
	Arrangements a;

	const auto shuffles = a.panel_shuffles(5);
	f_print_shuffles(shuffles);
}

static void f_test02()
{
	std::cout << "\n\n" << __FUNCTION__ << " BEGIN" << std::endl;
	Arrangements a;

	const auto shuffles = a.dinner_shuffles(4);
	f_print_shuffles(shuffles);
}

int main()
{
	f_test01();
	f_test02();

    return 0;
}

