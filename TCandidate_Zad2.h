#pragma once

#include "TCandidate.h"

class TCandidate_Zad2 : public TCandidate
{
public:
	TCandidate_Zad2() : TCandidate()
	{
		set_gens_range();
		rand_gens_val();
	}

	TCandidate_Zad2(const TCandidate_Zad2& original) : TCandidate(original) {}

private:
	void set_gens_range();
};

void TCandidate_Zad2::set_gens_range()
{
	genotype[0].set_range(0, 10, 1);
	genotype[1].set_range(11, 20, 2);
}