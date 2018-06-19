#pragma once

class Arrangements {
public:
	Arrangements();

	Arrangements(std::string thenames);

	std::vector<std::string> panel_shuffles(int n);

	std::vector<std::string> dinner_shuffles(int n);

	double panel_count(int n);

	double dinner_count(int n);

private:
	std::string m_names;

	void generate_panel_shuffles(
		const std::string & names,
		const int guest_idx,
		std::string & shuffle,
		std::vector<std::string> & shuffle_list);

	void generate_dinner_shuffles(
		const std::string & names,
		const int guest_idx,
		std::string & shuffle,
		std::vector<std::string> & shuffle_list);

	int calculate_left_index(const int idx, const int n) const;
	int calculate_right_index(const int idx, const int n) const;
};

