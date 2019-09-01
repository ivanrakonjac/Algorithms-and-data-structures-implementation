#ifndef NODE_H
#define NODE_H

using namespace std;
#include <iostream>

class Node
{
private:
	int key;
	int stepen;
public:
	Node(int k = 0, int s = 0);
	~Node();

	int getKey() const {
		return key;
	}
	int getStepen() const {
		return stepen;
	}

	void setKey(int k) {
		key = k;
	}
	void setStepen(int s) {
		stepen = s;
	}
	/*
	void setOtac(Node* o) {
	otac = o;
	}
	void setLevo(Node* l) {
	levo = l;
	}
	void setDesno(Node* d) {
	desno = d;
	}
	void setDole(Node* d) {
	dole=d;
	}*/
};
#endif