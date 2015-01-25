#pragma once
#include "Henkilo.h"

class Tyontekija: public Henkilo
{
public:

	Tyontekija();
	Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka);
	~Tyontekija();
	Tyontekija(const Tyontekija&tt);
	double annaPalkka() const;
	void asetaPalkka(double);
	void tulostaTiedot() const;
	void kysyTiedot();
	Tyontekija& operator=(const Tyontekija&);
private:
	double palkka_;
};