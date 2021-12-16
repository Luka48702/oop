using namespace std;
#include <iostream>
#include <cmath>

struct Point {
	double x, y;
	Point(double x, double y);
};

class Board {
	int rows;
	int cols;
	char* board;
public:
	Board(int rows, int cols);
	void draw_char(Point p, char znak);
	void draw_up_line(Point p, char znak);
	void draw_line(Point p1, Point p2, char znak);
	void display();
	Board(const Board& b);
	~Board();
};


Board::Board(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	board = new char[rows * cols];

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			if (i == 0 || i == cols - 1 || j == 0 || j == rows - 1) {
				board[i * rows + j] = 'o';
			}
			else {
				board[i * rows + j] = ' ';
			}
		}
	}
}

void Board::draw_char(Point p, char znak) {
	int x = p.x - 1;
	int y = p.y - 1;

	if (x >= cols || y >= rows || x <= 0) {
		cout << "Velicine nisu valjane" << endl;
		return;
	}
	else {
		board[x * rows + y] = znak;
	}
}


void Board::draw_up_line(Point p, char znak) {
	int x1 = p.x - 1;
	int y1 = p.y - 1;

	if (x1 >= cols || y1 >= rows || x1 <= 0) {
		cout << "unos velicina nije valjan" << endl;
		return;
	}

	int x = p.x;
	int y = p.y;

	if (p.x >= p.y) {

		for (int i = 0; i < p.y - 1; i++) {
			x--;
			//y--;
			board[x * cols + y] = znak;
		}
	}
	else {
		for (int i = 0; i < p.x - 1; i++) {
			x--;
			//y--;
			board[x * cols + y] = znak;
		}
	}

}
/*
void Board::draw_line(Point p1, Point p2, char znak) {
	int x1 = p1.x - 1;
	int y1 = p1.y - 1;
	int x2 = p2.x - 1;
	int y2 = p2.y - 1;

	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			if (y1 == y2)
				board[int(p1.x) * rows + int(p1.y)] = znak;
			else if (i == j)
				board[int(p1.x) * rows + int(p1.y)] = znak;
			else if (x1 == x2)
				board[int(p1.x) * rows + int(p1.y)] = znak;
			else
				continue;
		}
	}
}*/

void Board::draw_line(Point p1, Point p2, char znak) {
	p1.x = round(p1.x), p1.y = round(p1.y), p2.x = round(p2.x), p2.y = round(p2.y);
	int x1 = min(p1.x, p2.x);
	int x2 = max(p1.x, p2.x);
	int y1 = min(p1.y, p2.y);
	int y2 = max(p1.y, p2.y);
	int x1 = p1.x;
	int y1 = p1.y;
	int x2 = p2.x;
	int y2 = p2.y;
	if (x1 >= cols || y1 >= rows || x1 <= 0 || x2 >= cols || y2 >= rows || x2 <= 0) {
		cout << "unos velicina nije valjan" << endl;
		return;
	}

	int x = abs(p1.x - p2.x);
	int y = abs(p1.y - p2.y);
	float xk, yk;
	int brojac;

	if (x > y) {
		yk = float(y) / float(x);
		xk = 1;
		brojac = x;
	}
	else {
		xk = float(x) / float(y);
		yk = 1;
		brojac = y;
	}

	if (p1.x > p2.x) {
		xk *= -1;
	}
	if (p1.y > p2.y) {
		yk *= -1;
	}

	for (int i = 0; i < brojac; i++) {
		p1.x += xk;
		p2.y += yk;
		round(p1.x);
		round(p1.y);
		//if (x + i == visina - 1)
			//continue;
		board[int(p1.x) * rows + int(p1.y)] = znak;
	}
}

void Board::display() {
	cout << endl << endl;

	int j = 0;
	for (int i = 0; i < rows * cols; i++) {
		if (j == rows) {
			cout << endl;
			j = 0;
		}
		j++;
		cout << board[i];
	}
	cout << endl << endl;
}

Board::Board(const Board& b) {
	this->rows = b.rows;
	this->cols = b.cols;
	board = new char[rows * cols];
	for (int i = 0; i < rows * cols; i++) {
		board[i] = b.board[i];
	}
}

Board::~Board() {
	delete[] board;
}

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}


int main() {
	Point p1(2, 2), p2(8, 8), p3(2, 8),
		p4(16, 8);
	Board b(20, 10);
	b.draw_line(p1, p2, 'x');
	//b.draw_line(p3, p4, 'x');
	b.display();
}



