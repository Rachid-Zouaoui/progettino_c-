#include "Dispositivo.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;

string aziendaToString(AziendaProduttrice azienda){
	switch (azienda) {
		case apple:
			return "apple";
	    case hp:
	    	return "hp";
	    case microsoft:
	    	return "microsoft";
	    case dell:
	    	return "dell";
	    case asus:
	    	return "asus";
	    case lenovo:
	    	return "lenovo";
	    case huwawei:
	    	return "huwawei";
	    default:
	    	return "sconosciuta";
	}
}

string fasciaToString(Fascia fascia){
	switch (fascia) {
		case topDiGamma:
			return "topDiGamma";
	    case fasciaMedia:
	    	return "fasciaMedia";
	    case bassaFascia:
	    	return "bassaFascia";
	    default:
	    	return "sconosciuta";
	}
}


AziendaProduttrice stringToAzienda(int aziendaString){
	switch (aziendaString) {
			case 1:
				return apple;
		    case 2:
		    	return hp;
		    case 3:
		    	return microsoft;
		    case 4:
		    	return dell;
		    case 5:
		    	return asus;
		    case 6:
		    	return lenovo;
		    case 7:
		    	return huwawei;
		    default:
		    	return apple;
		}
}

Dispositivo::Dispositivo(){

}

Dispositivo::Dispositivo(string serial, string nome,
		string caratteristiche, AziendaProduttrice azienda, double prezzo, string colore, int pollici){

	setSerial(serial);
	setNome(nome);
	setAzienda(azienda);
	setCaratteristiche(caratteristiche);
	setColore(colore);
	setPrezzo(prezzo);
	setPollici(pollici);
}

Dispositivo::~Dispositivo(){
	cout<<"Dispositivo eliminato."<<endl;
}

void Dispositivo::setSerial(string s){
	serial_number = s;
}

string Dispositivo::getSerial(){
	return serial_number;
}

void Dispositivo::setNome(string n){
	nome = n;
}

string Dispositivo::getNome(){
	return nome;
}

void Dispositivo::setCaratteristiche(string caratteristiche){
	caratteristiche_tecniche = caratteristiche;
}

string Dispositivo::getCaratteristiche(){
	return caratteristiche_tecniche;
}

void Dispositivo::setColore(string c){
	colore = c;
}

string Dispositivo::getColore(){
	return colore;
}

void Dispositivo::setAzienda(AziendaProduttrice a){
	azienda = a;
}

AziendaProduttrice Dispositivo::getAzienda(){
	return azienda;
}

void Dispositivo::setPrezzo(double prezzo){
	prezzo_listino = prezzo;
}

double Dispositivo::getPrezzo(){
	return prezzo_listino;
}

void Dispositivo::setPollici(int pollici){
	pollici_display = pollici;
}

int Dispositivo::getPollici(){
	return pollici_display;
}

void Dispositivo::setFascia(Fascia f){
	fascia = f;
}

Fascia Dispositivo::getFascia(){
	return fascia;
}

string Dispositivo::toString(string classe){
	string pollici = to_string(pollici_display);
	return classe+"[ Azienda--> "+ aziendaToString(azienda) + " Prezzo "+ to_string(prezzo_listino)+" Colore--> " + colore + " Caratteristiche_tecniche--> "+caratteristiche_tecniche+" ]";
}

// -----------------------------------
// ---------- CLASSE Tablet ----------
// -----------------------------------

Tablet::Tablet(){}

Tablet::Tablet(string serial, string nome,string caratteristiche, AziendaProduttrice azienda, double prezzo, string colore, int pollici, bool digitalizzatore, string sistemaOperativo) :
		Dispositivo(serial, nome, caratteristiche, azienda, prezzo, colore, pollici){
		setDigitalizzatore(digitalizzatore);
		setSistemaOperativo(sistemaOperativo);
}

