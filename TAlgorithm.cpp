#include <iostream>
#include <math.h>

#include "TAlgorithm.h"

using namespace std;

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

int TAlgorithm::bin2dec(long long num)
{
	int dec, r, i = 0;

	while (num != 0)
	{
		r = num % 10;
		num /= 10;
		dec += r * pow(2, i);
		++i;
	}

	return dec;
}

long long TAlgorithm::dec2bin(int num)
{
	long long bin = 0;
	int r, i = 1;

	while (num != 0)
	{
		r = num % 2;
		num /= 2;
		bin += r * i;
		i *= 10;
	}

	return bin;
}

void TAlgorithm::crossbreading(unsigned int s1, unsigned int s2)
{
	srand(time(0));

	string p, g_p1, g_p2, out_gp1, out_gp2;
	vector <int>  l_p1, l_p2;
	int g_count[2], s1 = 0, s2 = 0;
	g_count[0] = wsk_population_pres->candidates[s1]->get_gens_count();
	g_count[1] = wsk_population_pres->candidates[s2]->get_gens_count();

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < g_count[i]; j++)
		{
			switch (i + 1)
			{
			case 1:
				p = to_string(dec2bin(wsk_population_pres->candidates[s1]->get_gen_val(j)));
				g_p1 += to_string(dec2bin(wsk_population_pres->candidates[s1]->get_gen_val(j)));
				l_p1.push_back(p.length());
				s1 += p.length();
				break;
			case 2:
				p = to_string(dec2bin(wsk_population_pres->candidates[s2]->get_gen_val(j)));
				g_p2 += to_string(dec2bin(wsk_population_pres->candidates[s2]->get_gen_val(j)));
				l_p2.push_back(p.length());
				s2 += p.length();
				break;
			}
		}
	}


	int cr_1 = rand() % (s1 - 1) + 1;
	 // Zakladam, ze przeciecie jest za indeksem cr

	out_gp1 = g_p1.substr(0, cr_1) + g_p2.substr(cr_1);
	out_gp2 = g_p2.substr(0, cr_1) + g_p1.substr(cr_1);

	TCandidate* child1 = wsk_population_pres->candidates[s1]->create();
	TCandidate* child2 = wsk_population_pres->candidates[s2]->create();

	int prev_id = 0;
	for (int i = 0; i < 2; i++)
	{
		prev_id = 0;
		for (int j = 0; j < g_count[i]; j++)
			switch (i + 1)
			{
			case 1:
				child1->genotype[j].set_val(stod(out_gp1.substr(prev_id, l_p1[j] - 1)));
				prev_id = l_p1[j];
				break;
			case 2:
				child2->genotype[j].set_val(stod(out_gp2.substr(prev_id, l_p2[j] - 1)));
				prev_id = l_p2[j];
				break;
			}
	}

	wsk_population_pres->candidates.push_back(child1);
	wsk_population_pres->candidates.push_back(child2);
}
