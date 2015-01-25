#include "Opiskelija.h"
#include <iostream>

using std::cout; using std::endl; using std::cin;using std::getline;

Opiskelija::Opiskelija(): Henkilo(), opiskelijanumero_("")
{}

Opiskelija::Opiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero): 
Henkilo(etunimi, sukunimi, osoite, puhelinnumero), opiskelijanumero_(opiskelijanumero)
{}

Opiskelija::~Opiskelija()
{}

Opiskelija::Opiskelija(const Opiskelija& alkup): Henkilo(alkup), opiskelijanumero_(alkup.opiskelijanumero_)
{}

string Opiskelija::annaOpiskelijanumero() const
{
	return opiskelijanumero_;
}

void Opiskelija::asetaOpiskelijanumero(string opiskelijanumero)
{
	opiskelijanumero_ = opiskelijanumero;
}

void Opiskelija::tulostaTiedot() const
{
	Henkilo::tulostaTiedot();
	cout <<" " << opiskelijanumero_ << endl;
}

void Opiskelija::kysyTiedot()
{
	Henkilo::kysyTiedot();
	cout <<"Anna opiskelijanumero: ";
	getline(cin, opiskelijanumero_);
}
Opiskelija& Opiskelija::operator=(const Opiskelija& opi)		//Ylikuormitus
{
	if(this != &opi)	//Tarkistetaan, ettei sijoiteta itseensä
	{
		Henkilo::operator=(opi);
		opiskelijanumero_=opi.opiskelijanumero_;

	}
	return *this;
}