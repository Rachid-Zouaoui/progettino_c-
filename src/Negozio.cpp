//============================================================================
// Name        : Negozio.cpp
// Author      : Rachid Zouaoui
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Dispositivo.h"

using namespace std;

Dispositivo* createDispositivo (int input){

	string serial;
	string nome;
	string caratteristiche;
	int azienda;
	double prezzo;
	string colore;
	int pollici;
	bool digitalizzatore;
	bool touchScreen;
	bool dualSim;
	bool casse;
	bool schermo;
	string so;
	int numFoto;

	Dispositivo *dispositivo;

	switch(input){
		case 1:
			cout<<"Inserire il seriale: "<< endl;
			cin >> serial;
			cout<<"Inserire il nome: "<< endl;
			cin >> nome;
			cout<<"Inserire le caratteristiche: "<< endl;
			cin >> caratteristiche;
			cout<<"Inserire Azienda: 1--> apple, 2-->hp, 3-->microsoft, 4-->dell, 5--> asus, 6-->lenovo, 7-->huwawey "<< endl;
			cin >> azienda;
			cout<<"Inserire Prezzo: "<< endl;
			cin >> prezzo;
			cout<<"Inserire pollici schermo: "<< endl;
			cin >> pollici;
			cout<<"Inserire Colore: "<< endl;
			cin >> colore;
			cout<<"Inserire Sistema operativo: "<< endl;
			cin >> so;
			cout<<"Inserire se ha il digitalizzatore (1 se lo ha 0 altrimenti) : "<< endl;
			cin >> digitalizzatore;
			dispositivo = new Tablet(serial, nome, caratteristiche, stringToAzienda(azienda), prezzo, colore, pollici, digitalizzatore, so);
			break;
		case 2:
			cout<<"Inserire il seriale: "<< endl;
			cin >> serial;
			cout<<"Inserire il nome: "<< endl;
			cin >> nome;
			cout<<"Inserire le caratteristiche: "<< endl;
			cin >> caratteristiche;
			cout<<"Inserire Azienda: 1--> apple, 2-->hp, 3-->microsoft, 4-->dell, 5--> asus, 6-->lenovo, 7-->huwawey "<< endl;
			cin >> azienda;
			cout<<"Inserire Prezzo: "<< endl;
			cin >> prezzo;
			cout<<"Inserire pollici schermo: "<< endl;
			cin >> pollici;
			cout<<"Inserire Colore: "<< endl;
			cin >> colore;
			cout<<"Inserire se è dualSim (1 se lo ha 0 altrimenti) : "<< endl;
			cin >> dualSim;
			cout<<"Inserire il numero di fotocamere : "<< endl;
			cin >> numFoto;
			cout<<"Inserire Sistema operativo: "<< endl;
			cin >> so;
			dispositivo = new Smartphone(serial, nome, caratteristiche, stringToAzienda(azienda), prezzo, colore, pollici, dualSim, numFoto, so);
			break;
		case 3:
			cout<<"Inserire il seriale: "<< endl;
			cin >> serial;
			cout<<"Inserire il nome: "<< endl;
			cin >> nome;
			cout<<"Inserire le caratteristiche: "<< endl;
			cin >> caratteristiche;
			cout<<"Inserire Azienda: 1--> apple, 2-->hp, 3-->microsoft, 4-->dell, 5--> asus, 6-->lenovo, 7-->huwawey "<< endl;
			cin >> azienda;
			cout<<"Inserire Prezzo: "<< endl;
			cin >> prezzo;
			cout<<"Inserire pollici schermo: "<< endl;
			cin >> pollici;
			cout<<"Inserire Colore: "<< endl;
			cin >> colore;
			cout<<"Inserire se è touchscreen (1 se lo ha 0 altrimenti) : "<< endl;
			cin >> touchScreen;
			cout<<"Inserire Sistema operativo: "<< endl;
			cin >> so;
			dispositivo = new Notebook(serial, nome, caratteristiche, stringToAzienda(azienda), prezzo, colore, pollici, touchScreen, so);
			break;
		case 4:
			cout<<"Inserire il seriale: "<< endl;
			cin >> serial;
			cout<<"Inserire il nome: "<< endl;
			cin >> nome;
			cout<<"Inserire le caratteristiche: "<< endl;
			cin >> caratteristiche;
			cout<<"Inserire Azienda: 1--> apple, 2-->hp, 3-->microsoft, 4-->dell, 5--> asus, 6-->lenovo, 7-->huwawey "<< endl;
			cin >> azienda;
			cout<<"Inserire Prezzo: "<< endl;
			cin >> prezzo;
			cout<<"Inserire pollici schermo: "<< endl;
			cin >> pollici;
			cout<<"Inserire Colore: "<< endl;
			cin >> colore;
			cout<<"Inserire se ha le casse (1 se le ha 0 altrimenti) : "<< endl;
			cin >> casse;
			cout<<"Inserire se ha lo schermo opaco (1 se lo ha 0 altrimenti) : "<< endl;
			cin >> schermo;
			dispositivo = new Monitor(serial, nome, caratteristiche, stringToAzienda(azienda), prezzo, colore, pollici, casse, schermo);
			break;
		case 5:
			cout<<"Inserire il seriale: "<< endl;
			cin >> serial;
			cout<<"Inserire il nome: "<< endl;
			cin >> nome;
			cout<<"Inserire le caratteristiche: "<< endl;
			cin >> caratteristiche;
			cout<<"Inserire Azienda: 1--> apple, 2-->hp, 3-->microsoft, 4-->dell, 5--> asus, 6-->lenovo, 7-->huwawey "<< endl;
			cin >> azienda;
			cout<<"Inserire Prezzo: "<< endl;
			cin >> prezzo;
			cout<<"Inserire pollici schermo: "<< endl;
			cin >> pollici;
			cout<<"Inserire Colore: "<< endl;
			cin >> colore;
			cout<<"Inserire Sistema operativo: "<< endl;
			cin >> so;
			Notebook* notebook = new Notebook(serial, nome, caratteristiche, stringToAzienda(azienda), prezzo, colore, pollici, 1, so);
			dispositivo = new DueInUno(notebook);
			break;
		defualt:
			return dispositivo;
			break;
	}
	return dispositivo;
}

