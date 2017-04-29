#pragma once
#include "Controller.h"
#include <iostream>
#include "DynamicVector.h"
using namespace std;

class UI {

private:
	Controller ctrl;
	
public:

	UI(const Controller & controller) : ctrl(controller) {}

	void run();
	

private:
	int readInteger(const char* message);
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();
	void readCoat(int &s, string &c, int &p, int &q, string &ph, int &l);



	//Admin operations:
	void addData();
	void removeData();
	void updateData();
	void seeData();
	void filter();

	//User operations:
	void iterate(int size);
	void UI::printIterate(int x);
	int UI::getNext(DynamicVector<Coat>& vec, int pos, int size);
};