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

	int calculate_left_index(const bool circular_table, const int idx, const int n) const;
	int calculate_right_index(const bool circular_table, const int idx, const int n) const;

	bool is_present(
		const std::string & shuffle,
		const std::vector<std::string> & shuffle_list);


	std::vector<std::string> generate_shuffles(
		const bool circular_table,
		const int num_guests);

	void generate_shuffles(
		const bool circular_table,
		const std::string & names,
		const int guest_idx,
		std::string & shuffle,
		std::vector<std::string> & shuffle_list);
};

