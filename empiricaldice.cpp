/*jamie farhi-humphrey
//This program will tell you the average of rolling x y-sided dice and dropping the z lowest
//The math was hard, so it does it empirically (it rolls a million sets of X Y-sided dice, 
	sums the highest (x-z) and delivers the average over a million
	*/

#include <iostream>
#include <vector>
//#include <random>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	int ximes, yides, zrop, value, ind;
	float settally;
	vector <int> rolls;
	srand(time(NULL));
	
	cout << "Number? ";
	cin >> ximes;
	cout << "Sides? ";
	cin >> yides;
	cout << "Dropping how many? ";
	cin >> zrop;
	while(zrop>=ximes)
	{
		cout <<"Error: Cannot drop more than you roll. Please remedy: ";
		cin >> zrop;
	}
	
	settally=0;
	rolls.resize(ximes);
	for (int i=0; i<1000000; i++) {
		for (ind=0; ind<ximes; ind++)
		{
			rolls[ind] = (rand() % yides) +1;
			//cout << rolls[ind]<< ", ";
		}
		//cout << endl;	
		sort(rolls.begin(), rolls.end());
	
		for (ind=0; ind<ximes; ind++)
		{
		//	cout << rolls[ind] << ", ";
		}
		for (ind=zrop; ind<ximes; ind++) settally+=rolls[ind];
		
	
		//cout << endl;
		//for (vector<int>::iterator it = rolls.begin(); it != rolls.end(); it++) std::cout << *it << ", ";
	}
	settally=settally/1000000;
	value=floor(log10 (settally))+1;
	cout<< "Average: "<< setprecision(value+2) << settally;
	return 0;
	}
