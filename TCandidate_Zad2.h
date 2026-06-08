#pragma once

#include "TCandidate.h"

class TCandidate_Zad2 : public TCandidate
{
public:
	TCandidate_Zad2() : TCandidate()
	{
		init_vector();
		set_gens_range();
	}

	TCandidate_Zad2(const TCandidate_Zad2& original) : TCandidate(original) {}

	TCandidate* create() override { return new TCandidate_Zad2(); }
	TCandidate* clone() const override { return new TCandidate_Zad2(*this); }

	void rate()
	{
		double x1 = genotype[0].get_val();
		double x2 = genotype[1].get_val();

		mark = 100 * x1 + x2;
	}
protected:
	void init_vector();
private:
	inline void set_gens_range();
};

void TCandidate_Zad2::set_gens_range()
{
	genotype[0].set_range(0, 10, 1);
	genotype[1].set_range(11, 20, 2);
}

void TCandidate_Zad2::init_vector()
{
	genotype.push_back(TParam("x1", 0, 10, 1));
	genotype.push_back(TParam("x2", 11, 20, 2));

	gens_count = genotype.size();
}