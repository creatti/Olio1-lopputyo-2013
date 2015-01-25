#include "Henkilo.h"
#include <iostream>
using std::cout; using std::endl; using std::cin; 
using std::getline;


Henkilo::Henkilo(): etunimi_(""), sukunimi_(""), osoite_(""), puhelinnumero_("")		// Luokan alustus oletusrakentajalla
{}

Henkilo::Henkilo(string etunimi, string sukunimi, string osoite, string puhelinnumero):			// Luokan alustus parametrisella rakentajalla
	etunimi_(etunimi), sukunimi_(sukunimi), osoite_(osoite), puhelinnumero_(puhelinnumero)
{}

Henkilo::~Henkilo()
{}

Henkilo::Henkilo(const Henkilo& alkup): etunimi_(alkup.etunimi_), sukunimi_(alkup.sukunimi_), osoite_(alkup.osoite_), puhelinnumero_(alkup.puhelinnumero_)			// Kopiorakentaja
{}

string Henkilo::annaEtunimi() const
{
	return etunimi_;
}

string Henkilo::annaOsoite() const
{
	return osoite_;
}

string Henkilo::annaPuhelinnumero() const
{ 
	return puhelinnumero_;
}

string Henkilo::annaSukunimi() const
{
	return sukunimi_;
}

void Henkilo::asetaEtunimi(string etunimi)
{
	etunimi_ = etunimi;
}

void Henkilo::asetaOsoite(string osoite)
{
	osoite_ = osoite;
}

void Henkilo::asetaPuhelinnumero(string puhelinnumero)
{
	puhelinnumero_ = puhelinnumero;
}

void Henkilo::asetaSukunimi(string sukunimi)
{
	sukunimi_ = sukunimi;
}

void Henkilo::tulostaTiedot() const
{
	cout << sukunimi_ << " " << etunimi_ << " " << osoite_ << " " << puhelinnumero_ ;
}

void Henkilo::kysyTiedot()
{
	cout << "Anna etunimi: ";
	getline(cin,etunimi_);
	cout << "Anna sukunimi: ";
	getline(cin, sukunimi_);
	cout << "Anna osoite: ";
	getline(cin,osoite_);
	cout <<"Anna puhelinnumero: ";
	getline (cin, puhelinnumero_);
}
Henkilo& Henkilo::operator= (const Henkilo& hlo)		// Ylikuormitus
{
	if (this != &hlo)									// Tarkistetaan, ettei sijoiteta itseensä
	{
		etunimi_ = hlo.etunimi_;
		sukunimi_ = hlo.sukunimi_;
		osoite_ = hlo.osoite_;
		puhelinnumero_ = hlo.puhelinnumero_;
	}

	return *this;

}