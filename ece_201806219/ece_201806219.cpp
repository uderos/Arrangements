// ece_201806219.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Arrangements.h"
#include "Fibonacci.h"

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

	const auto shuffles = a.panel_shuffles(3);
	f_print_shuffles(shuffles);
}

static void f_test02()
{
	std::cout << "\n\n" << __FUNCTION__ << " BEGIN" << std::endl;
	Arrangements a("ABCDEFGH");

	const auto shuffles = a.dinner_shuffles(3);
	f_print_shuffles(shuffles);
}

static void f_test03()
{
	Arrangements a;
	static constexpr int MAX_N = 15;
	std::array<int, 1+MAX_N> panel_counts;
	std::array<int, 1+MAX_N> dinner_counts;

	for (int n = 1; n <= MAX_N; ++n)
	{
		const auto bshuffles = a.panel_shuffles(n);
		const auto dshuffles = a.dinner_shuffles(n);
		panel_counts.at(n) = bshuffles.size();
		dinner_counts.at(n) = dshuffles.size();
	}

	for (int n = 1; n <= MAX_N; ++n)
	{
		std::cout << " n=" << n
			<< " np=" << panel_counts.at(n)
			<< " nd=" << dinner_counts.at(n)
			<< std::endl;
	}
}

static void f_test04()
{
	Fibonacci f;
	for (int i = 0; i < 10; ++i)
	{
		const double number = f.CalculateNth(i);

		std::cout << "f_" << i << '=' << number << std::endl;
	}
}

static void f_test05()
{
	Arrangements a;
	for (int ng = 0; ng < 10; ++ng)
	{
		const auto shuffles = a.panel_shuffles(ng);
		f_print_shuffles(shuffles);

		const double counter = a.panel_count(ng);
		std::cout << " ng=" << ng << " panel_counter=" << counter << std::endl;
	}
}

int main()
{
//	f_test01();
//	f_test02();
//	f_test03();
	f_test04();
//	f_test05();

    return 0;
}

