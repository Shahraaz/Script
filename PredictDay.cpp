//Optimise
#include <bits/stdc++.h>
using namespace std;

int main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	auto i = uniform_int_distribution<int>(0, 2)(rng);
	cout << "Your Suggested Physical Activity: \n";
	if (i < 2)
		cout << "Gym\n";
	else
		cout << "Cycling\n";
	i = uniform_int_distribution<int>(0, 2)(rng);
	cout << "\nSuggested Course: \n";
	if (i == 0)
		cout << "AndrewNG\n";
	else if (i == 1)
		cout << "Python Udemy\n";
	else
		cout << "Youtube Guy Notes\n";
	cout << "\n";
	cout.flush();
	// vector<int> Phy(3), Data(3);
	// for (int j = 0; j < 10000000; ++j)
	// {
	// 	i = uniform_int_distribution<int>(0, 3)(rng);
	// 	if (i <= 1)
	// 		Phy[0]++;
	// 	else
	// 		Phy[i - 1]++;
	// 	i = uniform_int_distribution<int>(0, 2)(rng);
	// 	Data[i]++;
	// }
	// cout << Phy[0] << ' ' << Phy[1] << ' ' << Phy[2] << '\n';
	// cout << Data[0] << ' ' << Data[1] << ' ' << Data[2] << '\n';
	system("pause");
	return 0;
}