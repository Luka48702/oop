#pragma once
#include <vector>
#include <iostream>

class Player{
	int points;
	int guess;
	int choice;
	bool win;

public:
		Player() {
		points = 0;
		guess = 0;
		choice = 0;
		win = false;
	}

	int get_points() { 
		return points; 
	}
	int get_guess() { 
		return guess; 
	};
	int get_choice() { 
		return choice; 
	};
	bool get_winner() { 
		return win; 
	}

	void set_points(int num){ 
		points = num; 
	}
	void set_guess(const int num) { 
		guess = num; 
	}
	void set_choice(const int num) { 
		guess = num; 
	}
	void set_winner(const bool flag) { 
		win = flag;
	}
};