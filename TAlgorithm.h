#pragma once

#include "TPopulation.h"

class TAlgorithm
{
	unsigned int stop_max_population_count;
	unsigned int stop_min_improvement_proc;

	TCandidate* pattern = nullptr;
	TPopulation* wsk_population_pres = nullptr;
	TPopulation* wsk_population_prev = nullptr;

public:
	TAlgorithm(TCandidate* pattern,
		unsigned int candidates_count = 10,
		unsigned int max_population_count = 20,
		unsigned int min_improvement_proc = 3);

	~TAlgorithm();

	void run();

private:
	bool is_stop();
	bool is_max_population();
	bool is_min_improvement();
};