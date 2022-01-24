#include "Player1.h"
#include "game.h"
using namespace std;

int Player1::H_pick() {

	int num_coin;
	int selected;
	int total = 0;
	vector<int> coins = {1,2,5};
	Game g;
	cout << "Number of coins:\n";
	cin >> num_coin;
	while (num_coin > 3)
	{
		cout << "Wrong input" << endl;
		cin >> num_coin;
	}

	if (num_coin == 0)
	{
		set_choice(0);
		return total;
	}
	else
	{
		cout << "Pick your coins\n";

		for (size_t i = 0; i < num_coin; i++)
		{

			for (auto it = coins.begin(); it < coins.end(); it++)
			{
				cout << *it << " left" << endl;
			}

			while (1)
			{
				cin >> selected;
				if (selected == 1 || selected == 2 || selected == 5)
				{
					break;
				}
				else {
					cout << "Pick 1, 2 or 5" << endl;
				}
			}
			total += selected;
			auto remove_coin = find(coins.begin(), coins.end(), selected);
			coins.erase(remove_coin);
		}
		set_choice(total);
		return total;
	}
}