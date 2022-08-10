#include"RingBuffer.h"

int main() {

	RingBuffer<int>::Iterator it;
	it.print();

	cout << endl;

	RingBuffer<int> Buffer1(3);
	Buffer1.add(1);
	Buffer1.add(3);
	Buffer1.add(2);
	Buffer1.add(4);
	for (int i = 0; i != Buffer1.size(); i++) {
		cout << Buffer1.get(i);
	}

	cout << endl;

	return 0;
}