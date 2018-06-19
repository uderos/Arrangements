#include "stdafx.h"
#include "Arrangements.h"

static const char EMPTY_SEAT = '#';

Arrangements::Arrangements()
{
	for (char c = 'a'; c <= 'z'; ++c)
		m_names.push_back(c);
	for (char c = 'A'; c <= 'Z'; ++c)
		m_names.push_back(c);
}

Arrangements::Arrangements(std::string thenames)
{
	m_names = thenames;
}

std::vector<std::string> Arrangements::panel_shuffles(int n)
{
	// TODO: be sure n < m_names.size()
	const std::string names = m_names.substr(0, n);
	const int guest_idx = 0;
	std::string shuffle(n, EMPTY_SEAT);
	std::vector<std::string> shuffle_list;

	generate_panel_shuffles(names, guest_idx, shuffle, shuffle_list);

	return shuffle_list;
}

std::vector<std::string> Arrangements::dinner_shuffles(int n)
{
	// TODO: be sure n < m_names.size()
	const std::string names = m_names.substr(0, n);
	const int guest_idx = 0;
	std::string shuffle(n, EMPTY_SEAT);
	std::vector<std::string> shuffle_list;

	generate_dinner_shuffles(names, guest_idx, shuffle, shuffle_list);

	return shuffle_list;
	return shuffle_list;
}

double Arrangements::panel_count(int n)
{
	double counter = 0.0;
	return counter;
}

double Arrangements::dinner_count(int n)
{
	double counter = 0.0;
	return counter;
}

void Arrangements::generate_panel_shuffles(
	const std::string & names,
	const int guest_idx,
	std::string & shuffle,
	std::vector<std::string> & shuffle_list)
{
	if (guest_idx == names.size())
	{
		std::cout << __FUNCTION__ 
			<< " i=" << guest_idx
			<< " s=" << shuffle
			<< " ADDING " << shuffle << std::endl;
		shuffle_list.push_back(shuffle);
		return;
	}

	// The guest does not move
	if (shuffle[guest_idx] == EMPTY_SEAT)
	{
		std::cout << __FUNCTION__
			<< " i=" << guest_idx
			<< " s=" << shuffle
			<< " stays " << std::endl;
		shuffle[guest_idx] = names[guest_idx];
		generate_panel_shuffles(names, 1 + guest_idx, shuffle, shuffle_list);
		shuffle[guest_idx] = EMPTY_SEAT;
	}

	// The guest moves left
	if ((guest_idx > 0) && (shuffle[guest_idx - 1] == EMPTY_SEAT))
	{
		std::cout << __FUNCTION__
			<< " i=" << guest_idx
			<< " s=" << shuffle
			<< " left move " << std::endl;
		shuffle[guest_idx - 1] = names[guest_idx];
		generate_panel_shuffles(names, 1 + guest_idx, shuffle, shuffle_list);
		shuffle[guest_idx - 1] = EMPTY_SEAT;
	}

	// The guest moves right
	if ((guest_idx < names.size() - 1) && (shuffle[guest_idx + 1] == EMPTY_SEAT))
	{
		std::cout << __FUNCTION__
			<< " i=" << guest_idx
			<< " s=" << shuffle
			<< " right move " << std::endl;
		shuffle[guest_idx + 1] = names[guest_idx];
		generate_panel_shuffles(names, 1 + guest_idx, shuffle, shuffle_list);
		shuffle[guest_idx + 1] = EMPTY_SEAT;
	}

}

int Arrangements::calculate_left_index(const int idx, const int n) const
{
	return (idx == 0 ? n - 1 : idx - 1);
}

int Arrangements::calculate_right_index(const int idx, const int n) const
{
	return (idx == n - 1 ? 0 : idx + 1);
}


void Arrangements::generate_dinner_shuffles(
	const std::string & names,
	const int guest_idx,
	std::string & shuffle,
	std::vector<std::string> & shuffle_list)
{
	if (guest_idx == names.size())
	{
		std::cout << __FUNCTION__
			<< " i=" << guest_idx
			<< " s=" << shuffle
			<< " ADDING " << shuffle << std::endl;
		shuffle_list.push_back(shuffle);
		return;
	}

	// The guest does not move
	if (shuffle[guest_idx] == EMPTY_SEAT)
	{
		std::cout << __FUNCTION__
			<< " i=" << guest_idx
			<< " s=" << shuffle
			<< ' ' << names[guest_idx] << " stays " << std::endl;
		shuffle[guest_idx] = names[guest_idx];
		generate_dinner_shuffles(names, 1 + guest_idx, shuffle, shuffle_list);
		shuffle[guest_idx] = EMPTY_SEAT;
	}

	// The guest moves left
	const int left_idx = calculate_left_index(guest_idx, names.size());
	if (shuffle[left_idx] == EMPTY_SEAT)
	{
		std::cout << __FUNCTION__
			<< " i=" << guest_idx
			<< " s=" << shuffle
			<< ' ' << names[guest_idx] << " moves left to " << left_idx << std::endl;
		shuffle[left_idx] = names[guest_idx];
		generate_dinner_shuffles(names, 1 + guest_idx, shuffle, shuffle_list);
		shuffle[left_idx] = EMPTY_SEAT;
	}

	// The guest moves right
	const int right_idx = calculate_right_index(guest_idx, names.size());
	if (shuffle[right_idx] == EMPTY_SEAT)
	{
		std::cout << __FUNCTION__
			<< " i=" << guest_idx
			<< " s=" << shuffle
			<< ' ' << names[guest_idx] << " moves right to " << right_idx << std::endl;
		shuffle[right_idx] = names[guest_idx];
		generate_dinner_shuffles(names, 1 + guest_idx, shuffle, shuffle_list);
		shuffle[right_idx] = EMPTY_SEAT;
	}
}

