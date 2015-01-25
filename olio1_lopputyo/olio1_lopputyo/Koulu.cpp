#include "Koulu.h"
#include <iostream>
using std::cout;using std::cin;using std::endl;using std::getline;
using std::vector;
#include<fstream>
using std::ofstream;using std::ifstream;

Koulu::Koulu()
{
}
Koulu::Koulu(string koulunimi):koulunimi_(koulunimi)
{
}
Koulu::~Koulu()
{
}
void Koulu::lisaaKoulutusohjelma()
{
	Koulutusohjelma ohjelma;
	ohjelma.kysyTiedot();
	koulutusohjelmat_.push_back(ohjelma);
}
void Koulu::tulostaKoulutusohjelmat()const
{
	for (unsigned int i=0; i<koulutusohjelmat_.size(); i++)
		koulutusohjelmat_.at(i).tulostaTiedot();
}
void Koulu::asetaKoulunimi(string koulunimi)
{
	koulunimi_ = koulunimi;
}
string Koulu::annaKoulunimi() const
{
	return koulunimi_;
}

int Koulu::kysykoulutusohjelma()
{
	cout<<"Anna koulutusohjelma: ";
	string koNimi;
	getline(cin,koNimi);
	return haeKoulutusohjelmaIndeksi(koNimi); 
}
int Koulu::haeKoulutusohjelmaIndeksi(string koNimi)	// haetaan koulutusohjelman indeksi(sijainti) vectorin sis‰ll‰ jotta voidaan k‰sitell‰ haluttua koulutusohjelmaa
{
	for ( unsigned int i=0; i<koulutusohjelmat_.size(); i++)
		if (koulutusohjelmat_.at(i).annaNimi() == koNimi)
			return i;  
	cout << "Koulutusohjelmaa ei loydy"<<endl;
	return -1;  
}

void Koulu::lisaaOpettaja()
{
	int koInd;
	koInd = kysykoulutusohjelma();
	if(koInd> -1)
		koulutusohjelmat_[koInd].lisaaOpettaja();
}

void Koulu::tulostaOpettajat()
{
	int koInd;
	koInd = kysykoulutusohjelma();
	if(koInd> -1)
		koulutusohjelmat_[koInd].tulostaOpettajat();
}
void Koulu::lisaaOpiskelija()
{
	int koInd;
	koInd = kysykoulutusohjelma();
	if(koInd>-1)
		koulutusohjelmat_[koInd].lisaaOpiskelija();
}
void Koulu::tulostaOpiskelijat()
{
	int koInd;
	koInd = kysykoulutusohjelma();
	if(koInd>-1)
		koulutusohjelmat_[koInd].tulostaOpiskelijat();
}
void Koulu::poistaKoulutusohjelma()
{
	int koInd;
	koInd = kysykoulutusohjelma();
	if(koInd>-1)
		koulutusohjelmat_.erase(koulutusohjelmat_.begin()+koInd);
}
void Koulu::poistaOpettaja()
{
	int koInd;
	koInd = kysykoulutusohjelma();
	if (koInd>-1)
		koulutusohjelmat_[koInd].poistaOpettaja();
}
void Koulu::poistaOpiskelija()
{
	int koInd;
	koInd = kysykoulutusohjelma();
	if (koInd>-1)
		koulutusohjelmat_[koInd].poistaOpiskelija();
}
void Koulu::ohjelmienMaara()	// kertoo koulutusohjelmien lukum‰‰r‰n
{
	cout <<"Koulutusohjelmien m\x84\x84r\x84: " << koulutusohjelmat_.size() << endl;
}
void Koulu::vaihdaOhjelmanNimi()
{
	int koInd;
	koInd = kysykoulutusohjelma();
	if (koInd>-1)
		koulutusohjelmat_[koInd].kysyTiedot();
}
void Koulu::vaihdaOpeTiedot()
{
	int koInd;
	koInd = kysykoulutusohjelma();
	if (koInd>-1)
		koulutusohjelmat_[koInd].vaihdaOpettajanTiedot();
}
void Koulu::vaihdaOpiskTiedot()
{
	int koInd;
	koInd = kysykoulutusohjelma();
	if (koInd>-1)
		koulutusohjelmat_[koInd].vaihdaOpiskelijanTiedot();
}
bool Koulu::lueKoulutusohjelma()		// Lataa koulutusohjelmat tiedostosta
{
	ifstream tied;
	string ko_nimi;
	koulutusohjelmat_.clear(); // tyhjenn‰ koulutusohjelmat ennen tiedostosta lukua.
	tied.open("Koulutusohjelma.csv");
	if(tied.is_open())
	{
		while(tied.peek() != EOF)
		{
			getline(tied,ko_nimi,'\n');
			koulutusohjelmat_.push_back(Koulutusohjelma(ko_nimi));
		}
		return true;
	}
	return false;
}
bool Koulu::tallennaKoulutusohjelma()		// Tallentaa koulutusohjelman tiedostoon
{
	ofstream tied;
	tied.open("Koulutusohjelma.csv");
	if(tied.is_open())
	{
		for(unsigned int i=0;i<koulutusohjelmat_.size();i++)
			tied<<koulutusohjelmat_.at(i).annaNimi()<<endl;
		tied.close();
		return true;
	}
	else
		cout<<"Koulutusohjelma.csv tiedostoa ei voi avata."<<endl;

	return false;
}
void Koulu::lue()	// tietojen lukeminen tiedostosta
{
	lueKoulutusohjelma();
	for(unsigned int i=0;i<koulutusohjelmat_.size();i++)	// Lue kolutusohjelman opettajat ja opiskelijat
	{
		koulutusohjelmat_.at(i).lueOpettajat();
		koulutusohjelmat_.at(i).lueOpiskelijat();
	}
}
void Koulu::tallenna()		// Tallentaminen tiedostoon
{
	tallennaKoulutusohjelma();		// koulutusohjelmien tallennus tiedostoon
	for(unsigned int i=0;i<koulutusohjelmat_.size();i++)
	{
		koulutusohjelmat_.at(i).tallennaOpettajat(i);	// opettajien tallennus tiedostoon
		koulutusohjelmat_.at(i).tallennaOpiskelijat(i);	// opiskelijoiden tallennus tiedostoon
	}
}