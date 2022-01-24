
#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Zivotinja {
protected:
	int brNogu;
	string vrsta;
public:
	Zivotinja();
	Zivotinja(int brnogu, string vrsta);
	string getVrsta() {return this->vrsta;};
	int getNoge() { return this->brNogu; };
};

class Kukac : public Zivotinja {
public:
	Kukac() { this->brNogu = 6; }
};

class Pauk : public Zivotinja {
public:
	Pauk() { this->brNogu = 8; }
};

class Ptica : public Zivotinja {
public:
	Ptica() { this->brNogu = 2; }
};


class Zohar : public Kukac {
public:
	Zohar() { this->vrsta = "Kukac"; }
};

class Tarantula : public Pauk {
public:
	Tarantula() { this->vrsta = "Pauk"; }
};

class Vrabac : public Ptica {
public:
	Vrabac() { this->vrsta = "Ptica"; }
	
};

class Brojac {
private:
	vector<Zivotinja*> zivotinje;
public:
	Brojac() {};
	Brojac(vector<Zivotinja*> zivotinje);
	int getBroji();
	void ispisi();
};

