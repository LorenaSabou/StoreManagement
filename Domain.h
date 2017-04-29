#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <shellapi.h>


class Coat {

private:
	int size;
	std::string color;
	int price;
	int quantity;
	std::string photo;
	int length;

public:
	Coat() : size(0), color(""), price(0), quantity(0), photo(""),length(0) {};
	Coat(int size, const std::string& color, int price, int quantity, const std::string& photo,int length);
	~Coat() = default;

	int get_price() { return price; }
	int get_size() { return size; }
	int get_quantity() { return quantity; }
	int get_length() { return length; }
	std::string get_color() { return color; }
	std::string get_photo() { return photo; }

	void set_price(int p) { this->price = p; }
	void set_size(int s) { this->size = s; }
	void set_length(int l) {this->length = l;}
	void set_color(std::string c) { this->color = c; }
	void set_photo(std::string ph) { this->photo = ph; }
	void set_quantity(int q) { this->quantity = q; }

	void see_photo();
	void print_coat();

	bool operator==(const Coat& anotherCoat);
	bool operator<(int cmpLength);
};
