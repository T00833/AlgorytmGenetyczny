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
        candidates.push_back(new TCandidate{});
	}
}

TPopulation::TPopulation(const TPopulation& original) : candidate_count { original.candidate_count }
{
    _id++;
    for (unsigned int i = 0; i < candidate_count; i++)
    {
        const TCandidate* wsk_os_org = original.get_candidate_wsk(i);
        TCandidate copy{ *wsk_os_org };
        candidates.push_back(&copy);
    }
}

TPopulation::~TPopulation()
{
    for (int i = 0; i < candidates.size(); i++)
    {
        delete candidates[i];
        cout << "\n\nUsunieto candidate #" << i << " z Populacji #" << _id << "\n\n";
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
        cout << "\n\n";
        do
        {
            cout << "Ilu osobnikow utworzyc? ";
            cin >> no;
            cout << endl;
        } while (no < 1);

        do
        {
            cout << "Czy osobnicy beda rozni czy tacy sami?\n 1->TAK\n0->NIE\n ";
            cin >> r;
            cout << endl;
        } while (r != 0 && r != 1);

        switch (r)
        {
            case 0:
                do
                {
                    cout << "Ktory osobnik [0-2]: ";
                    cin >> t;
                    cout << endl;
                } while (t < 0 || t > 2);

                switch (t)
                {
                    case 0:
                        for(int i = 0; i < no; i++) candidates.push_back(new TCandidate{});
                        break;
                    case 1:
                        for (int i = 0; i < no; i++) candidates.push_back(new TCandidate_Zad1{});
                        break;
                    case 2:
                        for (int i = 0; i < no; i++) candidates.push_back(new TCandidate_Zad2{});
                        break;
                }
                break;

            case 1:
                for (int i = 0; i < no; i++)
                {
                    do
                    {
                        cout << "Ktory osobnik [0-2]: ";
                        cin >> t;
                        cout << endl;
                    } while (t < 0 || t > 2);

                    switch (t)
                    {
                    case 0:
                        for (int i = 0; i < no; i++) candidates.push_back(new TCandidate{});
                        break;
                    case 1:
                        for (int i = 0; i < no; i++) candidates.push_back(new TCandidate_Zad1{});
                        break;
                    case 2:
                        for (int i = 0; i < no; i++) candidates.push_back(new TCandidate_Zad2{});
                        break;
                    }

                    cout << "Dodano " << i << "/" << no << endl;
                }
                break;
        }
    }

const TCandidate* TPopulation::get_candidate_wsk(int _id) const
{
    const TCandidate* wsk = candidates[_id];
    return wsk;
}