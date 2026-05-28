#include "TKlasa.h"
#include <iostream>

using namespace std;

unsigned int TKlasa::count = 0;
unsigned int TKlasa::vector_size = 5;

TKlasa::TKlasa(int init_val)
{
	TKlasa::count += 1;
	_id = TKlasa::count;
	//_id = this->count;

	this->init_val = init_val;
}

void TKlasa::set_vector_size(unsigned int size)
{
	vector_size = size;
	// TKlasa::vector_size = size;
}

void TKlasa::set_init_val(int init_val)
{
	this->init_val = init_val;
}

void TKlasa::info()
{
	cout << "Obiekt klasy TKlasa o numerze: " << _id << "/" << this->count << endl;
	cout << "Wartości: ";

	for (int i = 0; i < vector_size; i++)
	{
		cout << init_val + i << ", ";
	}

	cout << endl << endl;
}