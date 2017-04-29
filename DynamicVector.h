#pragma once

template <typename T>
class DynamicVector
{
private:

	T* elems;
	int size;
	int capacity;

public:

	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	/*
	Overloading the subscript operator
	Input: pos - a valid position within the vector.
	Output: a reference to the element at position pos.
	*/
	T& operator[](int pos);

	//find first occurence of object
	int DynamicVector<T>::findFirst(const T& obj) const;

	DynamicVector& operator-(const T& elem);

	// Adds an element into the vector.
	void add(T e);
	void del(int pos);
	int getSize() const;
	T* getAll();


private:
	// Doubles the capacity of the vector.
	void resize(double factor = 2);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity = 10)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template<typename T>
int DynamicVector<T>::findFirst(const T& obj) const {
	for (int i = 0; i < this->size(); i++) {
		if (this->elems[i] == obj) {
			return i;
		}
	}
	return -1;
}
template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <typename T>
void DynamicVector<T>::add(T e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <typename T>
void DynamicVector<T>::del(int pos)
{
	this->elems[pos] = this->elems[this->size - 1];
	this->size--;
}

template <typename T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= factor;

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}

template <typename T>
T* DynamicVector<T>::getAll() {

	return this->elems;
}

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator -(const T& elem) {
	int tid = this->findFirst(elem);
	if (tid != -1) {
		this->remove(tid);
	}
	return *this;
}

