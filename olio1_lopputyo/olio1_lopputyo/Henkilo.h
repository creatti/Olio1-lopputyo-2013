#pragma once
#include <string>
using std::string;
class Henkilo
{
public:
	Henkilo();
	Henkilo(string etunimi, string sukunimi, 
		string osoite, string puhelinnumero);
	~Henkilo();
	Henkilo(const Henkilo&hlo);

	string annaEtunimi() const;
	string annaOsoite() const;
	string annaPuhelinnumero() const;
	string annaSukunimi() const;
	void asetaEtunimi(string etunimi);
	void asetaOsoite(string osoite);
	void asetaPuhelinnumero(string puhelinnumero);
	void asetaSukunimi(string sukunimi);
	void tulostaTiedot() const;
	void kysyTiedot();
	Henkilo& operator=(const Henkilo&);		//sijoitusoperaattorin ylikuormitus
private:
	string etunimi_;
	string sukunimi_;
	string osoite_;
	string puhelinnumero_;
};

