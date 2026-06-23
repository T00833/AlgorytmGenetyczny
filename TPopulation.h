#pragma once
#include "TCandidate.h"
#include "TCandidate_Zad1.h"
#include "TCandidate_Zad2.h"
#include "TCandidate_Zad3.h"
#include <vector>

class TPopulation
{
	static unsigned int population_count;
	unsigned int _id;
	unsigned int candidate_count;
	double best_val = 0.0;

public:
	std::vector<TCandidate*> candidates;

	TPopulation(unsigned int candidate_count, TCandidate* pattern);
	TPopulation(const TPopulation& original);
	~TPopulation();

	void calculate();
	// std::vector<TCandidate> quicksort(std::vector<TCandidate> t, int l, int p);
	TCandidate* get_best_candidate();

	unsigned int get_id() const { return _id; }
	unsigned int get_candidates_count() const { return candidate_count; }
	double get_best_val() const { return best_val; }
	void set_candidates_count(unsigned int b) { candidate_count = b; }

	void info();
	void info_best();

	void choose_candidates();
	unsigned int rulette();

private:
	const TCandidate* get_candidate_wsk(int _id) const;
};