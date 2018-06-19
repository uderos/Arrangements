#include "stdafx.h"
#include "Fibonacci.h"


Fibonacci::Fibonacci()
{
}


Fibonacci::~Fibonacci()
{
}

double Fibonacci::CalculateNth(const int n) const
{
	// Utility matrix M =	[1 1
	//						 1 0]
	static constexpr matrix2x2 M{ { { { 1.0, 1.0 } },{ { 1.0, 0.0 } } } };

	// Calculate M^n
	const matrix2x2 Mn = mpower(M, n);

	return Mn[0][1];
}

std::string Fibonacci::to_string(const matrix2x2 & m) const
{
	std::ostringstream oss;
	oss << "[[" << m[0][0] << "," << m[0][1] << "],[" << m[1][0] << "," << m[1][1] << "]]";
	return oss.str();
}

// Calculates m = a * b
Fibonacci::matrix2x2 Fibonacci::mmultiply(
	const matrix2x2 & a, 
	const matrix2x2 & b) const
{
	matrix2x2 m;
	for (int r = 0; r < 2; ++r)
	{
		for (int c = 0; c < 2; ++c)
		{
			m[r][c] = 0.0;
			for (int k = 0; k < 2; ++k)
			{
				m[r][c] += (a[r][k] * b[k][c]);
			}
		}
	}
	//DBG_OUT << "mmultiply"
	//	<< " a=" << to_string(a)
	//	<< " b=" << to_string(b)
	//	<< " m=" << to_string(m)
	//	<< std::endl;
	return m;
}

// Calculates  m^n
Fibonacci::matrix2x2 Fibonacci::mpower(
	const matrix2x2 & m, 
	int n) const
{
	matrix2x2 result;

	//DBG_OUT << "mpower" << " m=" << to_string(m) << " n=" << n << std::endl;
	static constexpr matrix2x2 I{ { { { 1.0, 0.0 } },{ { 0.0, 1.0 } } } };
	if (n == 0)
	{
		result = I;
	}
	else if (n == 1)
	{
		result = m;
	}
	else
	{
		// if m size is even, then m^n = m^(n/2) * m^(n/2)
		// if m size is odd,  then m^n = m * m^(n/2) * m^(n/2)
		matrix2x2 m_n_2 = mpower(m, n / 2);
		result = mmultiply(m_n_2, m_n_2);
		if (n % 2)
			result = mmultiply(result, m); // m size is odd
	}

	return result;
}

