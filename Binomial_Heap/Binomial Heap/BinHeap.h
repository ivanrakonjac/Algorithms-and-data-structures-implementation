#ifndef BINHEAP_H
#define BINHEAP_H

#include "Node.h"

class BinHeap
{
private:

	struct Elem {
		Node n;
		Elem *otac, *levo, *desno, *dole;
		Elem(Node& no) :n(no) {
			otac = levo = desno = dole = nullptr;
		}
	};

	Elem * head;
	Elem* last;

public:
	BinHeap();
	BinHeap(const BinHeap& bh);
	//BinHeap(BinHeap&& bh);
	~BinHeap();

	Elem* getHead() {
		return head;
	}
	void setHead(Elem* e) {
		head = e;
	}


	BinHeap& dodaj(Node n) {
		Elem *novi = new Elem(n);

		if (head == nullptr) {
			head = novi;
			last = head;
		}
		else {
			last->desno = novi;
			last = last->desno;
		}

		return *this;
	}

	void ispis() const {

		if (head == nullptr) {
			cout << endl << "Heap nije formiran ili je obrisan!" << endl;
		}
		Elem* temp = head;
		while (temp) {
			cout << temp->n.getStepen() << " ";
			temp = temp->desno;
		}
		cout << endl;

	}

	BinHeap& mergeHeaps(BinHeap& h2){

		Elem* a = nullptr;
		Elem* b = nullptr;
		Elem* c = nullptr;
		bool p = false, d = false;
		BinHeap h3;

		if (head == nullptr && h2.head != nullptr) {
			//h3= h2;
			return h2;
		}
		else if (head != nullptr && h2.head == nullptr) {
			//h3 = *this;
			return *this;
		}
		else if (head->n.getStepen() >= h2.head->n.getStepen()) {
			b = head;
			a = h2.head;
			p = true;
		}
		else {
			b = h2.head;
			a = head;
			d = true;
		}

		while (b) {
			if (a->desno == nullptr) {
				a->desno = b;
				b = nullptr;
			}
			else if (a->desno->n.getStepen() < b->n.getStepen()) {
				a = a->desno;
			}
			else {
				c = b->desno;
				b->desno = a->desno;
				a->desno = b;
				a = a->desno;
				b = c;
			}
		}

		if (p) {
			//h3 = h2;
			return h2;
		}
		if (d) {
			//h3 = *this;
			return *this;
		}

		//return h3;
	}

	friend void povezi(Elem* y, Elem* z) {
		if (y != nullptr)
		{
			y->otac = z;
			y->desno = z->dole;

		}
		z->dole = y;

		z->n.setStepen(z->n.getStepen()+1);
	}
	
	BinHeap& Unija(BinHeap& h2,int &steps) {
		BinHeap h;
		if (this->head != nullptr) {
			if (this->head->n.getKey() == -572662307) {
				this->head = nullptr;
			}
		}
		h = mergeHeaps(h2);
		if (h.head == nullptr) {
			cout << "h.head==nullptr" << endl;
			return h;
		}
		
		Elem* x = h.head;
		Elem* prevX = nullptr;
		Elem* nextX = x->desno;

		bool c = false;
		
		while (nextX!=nullptr) {
			c = false;
			steps++;

			if (((x->n.getStepen()) != (nextX->n.getStepen()))||((nextX->desno!=nullptr)&& (nextX->desno->n.getStepen()==x->n.getStepen()))) {
				prevX = x;
				x = nextX;
			}
			else if (x->n.getKey() <= nextX->n.getKey()) {
				x->desno = nextX->desno;
				povezi(nextX, x);
				nextX = x->desno;
				c = true;
			}
			else if (prevX == nullptr) {
				h.head = nextX;
				povezi(x, nextX);
				x = nextX;
			}
			else {
				prevX->desno = nextX;
				povezi(x, nextX);
				x = nextX;	
			}
			if(!c)
				nextX = nextX->desno;
			
		}
		h2 = h;
		return h2;
		
	}

	BinHeap& add(int v,int &steps) {
		BinHeap h2;
		BinHeap h3;
		steps++;
		Node x(v, 0);
		Elem *novi = new Elem(x);
		h2.setHead(novi);
		h3=Unija(h2,steps);

		return h3;
	}

	int getMin() {
		Elem* temp = head;
		int min=100000;

		while (temp) {
			if (temp->n.getKey() < min) {
				min = temp->n.getKey();
			}
			temp = temp->desno;
		}

		return min;
	}

	BinHeap& deleteMin(int& steps) {
		Elem* temp = head;
		Elem* prev = nullptr;
		Elem* minPrev = nullptr;
		Elem* min = head;

		while (temp) {
			if (temp->n.getKey() < min->n.getKey()) {
				min = temp;
				minPrev = prev;
			}
			prev = temp;
			temp = temp->desno;
		}

		if ((min == head)&&(min->dole==nullptr)&&(min->desno!=nullptr)) {
			head = head->desno;
			min->desno = nullptr;
			delete min;

			return *this;
		}
		
		if(minPrev!=nullptr)
			minPrev->desno = min->desno;
	


		prev = min->dole;
		temp = min->dole->desno;
		Elem* next = temp->desno;

		prev->desno = nullptr;

		if (next == nullptr) {
			temp->desno = prev;
		}
		else {
			while (next) {
				temp->desno = prev;
				prev = temp;
				temp = next;
				next = next->desno;
			}
			temp->desno = prev;
		}
		/*
		ispis
		while (temp) {
			cout << temp->n.getKey() << " ";
			temp = temp->desno;
		}
		cout << endl;
		*/
		min->desno = nullptr;
		min->dole = nullptr;
		delete (min);
		//cout << "this:" << endl;

		BinHeap h2;
		h2.head = temp;
		*this = Unija(h2, steps);

		return *this;
	}

	BinHeap& destroy(int &steps) {
		Elem* temp = head;
		Elem* temp2 = nullptr;
		
		while (temp) {
			steps++;
			if (temp->dole != nullptr) {
				temp = temp->dole;
			}
			else if (temp->desno != nullptr) {
				temp2 = temp;
				temp = temp->desno;
				delete temp2;
			}
			else if (temp->otac != nullptr) {
				temp2 = temp;
				temp = temp->otac;
				temp->dole = nullptr;
				delete temp2;
			}
			else {
				delete temp;
				temp = nullptr;
			}
		}
		head = temp;
		return *this;
	}

	BinHeap& convert() {
			
	}
};
#endif

