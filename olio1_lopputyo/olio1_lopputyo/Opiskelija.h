#pragma once
#include "Henkilo.h"
class Opiskelija: public Henkilo
{
public:
	Opiskelija();
	Opiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero);
	~Opiskelija();
	Opiskelija(const Opiskelija&);
	string annaOpiskelijanumero() const;
	void asetaOpiskelijanumero(string opiskelijanumero);
	void tulostaTiedot() const;
	void kysyTiedot();
	Opiskelija& operator=(const Opiskelija&);
private:
	string opiskelijanumero_;
};