#include "Sovellus.h"
#include <iostream>
using std::cout;using std::cin;using std::endl;using std::getline;
using std::vector;

Sovellus::Sovellus()
{
}
Sovellus::~Sovellus()
{
}
void Sovellus::naytaValikko()
{
	cout<<"1) Lis\x84\x84 koulutusohjelma"<<endl;					//lisaaKoulutusohjelma()
	cout<<"2) Tulosta koulutusohjelmien nimet"<<endl;				//tulostaKoulutusohjelma()
	cout<<"3) Tulosta koulutusohjelmien m\x84\x84r\x84"<<endl;		//tulostaKouOhmaara()
	cout<<"4) Lis\x84\x84 koulutusohjelmaan opettaja"<<endl;		//lisaaOpettaja()
	cout<<"5) Tulosta koulutusohjelman opettajat"<<endl;			//tulostaOpettaja()
	cout<<"6) Lis\x84\x84 koulutusohjelmaan opiskelija"<<endl;		//lisaaOpiskelija()
	cout<<"7) Tulosta koulutusohjelman opiskelijat"<<endl;			//tulostaOpiskelija()
	cout<<"8) Poista koulutusohjelma"<<endl;						//postaKoulutusohjelma()
	cout<<"9) Poista opettaja"<<endl;								//poistaOpettaja()
	cout<<"10) Poista opiskelija"<<endl;							//poistaOpiskelija()
	cout<<"11) P\x84ivit\x84 koulutusohjelman nimi"<<endl;			//päivitäKoulutusohjelma()
	cout<<"12) P\x84ivit\x84 opettajan tiedot"<<endl;				//päivitäOpettaja()
	cout<<"13) P\x84ivit\x84 opiskelijan tiedot"<<endl;				//päivitäOpiskelija()
	cout<<"14) Lue tiedot"<<endl;									//lue()
	cout<<"15) Tallenna tiedot"<<endl;								//Tallenna()
	cout<<"0) Lopeta"<<endl;
}
void Sovellus::aja()
{
	naytaValikko();		//Tulostetaan päävalikko

	while(valinta_!="0")	// valikon toiminta ja valinnat
	{
		getline(cin,valinta_);
		if(valinta_=="0")
			break;
		else if(valinta_=="1")
			laitos_.lisaaKoulutusohjelma();
		else if(valinta_=="2")
			laitos_.tulostaKoulutusohjelmat();
		else if(valinta_=="3")
			laitos_.ohjelmienMaara();
		else if(valinta_=="4")
			laitos_.lisaaOpettaja();
		else if(valinta_=="5")
			laitos_.tulostaOpettajat();
		else if(valinta_=="6")
			laitos_.lisaaOpiskelija();
		else if(valinta_=="7")
			laitos_.tulostaOpiskelijat();
		else if(valinta_=="8")
			laitos_.poistaKoulutusohjelma();
		else if(valinta_=="9")
			laitos_.poistaOpettaja();
		else if(valinta_=="10")
			laitos_.poistaOpiskelija();
		else if(valinta_=="11")
			laitos_.vaihdaOhjelmanNimi();
		else if(valinta_=="12")
			laitos_.vaihdaOpeTiedot();
		else if(valinta_=="13")
			laitos_.vaihdaOpiskTiedot();
		else if(valinta_=="14")
			laitos_.lue();
		else if(valinta_=="15")
			laitos_.tallenna();
		else
			cout<<"Virheellinen valinta"<<endl;
		naytaValikko();
	}
}
void Sovellus::asetaValinta(string valinta)
{
	valinta_=valinta;
}
string Sovellus::annaValinta()const
{
	return valinta_;
}