Tablet::Tablet(bool digit, string sistemaOperativo){
	setDigitalizzatore(digit);
	setSistemaOperativo(sistemaOperativo);
}

Tablet::~Tablet(){
	cout<<"Tablet eliminato"<<endl;
}


void Tablet::setDigitalizzatore(bool digit){
	digitalizzatore = digit;
}

bool Tablet::getDigitalizzatore(){
	return digitalizzatore;
}

void Tablet::setSistemaOperativo(string so){
	sistemaOperativo = so;
}

string Tablet::getSistemaOperativo(){
	return sistemaOperativo;
}



// -----------------------------------
// ---------- CLASSE Smartphone ----------
// -----------------------------------

Smartphone::Smartphone(){}

Smartphone::Smartphone(string serial, string nome,string caratteristiche, AziendaProduttrice azienda, double prezzo, string colore, int pollici, bool dualsim, int num_fotocamere,string sistemaOperativo) :
		Dispositivo(serial, nome, caratteristiche, azienda, prezzo, colore, pollici){
		setDualSim(dualsim);
		setSistemaOperativo(sistemaOperativo);
}

Smartphone::~Smartphone(){
	cout<<"Smartphone eliminato"<<endl;
}

void Smartphone::setDualSim(bool d){
	dualSim = d;
}

bool Smartphone::getDualSim(){
	return dualSim;
}

void Smartphone::setSistemaOperativo(string so){
	sistemaOperativo = so;
}

string Smartphone::getSistemaOperativo(){
	return sistemaOperativo;
}

// -----------------------------------
// ---------- CLASSE Notebook ----------
// -----------------------------------

Notebook::Notebook(){}

Notebook::Notebook(string serial, string nome,string caratteristiche, AziendaProduttrice azienda, double prezzo, string colore, int pollici, bool touchsecreen, string sistemaOperativo) :
		Dispositivo(serial, nome, caratteristiche, azienda, prezzo, colore, pollici){
		setTouchScreen(touchsecreen);
		setSistemaOperativo(sistemaOperativo);
}

Notebook::~Notebook(){
	cout<<"Notebook eliminato"<<endl;
}

void Notebook::setTouchScreen(bool t){
	touchscreen = t;
}

void Notebook::setSistemaOperativo(string so){
	sistemaOperativo = so;
}

// -----------------------------------
// ---------- CLASSE Monitor ---------
// -----------------------------------

Monitor::Monitor(){}

Monitor::Monitor(string serial, string nome,string caratteristiche, AziendaProduttrice azienda, double prezzo, string colore, int pollici, bool casse, bool schermo ) :
		Dispositivo(serial, nome, caratteristiche, azienda, prezzo, colore, pollici){
		setCasseAudio(casse);
		setSchermoOpaco(schermo);
}

Monitor::~Monitor(){
	cout<<"Monitor eliminato"<<endl;
}

void Monitor::setCasseAudio(bool c){
	casse_audio = c;
}

void Monitor::setSchermoOpaco(bool so){
	schermo_opaco = so;
}


// -----------------------------------
// ----- MULTICLASSE DueInUno --------
// -----------------------------------

DueInUno::DueInUno(){

}

DueInUno::DueInUno(Tablet *t):
	Dispositivo(t->getSerial(), t->getNome(), t->getCaratteristiche(), t->getAzienda(), t->getPrezzo(), t->getColore(), t->getPollici()), Tablet(t->getDigitalizzatore(), t->getSistemaOperativo()), Notebook(){
			(t->getFascia());
	}

DueInUno::DueInUno(Notebook *n):
	Dispositivo(n->getSerial(), n->getNome(), n->getCaratteristiche(),
			n->getAzienda(), n->getPrezzo(), n->getColore(), n->getPollici()), Notebook(), Tablet(){
			(n->getFascia());
	}

string DueInUno::toString(Fascia fascia){
	return "DueInuNO"+ fasciaToString(fascia);
}
