#pragma once
#include <iostream>
using namespace std;
template<class T>
class RingBuffer
{

public:
	class Iterator;
};

template<class T>
class RingBuffer<T>::Iterator {

public:
	void print() {
		cout << " I'm the Iterator : " << T() << endl;
	}
};