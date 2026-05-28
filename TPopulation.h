#pragma once
#include "TCandidate.h"
#include <vector>

class TPopulation
{
	//unsigned int id;
	unsigned int candidate_count;
	std::vector<TCandidate> candidates;
	double best_val = 0.0;

public:
	TPopulation(unsigned int candidate_count);

	void calculate();
	// std::vector<TCandidate> quicksort(std::vector<TCandidate> t, int l, int p);
	TCandidate get_best_candidate();
	void info();
	void info_best();
};