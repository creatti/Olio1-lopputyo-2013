#include "Tyontekija.h"
#include <iostream>
using std::cout; using std::endl; using std::cin;

Tyontekija::Tyontekija(): Henkilo(), palkka_(0)
{}

Tyontekija::Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka): 
Henkilo(etunimi, sukunimi, osoite, puhelinnumero), palkka_(palkka)
{}

Tyontekija::~Tyontekija()
{}

Tyontekija::Tyontekija(const Tyontekija& alkup): Henkilo(alkup), palkka_(alkup.palkka_)
{}

double Tyontekija::annaPalkka() const
{
	return palkka_;
}

void Tyontekija::asetaPalkka(double palkka)
{
	palkka_ = palkka;
}

void Tyontekija::tulostaTiedot() const
{
	Henkilo::tulostaTiedot();
	cout << " " << palkka_;
}

void Tyontekija::kysyTiedot()
{
	string palkka;
	Henkilo::kysyTiedot();	
	cout << "Anna opettajan palkka: ";
	getline(cin, palkka);
	palkka_ = atof(palkka.c_str());	
}
Tyontekija& Tyontekija::operator=(const Tyontekija& tyo)		//Ylikuormitus
{
	if(this!=&tyo)	//Tarkistetaan, ettei sijoiteta itseensä
	{
		Henkilo::operator=(tyo);
		palkka_=tyo.palkka_;
	}
	return *this;
}