#pragma once
#include <iostream>
using namespace std;
template<class T>
class RingBuffer
{
private:
	int m_pose;
	int m_size;
	T *m_values;

public:
	class Iterator;

public:
	RingBuffer(int size) : m_pose(0), m_size(size), m_values(NULL) {
		m_values = new T[size];
	}
	
	~RingBuffer() {
		delete [] m_values;

	}

	int size() {
		return m_size;
	}

	void add(T value) {

		m_values[m_pose++] = value;

		if (m_pose == m_size) {
			m_pose = 0;
		}
	}

	T& get(int pose) {
		return m_values[pose];
	}
};

template<class T>
class RingBuffer<T>::Iterator {

public:
	void print() {
		cout << " I'm the Iterator : " << T() << endl;
	}
};