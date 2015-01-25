#include "Koulutusohjelma.h"
#include"Opettaja.h"
#include"Opiskelija.h"
#include <vector>
using std::vector;
#include <iostream>
using std::cout;using std::endl;using std::getline;using std::cin;using std::ios;
#include<fstream>
using std::ifstream;using std::ofstream;

Koulutusohjelma::Koulutusohjelma():nimi_("")
{
}
Koulutusohjelma::Koulutusohjelma(string nimi):nimi_(nimi)
{
}
Koulutusohjelma::~Koulutusohjelma()
{
}
void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija oppilas;
	oppilas.kysyTiedot();
	opiskelijat_.push_back(oppilas);

}
void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja ope;
	ope.kysyTiedot();
	opettajat_.push_back(ope);
	//cout<<opettajat_.size()<<endl;

}
void Koulutusohjelma::tulostaOpiskelijat()const
{
	for(unsigned int i=0;i<opiskelijat_.size();i++)
		opiskelijat_.at(i).tulostaTiedot();
}
void Koulutusohjelma::tulostaOpettajat()const
{
	for(unsigned int i=0;i<opettajat_.size();i++)
	{opettajat_.at(i).tulostaTiedot();
	}
}
void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_=nimi;
}
string Koulutusohjelma::annaNimi()const
{
	return nimi_;
}
void Koulutusohjelma::kysyTiedot()
{
	cout<<"Anna koulutusohjelman nimi: ";
	getline(cin,nimi_);
}
void Koulutusohjelma::tulostaTiedot()const
{
	cout<<nimi_<<endl;
}
Koulutusohjelma& Koulutusohjelma::operator=(const Koulutusohjelma& kou)		// Ylikuormitus
{
	if(this!=&kou)
	{
		nimi_=kou.nimi_;
		opettajat_=kou.opettajat_;
		opiskelijat_=kou.opiskelijat_;
	}
	return *this;
}
int Koulutusohjelma::kysyNimet(int kuka)	// kuka = 1 = opettaja, kuka = 2 = opiskelija
{
	cout<<"Anna etunimi: ";
	string Etunimi, Sukunimi;
	getline(cin,Etunimi);
	cout << "Anna sukunimi: ";
	getline(cin,Sukunimi);
	return haeHenkiloIndeksi(kuka, Etunimi, Sukunimi);
}

