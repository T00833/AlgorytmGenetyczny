#pragma once
#include "TCandidate.h"
#include <vector>

class TPopulation
{
	static unsigned int population_count;
	static unsigned int _id;
	unsigned int candidate_count;
	std::vector<TCandidate> candidates;
	double best_val = 0.0;

public:
	TPopulation(unsigned int candidate_count);
	TPopulation(const TPopulation& original);

	void calculate();
	// std::vector<TCandidate> quicksort(std::vector<TCandidate> t, int l, int p);
	TCandidate get_best_candidate();

	unsigned int get_id() { return _id; }
	unsigned int get_candidates_count() { return candidate_count; }
	double get_best_val() { return best_val; }

	void info();
	void info_best();

private:
	const TCandidate* get_candidate_wsk(int _id) const;
};