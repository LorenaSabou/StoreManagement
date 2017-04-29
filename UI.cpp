#include "UI.h"
#include "DynamicVector.h"
#include <string>
#define _CRT_SECURE_NO_WARNINGS

int UI::readInteger(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

void UI::readCoat(int &s, string &c, int &p, int &q, string &ph,int& l)
{
	s = readInteger("Give size: ");
	cout << "Give color: ";
	cin >> c;
	p = readInteger("Give price: ");
	q = readInteger("Give quantity: ");
	cout << "Link to photo : ";
	cin >> ph;
	l = readInteger("Give lenght(in cm): ");

}


void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator mode" << endl;
	cout << "2 - User mode" << endl;
	cout << "0 - Exit." << endl;
}

void UI::printAdminMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add " << endl;
	cout << "\t 2 - Update." << endl;
	cout << "\t 3 - Delete " << endl;
	cout << "\t 4 - Show All" << endl;
	cout << "\t 5 - Filter greater than length in cm" << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printUserMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Buy coats" << endl;
	cout << "\t 2 - Show cart list" << endl;
	cout << "\t 0 - Back." << endl;
}


//-----------------------------user-----------------------------------
void UI::printIterate(int x)
{
	cout << "\t\t1)Buy\n";
	if (x) cout << "\t\t2)See Photo\n";
	cout << "\t\t3)Next\n";
	cout << "\t\t0)Back\n";
}

int UI::getNext(DynamicVector<Coat>& vec, int pos, int size) {

	int steps = 0;
	while (true) {

		steps++;
		if (steps > vec.getSize())
			return -1;

		if (pos >= vec.getSize())
			pos = 0;

		if ((vec[pos].get_size() == size || size == 0)&& vec[pos].get_quantity() > 0)
			return pos;

		pos++;
	}

}


void UI::iterate(int size)
{
	DynamicVector<Coat>& vec = this->ctrl.getAll_repo();
	int pos = 0, cmd, sum = 0;

	while (true) {

		pos = this->getNext(vec, pos, size);

		if (pos == -1) {
			cout << "No more coats with this size .\n";
			break;
		}

		vec[pos].print_coat();
		this->printIterate(1);
		cin >> cmd;
		if (cmd == 1) {

			vec[pos].set_quantity(vec[pos].get_quantity() - 1);
			this->ctrl.add_bag(vec[pos]);

			sum += vec[pos].get_price();
			cout << "\n Sum:" << sum << "\n";

			if (vec[pos].get_quantity() == 0)
				this->ctrl.del_repo(vec[pos]);
			else {
				cout << "la";
				pos++;
			}
		}
		else if (cmd == 2) {
			vec[pos].see_photo();
		}
		else if (cmd == 3) {
			pos++;
		}
		else
			break;
	}

}

//-------------------------administrator-----------------------------
void UI::addData()
{
	int size, price, quantity,len;
	string color, photo;

	readCoat(size, color, price, quantity, photo, len);
	Coat x(size, color, price, quantity, photo, len);
	if (!ctrl.add_repo(x))
		cout << "ERROR: ALREADY EXISTING COAT.\n";
}

void UI::removeData()
{
	int size;
	string color, link;

	size = readInteger("SIZE: ");
	cout << "COLOR: ";
	cin >> color;
	cout << "LINK :";
	cin >> link;

	Coat x(size,color, 0, 0,link, 0);
	if (!ctrl.del_repo(x))
		cout << "ERROR: INEXISTENT COAT.\n";
}

void UI::updateData()
{
	int size, quantity, price, len, sizeUpdated, quantityUpdated, priceUpdated;
	string color, photo, colorUpdated;

	readCoat(size, color, price, quantity, photo, len);

	sizeUpdated = readInteger("NEW SIZE: ");
	cout << "NEW COLOR: ";
	cin >> colorUpdated;
	cout << "NEW PRICE:";
	cin >> priceUpdated;
	cout << "NEW QUANTITY:";
	cin >> quantityUpdated;

	
	Coat x(size, color, price, quantity, photo, len);
    Coat y(sizeUpdated,colorUpdated,priceUpdated,quantityUpdated,photo,len);
	
	if (!ctrl.update_repo(x, y))
		cout << "ERROR: INEXISTENT COAT.\n";
}

void UI::seeData()
{
	this->ctrl.print_repo();
}

void UI::filter()
{	
	int len = 0;
	cout << "Give the length:" << "\n";
	cin >> len;
	DynamicVector<Coat> results = this->ctrl.filter(len);
	int size = results.getSize();
	for (int i = 0; i < size; i++) {
		results[i].print_coat();
	}
	if (results.getSize() == 0)
		cout << "No matches!" << "\n";
}


void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// Repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printAdminMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addData();
					break;
				case 2:
					this->updateData();
					break;
				case 3:
					this->removeData();
					break;
				case 4:
					this->seeData();
					break;
				case 5:
					this->filter();
					break;
				default:
					cout << "Invalid command!";
					break;
				}
			}
		}

		// Shopping bag management
		if (command == 2)
		{
			while (true)
			{
				UI::printUserMenu();
				int command{ 0 };
				cout << "Input the command: ";
				cin >> command;
				cin.ignore();
				if (command == 0)
					break;
				switch (command)
				{
				case 1:
					int size;
					cout << "Please input the size: \n";
					cin >> size;
					this->iterate(size);
					break;
				case 2:
					this->ctrl.print_bag();
				    cout << endl;
					break;
				
				}
			}
		}
	}
}