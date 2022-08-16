#include"RingBuffer.h"

int main(){

	// Using template inorder to create a " RingBuffer " class, dowbelow using that class
	RingBuffer<int> Buffer1(3);
	Buffer1.add(1);
	Buffer1.add(3);
	Buffer1.add(2);
	Buffer1.add(4);

	// Iterating through Ringbuffer
	for (RingBuffer<int>::Iterator it = Buffer1.begin(); it != Buffer1.end(); it++) {
		cout << *it << endl;
	}

	cout << endl;

	// adding to Ringbuffer
	for (int i = 0; i != Buffer1.size(); i++) {
		cout << Buffer1.get(i);
	}

	cout << endl;

	return 0;
}