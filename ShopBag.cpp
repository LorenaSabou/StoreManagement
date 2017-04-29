#include "ShopBag.h"

void ShopBag::add(Coat x)
{
	this->v.add(x);
	this->price += x.get_price();
}

void ShopBag::print()
{
	Coat *vec = this->v.getAll();
	int sum = 0;

	if (this->v.getSize() == 0) {
		std::cout << "Empty cart!" << "\n";
		return;
	}
	for (int i = 0; i < this->v.getSize(); i++) {
		std::cout << "Size: " << vec[i].get_size() << "| Color: " << vec[i].get_color() << "| Price: " << vec[i].get_price() << "| Length:"<< vec[i].get_length()<<'\n';
		sum += vec[i].get_price();
	}
	std::cout << "\n Total sum:" << sum << "\n";

	
}

int ShopBag::get_bagPrice()
{
	return this->price;
}


//Coat* ShopBag::getAll()
//{
//	return this->v.getAll();
//}

int ShopBag::getSize()
{
	return this->v.getSize();
}