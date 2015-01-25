#pragma once
#include<vector>
#include<string>
#include"Opettaja.h"
#include"Opiskelija.h"
using std::vector;using std::string;
class Koulutusohjelma
{
public:
	Koulutusohjelma();
	Koulutusohjelma(string);
	~Koulutusohjelma();
	void lisaaOpiskelija();						// valinta 6
	void lisaaOpettaja();						// valinta 4
	void tulostaOpiskelijat()const;
	void tulostaOpettajat()const;
	void asetaNimi(string);
	string annaNimi()const;
	void kysyTiedot();
	void tulostaTiedot()const;
	Koulutusohjelma& operator=(const Koulutusohjelma&);
	void poistaOpettaja();						// valinta 9
	void poistaOpiskelija();					// valinta 10
	void vaihdaOpettajanTiedot();				// valinta 12
	void vaihdaOpiskelijanTiedot();				// valinta 13
	bool lueOpettajat();
	bool tallennaOpettajat(int);
	bool lueOpiskelijat();
	bool tallennaOpiskelijat(int);
private:
	string nimi_;
	vector<Opiskelija> opiskelijat_;
	vector<Opettaja> opettajat_;
	int kysyNimet(int);
	int haeHenkiloIndeksi(int,string,string);
};