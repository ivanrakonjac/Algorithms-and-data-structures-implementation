#include "BinHeap.h"



BinHeap::BinHeap()
{
	head = nullptr;
	last = nullptr;
}

BinHeap::BinHeap(const BinHeap & bh)
{
	Elem* tek = bh.head;
	Elem* novi;

	while (tek) {
		novi = new Elem(tek->n);

		if (head == nullptr) {
			head = novi;
			last = head;
		}
		else {
			last->desno = novi;
			last = last->desno;
		}
		tek = tek->desno;
	}
}
/*
BinHeap::BinHeap(BinHeap && bh)
{
	head = bh.head;
	last = bh.last;
	bh.head = bh.last = nullptr;
}*/


BinHeap::~BinHeap()
{/*
	Elem* tek;
	while (head) {
		tek = head;
		head = head->desno;
		head->levo = nullptr;
		delete tek;
	}*/
}
