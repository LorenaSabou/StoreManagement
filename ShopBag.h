#pragma once
#include "DynamicVector.h"
#include "Domain.h"

class ShopBag {

private:
	
	DynamicVector <Coat> v;// Acts as a repository of coats(the shop bag)
	int price;// Variable where we keep the total sum of the elements' prices from the shopbag.

public:

	//Costructor
	ShopBag() : price(0) {}

	//Gets a coat object and adds it to the shop bag
	void add(Coat x);

	//Prints the repository
	void print();

	//Returns the total price 
	int get_bagPrice();


	//output: pointer to the first coat in the bag
	DynamicVector<Coat> getAll() const {return v;};

	//returns the size of the bag
	int getSize();
};