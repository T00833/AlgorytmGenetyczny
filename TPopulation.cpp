#include <iostream>
#include <algorithm>


#include "TPopulation.h"

using namespace std;

unsigned int TPopulation::population_count = 0;

TPopulation::TPopulation(unsigned int candidate_count, TCandidate* pattern) : candidate_count{ candidate_count }
{
    _id = population_count;
    population_count++;

    this->candidate_count = candidate_count;

    for (unsigned int i = 0; i < candidate_count; i++) candidates.push_back(pattern->create());
}

TPopulation::TPopulation(const TPopulation& original) : candidate_count { original.get_candidates_count() }, best_val { original.get_best_val() }
{
    _id = population_count;
    population_count++;

    for (unsigned int i = 0; i < candidate_count; i++)
    {
        const TCandidate* wsk_os_org = original.get_candidate_wsk(i);
        candidates.push_back(wsk_os_org->clone());

        //cout << "Liczba osobnikow: " << candidates.size() << endl;
    }
}

TPopulation::~TPopulation()
{
    for (int i = 0; i < candidates.size(); i++)
    {
        delete candidates[i];
        //cout << "\n\nUsunieto candidate #" << i << " z Populacji #" << _id << "\n\n";
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
		candidates[i]->rate();
        double val = candidates[i]->get_mark();

        if (i == 0) best_val = val;
        else        best_val = max(best_val, val);
	}

    this->best_val = best_val;
}

TCandidate* TPopulation::get_best_candidate()
{
    int i = 0;

    while (candidates[i]->get_mark() != best_val) i++;

    return candidates[i];
}

void TPopulation::info()
{
    cout << "\n\n";
    cout << "----- POPULATION #" << _id << " -----\n";

    for (int i = 0; i < candidate_count; i++)
    {
        cout << "== candidate#" << i << ": " << candidates[i]->get_mark() << "\n";
    }
    cout << "============================\n\n";
}

void TPopulation::info_best()
{
    unsigned int i = 0;
    while (candidates[i]->get_mark() != best_val) i++;
    cout << "BEST: candidate#" << i;
    candidates[i]->info();
}

void TPopulation::choose_candidates()
    {
        int no, t, r;        


        do
        {
            cout << "Ile typow osobnikow chcesz dodac? (max 3) ";
            cin >> r;
            cout << endl;
        } while (r < 0 && r > 3);

        for (int j = 0; j < r; j++)
        {

            do
            {
                cout << "Ktory osobnik [1-3]: ";
                cin >> t;
                cout << endl;
            } while (t < 1 || t > 3);

            do
            {
                cout << "Ilu osobnikow utworzyc? ";
                cin >> no;
                cout << endl;
            } while (no < 1);

            candidate_count += no;

            switch (t)
            {
            case 1:
                for (int i = 0; i < no; i++) candidates.push_back(new TCandidate_Zad1{});
                break;
            case 2:
                for (int i = 0; i < no; i++) candidates.push_back(new TCandidate_Zad2{});
                break;
            case 3:
                for (int i = 0; i < no; i++) candidates.push_back(new TCandidate_Zad3{});
                break;
            default:
                for (int i = 0; i < no; i++) candidates.push_back(new TCandidate_Zad1{});
                break;
            }
        }
    }

const TCandidate* TPopulation::get_candidate_wsk(int _id) const
{
    const TCandidate* wsk = candidates[_id];
    return wsk;
}