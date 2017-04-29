#pragma once
#include "Repository.h"
#include "Domain.h"
#include "ShopBag.h"
#include "DynamicVector.h"

class Controller {

private:
	Repository repo;
	ShopBag bag;
public:
	//Required operations on the two lists
	Controller(const Repository& r) : repo(r) {}
	bool add_repo(Coat x);
	bool del_repo(Coat x);
	bool update_repo(Coat x, Coat y);
	void print_repo();
	DynamicVector<Coat> Controller::filter(int len);

	void add_bag(Coat x);
	int get_price_bag();
	void print_bag();

	//Functions which provide informations about the repository 
	DynamicVector<Coat> getAll_repo();
	int getSize_repo();

	//Functions which provide information about the shopping bag
	DynamicVector<Coat> getAll_bag();
	int getSize_bag();

};