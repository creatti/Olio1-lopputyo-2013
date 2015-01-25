#pragma once
#include <string>
#include <vector>
#include "Koulutusohjelma.h"
using std::string; using std::vector;

class Koulu
{
public:
	Koulu();
	Koulu(string);
	~Koulu();
	void lisaaKoulutusohjelma();			// valinta 1
	void tulostaKoulutusohjelmat()const;	// valinta 2
	void asetaKoulunimi(string);
	string annaKoulunimi()const;
	void lisaaOpettaja();					// valinta 4
	void tulostaOpettajat();				// valinta 5
	void lisaaOpiskelija();					// valinta 6
	void tulostaOpiskelijat();				// valinta 7
	void poistaKoulutusohjelma();			// valinta 8
	void poistaOpettaja();					// valinta 9
	void poistaOpiskelija();				// valinta 10
	void ohjelmienMaara();					// valinta 3
	void vaihdaOhjelmanNimi();				// valinta 11
	void vaihdaOpeTiedot();					// valinta 12
	void vaihdaOpiskTiedot();				// valinta 13
	bool lueKoulutusohjelma();
	bool tallennaKoulutusohjelma();	
	void lue();								// valinta 14
	void tallenna();						// valinta 15
private:
	string koulunimi_;
	vector <Koulutusohjelma> koulutusohjelmat_;
	int kysykoulutusohjelma();
	int haeKoulutusohjelmaIndeksi(string);
};