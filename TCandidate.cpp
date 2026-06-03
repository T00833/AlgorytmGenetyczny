#include <iostream>
#include <math.h>

#include "TCandidate.h"

using namespace std;

TCandidate::TCandidate() : mark{ 0 }
{
	rand_gens_val();
}

TCandidate::TCandidate(const TCandidate &original) : mark{ original.mark }
{
	for (int i = 0; i < GENS_COUNT; i++)
	{
		genotype[i].set_range(original.genotype[i].get_x_start(), original.genotype[i].get_x_end(), original.genotype[i].get_dx());
		genotype[i].set_val(original.genotype[i].get_val());
	}
}

void TCandidate::rate()
{
	double x1 = genotype[0].get_val();
	double x2 = genotype[1].get_val();

	mark = pow(x1, 2) + x2;
}

void TCandidate::rand_gens_val()
{
	for(int i = 0; i < GENS_COUNT; i++)
	{
		genotype[i].set_rand_val();
	}
}

void TCandidate::info()
{
	cout << "\n\n";
	cout << "===============================\n";
	cout << "== gens count: " << GENS_COUNT << "\n";

	for (int i = 0; i < GENS_COUNT; i++)
	{
		cout << "== \"" << genotype[i].get_name()
			<< "\" value: " << genotype[i].get_val()
			<< "\n";
	}

	cout << "==\n";
	cout << "== rate: " << mark << "\n";
	cout << "===============================\n\n";
}