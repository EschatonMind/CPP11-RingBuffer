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

	Iterator begin() {
		return Iterator(0, *this);
	}

	Iterator end() {
		return Iterator(m_size, *this);
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
private:
	int m_pose;
	RingBuffer& m_Ring;
public:
	Iterator(int pose, RingBuffer& Ring): m_pose(pose), m_Ring(Ring) {

	}

	Iterator& operator++(int) {
		m_pose++;
		return *this;
	}

	Iterator& operator++() {
		m_pose++;
		return *this;
	}

	T& operator*() {
		return m_Ring.get(m_pose);
	}

	bool operator!=(const Iterator& other)const {
		return m_pose != other.m_pose;
	}

	bool operator==(const Iterator& other)const {
		return m_pose == other.m_pose;
	}
};