#pragma once
class Fibonacci
{
public:
	Fibonacci();
	~Fibonacci();

	double CalculateNth(const int n) const;

private:
	using matrix2x2 = std::array<std::array<double, 2>, 2>;

	matrix2x2 mmultiply(const matrix2x2 & a, const matrix2x2 & b) const;
	matrix2x2 mpower(const matrix2x2 & m, int n) const;
	std::string to_string(const matrix2x2 & m) const;

};

