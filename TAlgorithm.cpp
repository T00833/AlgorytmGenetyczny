#include <iostream>
#include <math.h>

#include "TAlgorithm.h"

using namespace std;

TAlgorithm::TAlgorithm(unsigned int candidates_count,
	unsigned int max_population_count,
	unsigned int min_improvement_proc)
{
	stop_max_population_count = max_population_count;
	stop_min_improvement_proc = min_improvement_proc;
	TCandidate_Zad2 pattern;
	wsk_population_pres = new TPopulation{ candidates_count, &pattern };
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

			// chwilowe rozwiazanie - tworzenie kolejnej losowej populacji
			TCandidate_Zad2 pattern;
			wsk_population_pres = new TPopulation{ candidates_count, &pattern };
		}

		if (wsk_population_pres->get_id() == 25) return;
	}
}

bool TAlgorithm::is_max_population()
{
	unsigned int _id_pres = wsk_population_pres->get_id();
	return (_id_pres == stop_max_population_count);
}

bool TAlgorithm::is_min_improvement()
{
	TPopulation population_pres = (*wsk_population_pres);
	TPopulation population_prev = (*wsk_population_prev);

	double best_val_pres = population_pres.get_best_val();
	double best_val_prev = population_prev.get_best_val();

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