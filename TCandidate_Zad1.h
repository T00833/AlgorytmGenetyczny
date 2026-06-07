#pragma once

#include "TCandidate.h"

class TCandidate_Zad1 : public TCandidate
{
public:
	TCandidate_Zad1() : TCandidate() {}
	TCandidate_Zad1(const TCandidate_Zad1& original) : TCandidate(original) {}

	void rate()
	{
		double x1 = genotype[0].get_val();
		double x2 = genotype[1].get_val();

		mark = 2 * (x1 + x2);
	}
};