#pragma once
#include "Tyontekija.h"

class Opettaja: public Tyontekija
{
public:
	Opettaja();
	Opettaja(string etunimi, string sukunimi,  string osoite, 
		string puhelinnumero, double palkka, string opetusala);
	~Opettaja();
	Opettaja(const Opettaja&ope);
	string annaOpetusala() const;
	void asetaOpetusala(string);
	void tulostaTiedot() const;
	void kysyTiedot();
	Opettaja& operator=(const Opettaja&);
private:
	string opetusala_;
};