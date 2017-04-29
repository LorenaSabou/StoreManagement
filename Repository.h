#pragma once
#include "Domain.h"
#include "DynamicVector.h"
class Repository {

private:
	DynamicVector <Coat> v;

public:

	/*Function for adding an element
	INPUT:
	- Coat x = an object of the class Coat
	OUTPUT:
	- True if we successfully added the element into repo, false otherwise(if the element is already in the repo)
	*/
	bool add(Coat x);

	/*Function for finding an element, iterates through the whole repo and searches the element that we gave as input.
	An element is uniquely determinated by its size and its colour.

	INPUT:
	- Coat x = an object of the class Coat,the searched element
	OUTPUT:
	- RETURNS AN INTEGER ,that is ,the position of the searched element in repo
	- If the element doesen't exists RETURNS -1.
	*/
	int find(Coat x);

	/*Function for deleting an element.
	INPUT:
	- Coat x = an object of class Coat, that we will delete it
	OUTPUT:
	- Returns TRUE if we succesfully deleted it, FALSE if the coat does not exist in the repo.
	*/
	bool del(Coat x);

	/*Function for updating an element. In this process,a new object is created from scratch,the old one is deleted and replaced 
	with the new one.

	INPUT:
	- Coat x = an object of the class Coat, that we want to update
	- Coat y = an object of the class Coat, containing the new values for updating
	OUTPUT:
	- Returns TRUE if we succesfully updated it, FALSE if coat X was not in the repo in the first place.
	*/
	bool update(Coat x, Coat y);

	//Function for printing the  repo.
	void print();

	/*Function that get all the elements from the repo.*/
	DynamicVector<Coat> getAll() const { return v; };

	/*Function that returns the size of the repo.
	OUTPUT:
	- Returns an integer,that is, the size of our repo.
	*/
	int getSize();

};