int main() {
		int input;
		std::list<Dispositivo*> dataSet;
	do{
		string x = "Tablet --> 1";
		string x1 = "Smatphone --> 2";
		string x2 = "Notebook --> 3";
		string x3 = "Monitor --> 4";
		string x4 = "DueInUno --> 5";
		string x5 = "Termina e visualizza inventario --> 6";
		cout << "Quale dispositivo desideri inserire? Scegli il numero corrispondente: " << endl;
		cout << x << endl;
		cout << x1 << endl;
		cout << x2 << endl;
		cout << x3 << endl;
		cout << x4 << endl;
		cout << x5 << endl;
		cin >> input;


		if(input == 1){
			Dispositivo *adispositivo = createDispositivo(1);
			dataSet.insert(dataSet.begin(), adispositivo);
		}else if(input == 2){
			Dispositivo *adispositivo = createDispositivo(2);
			dataSet.insert(dataSet.begin(), adispositivo);
		}else if(input == 3){
			Dispositivo *adispositivo = createDispositivo(3);
			dataSet.insert(dataSet.begin(), adispositivo);
		}else if(input == 4){
			Dispositivo *adispositivo = createDispositivo(4);
			dataSet.insert(dataSet.begin(), adispositivo);
		}else if(input == 5){
			Dispositivo *adispositivo = createDispositivo(5);
			dataSet.insert(dataSet.begin(), adispositivo);
		}

	}while(input!=6);
	cout << "Ecco gli elementi inseriti nel tuo inventario: " << endl;
	for(Dispositivo *disp : dataSet){
		cout<< disp->toString("") <<endl;
	}


	return 0;
}