int Koulutusohjelma::haeHenkiloIndeksi(int kuka, string Etunimi, string Sukunimi)	// haetaan opettajan/opiskelijan indeksi(sijainti) vectorissa jotta voidaan käsitellä haluttua henkilöä
{
	// kuka = 1 = opettaja, Kuka = 2 = opiskelija
	if(kuka==1)		
	{
		for ( unsigned int i=0; i<opettajat_.size(); i++)
		{
			if (opettajat_.at(i).annaEtunimi() == Etunimi && opettajat_.at(i).annaSukunimi() == Sukunimi)
			{
				return i;
			}     
		}
		cout << "Opettajaa ei l\x94ydy"<<endl;
		return -1; 
	}
	else
	{
		for ( unsigned int i=0; i<opiskelijat_.size(); i++)
		{
			if (opiskelijat_.at(i).annaEtunimi() == Etunimi && opiskelijat_.at(i).annaSukunimi() == Sukunimi)
			{
				return i;
			}     
		}
		cout << "Opiskelijaa ei l\x94ydy"<<endl;
		return -1; 
	}
}
void Koulutusohjelma::poistaOpettaja()
{
	int koInd;
	int kuka = 1;
	koInd = kysyNimet(kuka);
	if(koInd>-1)
		opettajat_.erase(opettajat_.begin()+koInd);
}
void Koulutusohjelma::poistaOpiskelija()
{
	int koInd;
	int kuka = 2;
	koInd = kysyNimet(kuka);
	if(koInd>-1)
		opiskelijat_.erase(opiskelijat_.begin()+koInd);
}
void Koulutusohjelma::vaihdaOpettajanTiedot()
{
	int OpeInd;
	int kuka = 1;
	OpeInd = kysyNimet(kuka);
	if(OpeInd>-1)
		opettajat_[OpeInd].kysyTiedot();
}
void Koulutusohjelma::vaihdaOpiskelijanTiedot()
{
	int OpiskInd;
	int kuka = 2;
	OpiskInd = kysyNimet(kuka);
	if(OpiskInd>-1)
		opiskelijat_[OpiskInd].kysyTiedot();
}
bool Koulutusohjelma::lueOpettajat()		// Haetaan opettajien tiedot tiedostosta
{
	ifstream tied;
	string ko_nimi, enimi, snimi, osoite, puhelin, opetusala, apu;
	double palkka;
	tied.open("Opettaja.csv");
	if(tied.is_open())
	{
		while(tied.peek() !=EOF)
		{
			getline(tied,ko_nimi,';');
			if(nimi_==ko_nimi)
			{
				getline(tied,enimi,';');
				getline(tied,snimi,';');
				getline(tied,osoite,';');
				getline(tied,puhelin,';');
				tied>>palkka;					// double tyyppinen luetaan eri tavalla
				tied.get();
				getline(tied,opetusala,'\n');
				opettajat_.push_back(Opettaja(enimi,snimi,osoite,puhelin,palkka,opetusala));
			}

			else
				getline(tied,apu,'\n');
		}
		return true;
	}
	return false;
}
bool Koulutusohjelma::tallennaOpettajat(int indeksi) //Tallennetaan opettajien tiedot tiedostoon
{
	ofstream tied;
	if(indeksi>0)
		tied.open("Opettaja.csv",ios::app);		// Tiedosto jo olemassa tallennus tiedoston loppuun
	else
		tied.open("Opettaja.csv");				// Luodaan uusi tiedosto
	if(tied.is_open())
	{
		for(unsigned int i=0;i<opettajat_.size();i++)
		{
			tied<<nimi_<<";"<<opettajat_.at(i).annaEtunimi()<<";"<<opettajat_.at(i).annaSukunimi()<<";"<<opettajat_.at(i).annaOsoite()<<";"<<opettajat_.at(i).annaPuhelinnumero()<<";"<<opettajat_.at(i).annaPalkka()<<";"<<opettajat_.at(i).annaOpetusala()<<endl;
		}
		tied.close();
		return true;
	}
	else
		cout<<"Opettaja.csv tiedostoa ei voi avata."<<endl;
	return false;

}
bool Koulutusohjelma::lueOpiskelijat()		// Luetaan opiskelijan tiedot tiedostosta
{
	ifstream tied;
	string ko_nimi, enimi, snimi, osoite, puhelin, opiskelijanumero, apu;
	tied.open("Opiskelija.csv");
	if(tied.is_open())
	{
		while(tied.peek() !=EOF)
		{
			getline(tied,ko_nimi,';');
			if(nimi_==ko_nimi)
			{
				getline(tied,enimi,';');
				getline(tied,snimi,';');
				getline(tied,osoite,';');
				getline(tied,puhelin,';');
				getline(tied,opiskelijanumero,'\n');
				opiskelijat_.push_back(Opiskelija(enimi,snimi,osoite,puhelin,opiskelijanumero));
			}
			else
				getline(tied,apu,'\n');
		}
		return true;
	}
	return false;
}
bool Koulutusohjelma::tallennaOpiskelijat(int indeksi)		// Tallennetaan opiskelijan tiedot tiedostoon
{
	ofstream tied;
	if(indeksi>0)
		tied.open("Opiskelija.csv",ios::app);		// Tiedosto jo olemassa tallennus tiedoston loppuun
	else 
		tied.open("Opiskelija.csv");				// Luodaan uusi tiedosto
	if(tied.is_open())
	{
		for(unsigned int i=0;i<opiskelijat_.size();i++)
		{
			tied<<nimi_<<";"<<opiskelijat_.at(i).annaEtunimi()<<";"<<opiskelijat_.at(i).annaSukunimi()<<";"<<opiskelijat_.at(i).annaOsoite()<<";"<<opiskelijat_.at(i).annaPuhelinnumero()<<";"<<opiskelijat_.at(i).annaOpiskelijanumero()<<endl;
		}
		tied.close();
		return true;
	}
	else
		cout<<"Opiskelija.csv tiedostoa ei voi avata."<<endl;
	return false;
}