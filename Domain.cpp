#include "domain.h"
#include <shellapi.h>
#include <iostream>
#include <string>

Coat::Coat(int size, const std::string& color, int price, int quantity, const std::string& photo,int length)
{
	this->size = size;
	this->color = color;
	this->price = price;
	this->quantity = quantity;
	this->photo = photo;
	this->length = length;
}

void Coat::print_coat()
{
	std::cout << "Size: " << this->size << "| Color: " << this->color << "| Price: " << this->price << "| Quantity: " << this->quantity <<"| Length: "<< this->length <<'\n';
	std::cout << "Photo: " << this->photo <<"\n";
	std::cout << '\n';
}

void Coat::see_photo()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->get_photo().c_str(), NULL, SW_SHOWMAXIMIZED);

}

bool Coat::operator==(const Coat& anotherCoat) {
	return this->get_size() == anotherCoat.size && this->get_color() == anotherCoat.color;
}

bool Coat::operator<(int cmpLength) {
	return this->length < cmpLength;
}