#include <iostream>
#include <cmath>
#include <cstdlib>

#include "TParam.h"

using namespace std;


TParam::TParam(double x_start, double x_end, double dx) : name{""}
{
	set_range(x_start, x_end, dx);
	//name = "";
	set_rand_val();
}

TParam::TParam(double x_start, double x_end, double dx, double val) : TParam::TParam(x_start, x_end, dx)
{
	//set_range(x_start, x_end, dx);
	//name = "";
	set_val(val);
}

TParam::TParam(string name, double x_start, double x_end, double dx) : name{name}
{
	set_range(x_start, x_end, dx);
	//set_name(name);
	set_rand_val();
}

TParam::TParam(string name, double x_start, double x_end, double dx, double val) : TParam::TParam(name, x_start, x_end, dx)
{
	//set_range(x_start, x_end, dx);
	//set_name(name);
	set_val(val);
}

TParam::TParam(const TParam &original) : name{original.get_name()}
{
	double x_start = original.get_x_start();
	double x_end= original.get_x_end();
	double dx = original.get_dx();
	set_range(x_start, x_end, dx);

	double val = original.get_val();
	set_val(val);
}

void TParam::set_range(double x_start, double x_end, double dx)
{
	this->x_start = x_start;
	this->x_end = x_end;
	this->dx = dx;
}

int TParam::get_val_id(double val)
{
	if (val < x_start) return 0;

	else if (val > x_end) return (x_end - x_start) / dx;

	else
	{
		int _id = 0;

		while (fabs(x_start + _id * dx - val) > dx / 2) _id++;

		return _id;
	} 
}

void TParam::set_rand_val()
{
	int vals_count = fabs(x_end - x_start) / dx + 1;
	val_id = rand() % vals_count;
}

void TParam::info()
{
	cout << "\n";
	cout << "===============================\n";
	cout << "== name: " << name << endl;
	cout << "== range: [" << x_start << "; " << dx << "; " << x_end << "]\n";
	cout << "== value: " << get_val() << "\t (id: #" << val_id << ")\n";
	cout << "===============================\n\n";
}