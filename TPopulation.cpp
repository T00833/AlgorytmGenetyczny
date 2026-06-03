#include <iostream>
#include <algorithm>


#include "TPopulation.h"

using namespace std;

unsigned int TPopulation::_id = 0;

TPopulation::TPopulation(unsigned int candidate_count) : candidate_count{ candidate_count }
{
    _id++;
	for (unsigned int i = 0; i < candidate_count; i++)
	{
        candidates.push_back(TCandidate{});
	}
}

TPopulation::TPopulation(const TPopulation& original) : candidate_count { original.candidate_count }
{
    _id++;
    for (unsigned int i = 0; i < candidate_count; i++)
    {
        const TCandidate* wsk_os_org = original.get_candidate_wsk(i);
        TCandidate copy{ *wsk_os_org };
        candidates.push_back(copy);
    }
}

//std::vector<TCandidate> TPopulation::quicksort(std::vector<TCandidate> t, int l, int p)
//{
//    TCandidate v = t[(l + p) / 2]; //wybieranie osi jako środkowy wyraz wektora
//    int i = l, j = p;
//
//    do {
//        while (t[i] > v) i++;
//        while (t[j] < v) j--;
//        if (i <= j) {
//            std::swap(t[i], t[j]);
//            i++; j--;
//        }
//    } while (i <= j);
//    if (j > l) quicksort(t, l, j);
//    if (i < p) quicksort(t, i, p);
//
//    return t;
//}

void TPopulation::calculate()
{   
    double best_val = 0.0;

	for (unsigned int i = 0; i < candidate_count; i++)
	{
		candidates[i].rate();
        double val = candidates[i].get_mark();

        if (i == 0) best_val = val;
        else        best_val = max(best_val, val);
	}

    this->best_val = best_val;
}

TCandidate TPopulation::get_best_candidate()
{
    int i = 0;

    while (candidates[i].get_mark() != best_val) i++;

    return candidates[i];
}

void TPopulation::info()
{
    cout << "\n\n";
    cout << "----- POPULATION #" << _id << " -----\n";

    for (int i = 0; i < candidate_count; i++)
    {
        cout << "== candidate#" << i << ": " << candidates[i].get_mark() << "\n";
    }
    cout << "============================\n\n";
}

void TPopulation::info_best()
{
    unsigned int i = 0;
    while (candidates[i].get_mark() != best_val) i++;
    cout << "BEST: candidate#" << i;
    candidates[i].info();
}

const TCandidate* TPopulation::get_candidate_wsk(int _id) const
{
    const TCandidate* wsk = &candidates[_id];
    return wsk;
}