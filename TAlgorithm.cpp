#include <iostream>
#include <random>
#include <math.h>

#include <cstring>
#include <sstream>

#include "TAlgorithm.h"

using namespace std;

static mt19937 rng(random_device{}());

TAlgorithm::TAlgorithm(TCandidate* pattern,
	unsigned int candidates_count,
	unsigned int max_population_count,
	unsigned int min_improvement_proc)
{
	this->pattern = pattern;

	stop_max_population_count = max_population_count;
	stop_min_improvement_proc = min_improvement_proc;

	wsk_population_pres = new TPopulation{ candidates_count, pattern };
}

TAlgorithm::~TAlgorithm()
{
	delete wsk_population_pres;
	wsk_population_pres = nullptr;
	delete wsk_population_prev;
	wsk_population_prev = nullptr;

	cout << "Usunieto obiekt klasy TAlgorithm";
}

void TAlgorithm::run()
{
	bool stop = false;

	while (!wsk_population_prev || !stop)
	{
		//(*wsk_population_pres).calculate();
		wsk_population_pres->calculate();

		cout << "==Population #" << wsk_population_pres->get_id();
		cout << " || best val: " << wsk_population_pres->get_best_val() << endl;

		stop = is_stop();

		if (!stop)
		{
			unsigned int candidates_count = wsk_population_pres->get_candidates_count();

			delete wsk_population_prev;
			wsk_population_prev = wsk_population_pres;
			wsk_population_pres = new TPopulation{ candidates_count, pattern };

			for (int i = 0; i < candidates_count; i++)
			{
				uniform_int_distribution <unsigned int> los(0, 100);
				if (los(rng) > 75)
				{
					unsigned int sp1 = 0, sp2 = 0;
					while (sp1 == sp2)
					{
						sp1 = wsk_population_prev->rulette();
						sp2 = wsk_population_prev->rulette();
					}
					crossbreading(sp1, sp2);
				}
			}
		}
	}
}

bool TAlgorithm::is_max_population()
{
	unsigned int _id_pres = wsk_population_pres->get_id();
	return (_id_pres == stop_max_population_count);
}

bool TAlgorithm::is_min_improvement()
{
	double best_val_pres = wsk_population_pres->get_best_val();
	double best_val_prev = wsk_population_prev->get_best_val();

	int improvement = fabs(best_val_prev - best_val_pres) / best_val_prev * 100;
	return (improvement <= stop_min_improvement_proc);
}

bool TAlgorithm::is_stop()
{
	bool stop = false;

	if (!wsk_population_prev) // rozpatrywana pierwsza populacja
	{
		stop = is_max_population();
	}
	else
	{
		bool stop_case1 = is_max_population();
		bool stop_case2 = is_min_improvement();
		stop = stop_case1 || stop_case2;
		// cout << "stop_case1: " << stop_case1 << endl;
		// cout << "stop_case2: " << stop_case2 << endl;
	}

	// cout << "stop: " << stop << endl;
	return stop;
}

string TAlgorithm::double2bin(double num)
{
	uint64_t bits;
	memcpy(&bits, &num, 8);

	string results = "";
	for (int i = 63; i >= 0; i--)
	{
		results += ((bits >> i) & 1) ? '1' : '0';
	}
	return results;
}

double TAlgorithm::bin2double(string binary)
{
	uint64_t bits = 0;
	for (char c : binary)
	{
		bits = bits * 2 + (c - '0');
	}
	double results;
	memcpy(&results, &bits, 8);
	return results;
}

void TAlgorithm::crossbreading(unsigned int sp1, unsigned int sp2)
{
	string p, g_p1, g_p2, out_gp1, out_gp2;
	vector <int>  l_p1, l_p2;
	unsigned int s1 = 0, s2 = 0;
	int g_count[2];
	g_count[0] = wsk_population_prev->candidates[sp1]->get_gens_count();
	g_count[1] = wsk_population_prev->candidates[sp2]->get_gens_count();

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < g_count[i]; j++)
		{
			switch (i + 1)
			{
			case 1:
				p = double2bin(wsk_population_prev->candidates[sp1]->get_gen_val(j));
				g_p1 += double2bin(wsk_population_prev->candidates[sp1]->get_gen_val(j));
				l_p1.push_back(p.length());
				s1 += p.length();
				break;
			case 2:
				p = double2bin(wsk_population_prev->candidates[sp2]->get_gen_val(j));
				g_p2 += double2bin(wsk_population_prev->candidates[sp2]->get_gen_val(j));
				l_p2.push_back(p.length());
				s2 += p.length();
				break;
			}
		}
	}
	
	uniform_int_distribution <unsigned int> los(1, s1 - 1);
	int cr_1 = los(rng);
	 // Zakladam, ze przeciecie jest za indeksem cr

	out_gp1 = g_p1.substr(0, cr_1) + g_p2.substr(cr_1);
	out_gp2 = g_p2.substr(0, cr_1) + g_p1.substr(cr_1);

	TCandidate* child1 = wsk_population_prev->candidates[sp1]->create();
	TCandidate* child2 = wsk_population_prev->candidates[sp2]->create();

	int prev_id = 0;
	for (int i = 0; i < 2; i++)
	{
		prev_id = 0;
		for (int j = 0; j < g_count[i]; j++)
			switch (i + 1)
			{
			case 1:
				child1->genotype[j].set_val(bin2double(out_gp1.substr(prev_id, l_p1[j])));
				prev_id += l_p1[j];
				break;
			case 2:
				child2->genotype[j].set_val(bin2double(out_gp2.substr(prev_id, l_p2[j])));
				prev_id += l_p2[j];
				break;
			}
	}

	wsk_population_pres->candidates.push_back(child1);
	wsk_population_pres->candidates.push_back(child2);

	cout << "Osobnik #" << sp1 << "skrzyzowal sie z osobnikiem #" << sp2 << "!\n\n";
}
