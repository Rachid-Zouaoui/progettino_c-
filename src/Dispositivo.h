/*
 * Dispositivo.h
 *
 *  Created on: 4 lug 2021
 *      Author: rachidzouaoui
 */

#ifndef DISPOSITIVO_H_
#define DISPOSITIVO_H_

#include <string>
#include <list>
using namespace std;

enum AziendaProduttrice{
	apple, hp, microsoft, dell, asus, lenovo, huwawei
};

enum Fascia{
	topDiGamma, fasciaMedia, bassaFascia
};



//metodo di utilità per convertire enumerativo in stringa
string aziendaToString (AziendaProduttrice azienda);
AziendaProduttrice stringToAzienda(int azienda);

// classe Dispositivo
class Dispositivo{
	protected:
		string serial_number;
		string nome;
		string caratteristiche_tecniche;
		AziendaProduttrice azienda;
		double prezzo_listino;
		string colore;
		int pollici_display;
		Fascia fascia;
	public:
		Dispositivo();
		Dispositivo(string serial, string nome, string caratteristiche, AziendaProduttrice azienda, double prezzo,
				string colore, int pollici );
		virtual ~Dispositivo();
		AziendaProduttrice getAzienda();
		void setAzienda(AziendaProduttrice azienda);
		string getSerial();
		void setSerial(string serial);
		string getNome();
		void setNome(string n);
		string getCaratteristiche();
		void setCaratteristiche(string caratteristiche);
		string getColore();
		void setColore(string n);
		double getPrezzo();
		void setPrezzo(double prezzo);
		string toString(string classe);
		int getPollici();
		void setPollici(int pollici);
		Fascia getFascia();
		void setFascia(Fascia fascia);
		//virtual void astratta() = 0;
};

//classe Tablet
class Tablet : virtual public Dispositivo{

	protected:
		bool digitalizzatore;
		string sistemaOperativo;


	public:
		Tablet();
		Tablet(string serial, string nome, string caratteristiche, AziendaProduttrice azienda, double prezzo, string colore,
				int pollici, bool digitalizzatore, string sistemaOperativo);
		Tablet(bool digitalizzatore, string sistemaOperativo);
		virtual ~Tablet();
		bool getDigitalizzatore();
		void setDigitalizzatore(bool digitalizzatore);
		string getSistemaOperativo();
		void setSistemaOperativo(string sistemaOperativo);
};

//classe Smartphone
class Smartphone : virtual public Dispositivo{

	protected:
		bool dualSim;
		int num_fotocamere;
		string sistemaOperativo;

	public:
		Smartphone();
		Smartphone(string serial, string nome, string caratteristiche, AziendaProduttrice azienda, double prezzo, string colore,
				int pollici, bool dualSim, int num_fotocamere, string sistemaOperativo);
		Smartphone(bool dualSim, int num_fotocamere, string sistemaOperativo);
		virtual ~Smartphone();
		bool getDualSim();
		void setDualSim(bool dualsim);
		int getNumFotocamere();
		void NumFotocamere(int num_fotocamere);
		string getSistemaOperativo();
		void setSistemaOperativo(string sistemaOperativo);
};


class Notebook : virtual public Dispositivo{

	protected:
		bool touchscreen;
		string sistemaOperativo;

	public:
		Notebook();
		Notebook(string serial, string nome, string caratteristiche, AziendaProduttrice azienda, double prezzo, string colore,
				int pollici, bool touchscreen, string sistemaOperativo);
		Notebook(bool touchscreen, string sistemaOperativo);
		virtual ~Notebook();
		bool getTouchscreen();
		void setTouchScreen(bool touchscreen);
		string getSistemaOperativo();
		void setSistemaOperativo(string sistemaOperativo);
};

class Monitor : virtual public Dispositivo{

	protected:
		bool casse_audio;
		bool schermo_opaco;

	public:
		Monitor();
		Monitor(string serial, string nome, string caratteristiche, AziendaProduttrice azienda, double prezzo, string colore,
					int pollici,bool casse_audio, bool schermo_opaco);
		Monitor(bool casse_audio, bool schermo_opaco);
		virtual ~Monitor();

		bool getCasseAudio();
		void setCasseAudio(bool casseAudio);
		bool getSchermoOpaco();
		void setSchermoOpaco(bool schermoOpaco);

};

class DueInUno : public Notebook, public Tablet{
	public:
		DueInUno();
		DueInUno(Tablet *t);
		DueInUno(Notebook *n);
		string toString(Fascia fascia);
};

#endif /* DISPOSITIVO_H_ */
