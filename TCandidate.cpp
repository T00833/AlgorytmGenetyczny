#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

#include "TCandidate.h"

using namespace std;

TCandidate::TCandidate() : mark{ 0 }, gens_count{ 0 } {}

TCandidate::TCandidate(const TCandidate &original) : mark{ original.mark } {}

void TCandidate::copy_gens(const TCandidate& original)
{
	for (int i = 0; i < original.gens_count; i++)
	{
		genotype[i].set_range(original.genotype[i].get_x_start(),
			original.genotype[i].get_x_end(),
			original.genotype[i].get_dx());
		genotype[i].set_val(original.genotype[i].get_val());
	}
	gens_count = genotype.size();
}

// void TCandidate::rate()
// {
// 	double x1 = genotype[0].get_val();
// 	double x2 = genotype[1].get_val();

// 	mark = pow(x1, 2) + x2;
// }

// void TCandidate::init_vector()
// {
// 	genotype.push_back(TParam("x1", 2, 100, 1));
// 	genotype.push_back(TParam("x2", 2, 100, 1));
// }

void TCandidate::rand_gens_val()
{
	for(int i = 0; i < gens_count; i++)
	{
		genotype[i].set_rand_val();
	}
}

void TCandidate::info()
{
	cout << "\n\n";
	cout << "===============================\n";
	cout << "== gens count: " << gens_count << "\n";

	for (int i = 0; i < gens_count; i++)
	{
		cout << "== \"" << genotype[i].get_name()
			<< "\" value: " << genotype[i].get_val()
			<< "\n";
	}

	cout << "==\n";
	cout << "== rate: " << mark << "\n";
	cout << "===============================\n\n";
}