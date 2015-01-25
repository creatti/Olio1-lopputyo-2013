#pragma once
#include "Koulu.h"

class Sovellus
{
public:
	Sovellus();
	~Sovellus();
	void naytaValikko();
	void aja();
	void asetaValinta(string);
	string annaValinta()const;
private:
	string valinta_;
	Koulu laitos_;
};