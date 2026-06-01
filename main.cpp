#include <iostream>
//#include <vector>
#include <cstdlib>
#include <time.h>
//
//#include "TPopulation.h"
//#include "TKlasa.h"
#include "TAlgorithm.h"

using namespace std;

int main()
{
	//srand(time(0));


	// KLASA GENU


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


	// KLASA OSOBNIK


	TCandidate os1{};
	os1.rate();
	os1.info();
	*/


	// TPOPULATION


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


	// TKLASA


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


	// TKLASA VECTOR


	//vector <TKlasa> obiekty;
	//unsigned int count;

	//cout << "Podaj liczbę obiektów do utworzenia: ";
	//cin >> count;
	//cout << endl;

	//for (int i = 0; i < count; i++)
	//{
	//	obiekty.push_back(TKlasa(i));
	//}

	//for (int i = 0; i < count; i++)
	//{
	//	obiekty[i].info();
	//}


	// DYNAMICZNE TWORZENIE OBIEKTÓW

	//TKlasa* wsk_obiekt1 = new TKlasa{ -3 };
	//TKlasa* wsk_obiekt2 = new TKlasa{ 0 };
	//TKlasa* wsk_obiekt3 = new TKlasa{ 5 };
	//TKlasa obiekt4{ -3 };
	//TKlasa obiekt5{ 2 };

	//wsk_obiekt1->info();
	//(*wsk_obiekt2).info();
	//wsk_obiekt3->info();

	//delete wsk_obiekt1;
	//wsk_obiekt1 = nullptr;
	//delete wsk_obiekt2;
	//wsk_obiekt2 = nullptr;
	//delete wsk_obiekt3;
	//wsk_obiekt3 = nullptr;

	// TALGORITHM
	srand(time(0));

	unsigned int candidates_count = 5;
	unsigned int max_population_count = 20;
	unsigned int min_improvement_proc = 2;

	TAlgorithm task{ candidates_count,
					max_population_count,
					min_improvement_proc };
	task.run();

	return 0;
}