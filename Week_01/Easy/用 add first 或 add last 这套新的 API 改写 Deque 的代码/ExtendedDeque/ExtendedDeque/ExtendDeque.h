#pragma once
#include <deque>

template <typename T>
class ExtendDeque : public std::deque<T>
{
public:
	ExtendDeque() {

	}

public:
	void add_first(T val) {
		this->push_front(val);
	}

	void add_last(T val) {
		this->push_back(val);
	}
};
