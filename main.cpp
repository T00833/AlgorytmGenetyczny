#include <iostream>
#include <vector>
//#include <cstdlib>
//#include <time.h>
//
//#include "TPopulation.h"
#include "TKlasa.h"

using namespace std;

int main()
{
	//srand(time(0));
	/*
	TParam param1(1, 4, 1, 2);
	TParam param2(10, 20, 3);
	TParam param3(0, 10, 0.5, 3.3);

	//////////////////////////////////////

	cout << "param1";
	param1.info();

	cout << "param2";
	param2.info();

	cout << "param3";
	param3.info();

	//////////////////////////////////////

	param2.set_val(100);
	param3.set_val(7.5);

	cout << "=============\n";
	cout << "AFTER\n";
	cout << "=============\n\n";

	cout << "param2";
	param2.info();

	cout << "param3";
	param3.info();

	//////////////////////////////////////

	TCandidate os1{};
	os1.rate();
	os1.info();
	*/

	/*TPopulation pop(10);

	cout << "Zaraz po utworzeniu obiektu klasy TPopulation";
	pop.info();
	cout << "\n\n";

	cout << "Po wykonaniu obliczeń";
	pop.calculate();
	pop.info();
	cout << "\n\n";
	pop.info_best();
	cout << "\n\n";*/

	//TKlasa obiekt1{-3};
	//TKlasa obiekt2{0};
	//TKlasa obiekt3{5};

	//obiekt1.info();
	//obiekt2.info();
	//obiekt3.info();

	//cout << "===========================\n\n";

	//obiekt1.set_vector_size(3);
	//obiekt3.set_init_val(2);

	//obiekt1.info();
	//obiekt2.info();
	//obiekt3.info();

	vector <TKlasa> obiekty;
	unsigned int count;

	cout << "Podaj liczbę obiektów do utworzenia: ";
	cin >> count;
	cout << endl;

	for (int i = 0; i < count; i++)
	{
		obiekty.push_back(TKlasa(i));
	}

	for (int i = 0; i < count; i++)
	{
		obiekty[i].info();
	}

	return 0;
}