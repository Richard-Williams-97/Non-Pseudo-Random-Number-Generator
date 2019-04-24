#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

/* This program is an attempt to make a non pseudo random number generator
 *
 * authors: richard Williams
 */

/*
*this Random number generator will give a random number [0, 99] everytime it is called
*/
int random()
{
	bool* bits = new bool[16];
	for (int i = 0; i < 16; i++)
	{
		//gets pseudo random seed
		auto start = high_resolution_clock::now();
		auto finish = high_resolution_clock::now();
		int number = abs((int)(duration_cast<nanoseconds>(finish - start).count()));

		//makes array of 0s and 1s
		bits[i] = number % 2;
	}

	int decimal = 0;
	for (int i = 16; i > 0; i--)
	{
		//converts to decimal
		decimal = (int)(decimal + bits[i] * pow(2, 16 - i));
	}


	delete[] bits;
	return decimal %= 100; //edit to change range
}

int main() 
{
	for (int i = 0; i < 10; i++)
	{
		int test = random();
		cout << test << endl;
	}
	system("pause");
}


