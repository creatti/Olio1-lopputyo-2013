#include "Opettaja.h"
#include <iostream>
using std::cout; using std::endl; using std::getline; using std::cin;

Opettaja::Opettaja(): Tyontekija(), opetusala_("")
{}

Opettaja::Opettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string opetusala):
	Tyontekija(etunimi, sukunimi, osoite, puhelinnumero, palkka), opetusala_(opetusala)
{}

Opettaja::~Opettaja()
{}

Opettaja::Opettaja(const Opettaja& alkup): Tyontekija(alkup), opetusala_(alkup.opetusala_)
{}

string Opettaja::annaOpetusala() const
{
	return opetusala_;
}

void Opettaja::asetaOpetusala(string opetusala)
{
	opetusala_ = opetusala;
}

void Opettaja::tulostaTiedot() const
{
	Tyontekija::tulostaTiedot();
	cout <<" " << opetusala_ <<  endl;
}

void Opettaja::kysyTiedot()
{
	Tyontekija::kysyTiedot();
	cout << "Anna opetusala: ";	
	getline(cin, opetusala_);
}
Opettaja& Opettaja::operator=(const Opettaja& ope)		//Ylikuormitus
{
	if(this!=&ope)	//Tarkistetaan, ettei sijoiteta itseensä
	{
		Tyontekija::operator=(ope);
		opetusala_=ope.opetusala_;
	}
	return *this;
}