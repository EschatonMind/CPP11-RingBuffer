#pragma once
#include <iostream>
using namespace std;
// declareing the " RingBuffer Class " from template
template<class T>
class RingBuffer
{
private:
	int m_pose; // position of an item of type t
	int m_size; // the size of array of T
	T *m_values; // dynamic allocation of T array

public:
	class Iterator; // creating Iterator class

public:
	// RingBuffer constructor gets the size and initializes other values az 0 and null
	RingBuffer(int size) : m_pose(0), m_size(size), m_values(NULL) {
		m_values = new T[size];
	}
	
	// RingBuffer destructor deallocates the values
	~RingBuffer() {
		delete [] m_values;

	}

	// fuction returns size
	int size() {
		return m_size;
	}

	// setting Iterator functions related to Ringbuffer : begin
	Iterator begin() {
		return Iterator(0, *this);
	}

	// setting Iterator functions related to Ringbuffer : end
	Iterator end() {
		return Iterator(m_size, *this);
	}

	// adding values to array
	void add(T value) {

		m_values[m_pose++] = value;

		if (m_pose == m_size) {
			m_pose = 0;
		}
	}

	// returning an " pose " value by ref
	T& get(int pose) {
		return m_values[pose];
	}
};

// implementing " Iterator " class through T template
template<class T>
class RingBuffer<T>::Iterator {
private:
	int m_pose; // current location
	RingBuffer& m_Ring; // refrence to RingBuffer

public:
	// Iterator constructor initializing variables
	Iterator(int pose, RingBuffer& Ring): m_pose(pose), m_Ring(Ring) {

	}

	// operator overloading: ++ for incrementing the iterator position or location
	Iterator& operator++(int) {
		m_pose++;
		return *this;
	}

	// operator overloading: ++ for incrementing the iterator position or location
	Iterator& operator++() {
		m_pose++;
		return *this;
	}

	// operator overloading: * inorder to get current value of Ringbuffer
	T& operator*() {
		return m_Ring.get(m_pose);
	}

	// operator overloading: != and == to check the Itrators
	bool operator!=(const Iterator& other)const {
		return m_pose != other.m_pose;
	}

	bool operator==(const Iterator& other)const {
		return m_pose == other.m_pose;
	}

};