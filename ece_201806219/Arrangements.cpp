#include "stdafx.h"
#include "Arrangements.h"
#include "Fibonacci.h"

static constexpr char EMPTY_SEAT_CHAR = '#';

Arrangements::Arrangements()
{
	// Create default names
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
	const bool circular_table = false;

	return generate_shuffles(circular_table, n);
}

std::vector<std::string> Arrangements::dinner_shuffles(int n)
{
	const bool circular_table = true;

	return generate_shuffles(circular_table, n);
}

double Arrangements::panel_count(int n)
{
	Fibonacci f;
	const double counter = f.CalculateNth(1 + n);
	return counter;
}

// TODO - Still not implemented
double Arrangements::dinner_count(int n)
{
	double counter = 0.0;
	return counter;
}

int Arrangements::calculate_left_index(
	const bool circular_table, 
	const int idx, 
	const int n) const
{
	int left_idx = idx - 1;

	if (circular_table && left_idx < 0)
		left_idx += n;

	return left_idx;
}

int Arrangements::calculate_right_index(
	const bool circular_table, 
	const int idx, 
	const int n) const
{
	int right_idx = idx + 1;

	if (circular_table && right_idx > n - 1)
		right_idx -= n;

	return right_idx;
}

bool Arrangements::is_present(
	const std::string & shuffle,
	const std::vector<std::string> & shuffle_list)
{
	const auto it = std::find(shuffle_list.begin(), shuffle_list.end(), shuffle);
	return (it != shuffle_list.end());
}

std::vector<std::string> Arrangements::generate_shuffles(
	const bool circular_table,
	const int num_guests)
{
	if (num_guests >= m_names.size())
		throw num_guests;

	const std::string names = m_names.substr(0, num_guests);
	const int guest_idx = 0;
	std::string shuffle(num_guests, EMPTY_SEAT_CHAR);
	std::vector<std::string> shuffle_list;

	generate_shuffles(circular_table, names, guest_idx, shuffle, shuffle_list);

	return shuffle_list;
}

void Arrangements::generate_shuffles(
	const bool circular_table,
	const std::string & names,
	const int guest_idx,
	std::string & shuffle,
	std::vector<std::string> & shuffle_list)
{
	const int num_guests = names.size();

	if (guest_idx == num_guests)
	{	// Everybody is sitting ... we are done !
		if (!is_present(shuffle, shuffle_list))
		{
			DBG_OUT << __FUNCTION__
				<< " i=" << guest_idx
				<< " s=" << shuffle
				<< " ADDING " << shuffle << std::endl;
			shuffle_list.push_back(shuffle);
		}
		return;
	}

	// The guest does not move (she/he sits back in his original chair)
	if (shuffle[guest_idx] == EMPTY_SEAT_CHAR)
	{
		DBG_OUT << __FUNCTION__
			<< " i=" << guest_idx
			<< " s=" << shuffle
			<< ' ' << names[guest_idx] << " stays " << std::endl;
		// Sit, let the other guests find a chair and stand up again
		shuffle[guest_idx] = names[guest_idx];
		generate_shuffles(circular_table, names, 1 + guest_idx, shuffle, shuffle_list);
		shuffle[guest_idx] = EMPTY_SEAT_CHAR;
	}

	// The guest moves left and sits
	const int left_idx = calculate_left_index(circular_table, guest_idx, num_guests);
	if ((left_idx >= 0) && (shuffle[left_idx] == EMPTY_SEAT_CHAR))
	{
		DBG_OUT << __FUNCTION__
			<< " i=" << guest_idx
			<< " s=" << shuffle
			<< ' ' << names[guest_idx] << " moves left to " << left_idx << std::endl;
		// Sit, let the other guests find a chair and stand up again
		shuffle[left_idx] = names[guest_idx];
		generate_shuffles(circular_table, names, 1 + guest_idx, shuffle, shuffle_list);
		shuffle[left_idx] = EMPTY_SEAT_CHAR;
	}

	// The guest moves right and sits
	const int right_idx = calculate_right_index(circular_table, guest_idx, num_guests);
	if ((right_idx < num_guests) && (shuffle[right_idx] == EMPTY_SEAT_CHAR))
	{
		DBG_OUT << __FUNCTION__
			<< " i=" << guest_idx
			<< " s=" << shuffle
			<< ' ' << names[guest_idx] << " moves right to " << right_idx << std::endl;
		// Sit, let the other guests find a chair and stand up again
		shuffle[right_idx] = names[guest_idx];
		generate_shuffles(circular_table, names, 1 + guest_idx, shuffle, shuffle_list);
		shuffle[right_idx] = EMPTY_SEAT_CHAR;
	}
}

