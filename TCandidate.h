#pragma once
#include <vector>
#include "TParam.h"

//#define GENS_COUNT 2

class TCandidate
{
protected:
	// TParam genotype[GENS_COUNT] = 
	// {
	// 	TParam("x1", 0, 10, 1),
	// 	TParam("x2", 0, 10, 1)
	// };
	int gens_count = 0;
	std::vector<TParam> genotype;

	double mark;

public:
	TCandidate();
	TCandidate(const TCandidate& original);
	virtual TCandidate* clone() const { return new TCandidate(*this); }

	double get_mark() { return mark; };
	virtual void rate();
	void info();

	//bool operator<(const TCandidate& other) const { return mark < other.mark; }
	//bool operator>(const TCandidate& other) const { return mark > other.mark; };

protected:
	void init_vector();
	void rand_gens_val();
	double get_gen_val(int gen_id) const { return genotype[gen_id].get_val(); }
};