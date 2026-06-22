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
	double mark;
	int gens_count = 0;

public:
	std::vector<TParam> genotype;

	TCandidate();
	TCandidate(const TCandidate& original);

	virtual TCandidate* create() = 0;
	virtual TCandidate* clone() const = 0;

	void copy_gens(const TCandidate& original);
	double get_gen_val(int gen_id) const { return genotype[gen_id].get_val(); }

	double get_mark() { return mark; };
	int get_gens_count() const { return gens_count; }
	virtual void rate() = 0;
	void info();

	//bool operator<(const TCandidate& other) const { return mark < other.mark; }
	//bool operator>(const TCandidate& other) const { return mark > other.mark; };

protected:
	virtual void init_vector() = 0;
	void rand_gens_val();
};