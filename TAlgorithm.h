#pragma once

#include <string>
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

	std::string double2bin(double num);
	double bin2double(std::string binary);
	void crossbreading(unsigned int s1, unsigned int s2);

private:
	bool is_stop();
	bool is_max_population();
	bool is_min_improvement();
};