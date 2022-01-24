#include "Zivotinja.h"


Zivotinja::Zivotinja() {

}

Zivotinja::Zivotinja(int brNogu, string vrsta)
{
	this->brNogu = brNogu;
	this->vrsta = vrsta;
}


Brojac::Brojac(vector<Zivotinja*> zivotinje)
{
	this->zivotinje = zivotinje;
}

int Brojac::getBroji()
{
    int broji = 0;
    for (auto it = zivotinje.begin(); it != zivotinje.end(); it++){
        broji = broji + (*it)->getNoge();
    }
    return broji;
}

void Brojac::ispisi()
{
    for (auto it = zivotinje.begin(); it != zivotinje.end(); it++)
    {
        cout << "Dodan:" << (*it)->getVrsta() << endl;
    }
}
