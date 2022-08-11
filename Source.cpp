#include"RingBuffer.h"

int main(){


	RingBuffer<int> Buffer1(3);
	Buffer1.add(1);
	Buffer1.add(3);
	Buffer1.add(2);
	Buffer1.add(4);
	for (RingBuffer<int>::Iterator it = Buffer1.begin(); it != Buffer1.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
	for (int i = 0; i != Buffer1.size(); i++) {
		cout << Buffer1.get(i);
	}

	cout << endl;

	return 0;
}