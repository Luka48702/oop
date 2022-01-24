#include "Zivotinja.h"


int main() {
	Tarantula t;
	Zohar z;
	Vrabac v;

	vector<Zivotinja*> zivotinje;
	zivotinje.push_back(&t);
	zivotinje.push_back(&z);
	zivotinje.push_back(&v);
	Brojac broj(zivotinje);
	broj.ispisi();
	cout << "Broj nogu je: " << broj.getBroji() << endl;
}
