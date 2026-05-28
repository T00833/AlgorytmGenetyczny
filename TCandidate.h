#pragma once
#include "TParam.h"

#define GENS_COUNT 2

class TCandidate
{
	TParam genotype[GENS_COUNT] = 
	{
		TParam("x1", 0, 10, 1),
		TParam("x2", 0, 10, 1)
	};

	double mark;

public:
	TCandidate();

	double get_mark() { return mark; };
	void rate();
	void info();

	bool operator<(const TCandidate& other) const { return mark < other.mark; }
	bool operator>(const TCandidate& other) const { return mark > other.mark; };

private:
	void rand_gens_val();
};