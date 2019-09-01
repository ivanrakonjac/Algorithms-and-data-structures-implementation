#include "BinHeap.h"
#include <fstream>
#include "PerformanceCalculator.h"


int main() {
/*
Node n1(12, 1);
Node n2(7, 2);
Node n3(15, 3);
Node n4(18, 1);
Node n5(3, 2);
Node n6(21, 4);
Node n7(22, 5);


BinHeap h;

h=h.dodaj(n1);
h=h.dodaj(n2);
h=h.dodaj(n3);

cout << "h1: ";
h.ispis();

BinHeap h2;

h2 = h2.dodaj(n4);
h2 = h2.dodaj(n5);

cout << "h2: ";
h2.ispis();

BinHeap h3;
h3=h.mergeHeaps(h2);
h3.ispis();

cout << "h1: ";
h.ispis();
cout << "h2: ";
h2.ispis();


//h = h.Unija(h2);
//h.ispis();

h=h.add(18);
h.ispis();
h = h.add(90);
h.ispis();
h = h.add(26);
h.ispis();
h = h.add(38);
h.ispis();
h = h.add(45);
h.ispis();
h = h.add(84);
h.ispis();
h = h.add(66);
h.ispis();
h = h.add(64);
h.ispis();
h = h.add(70);
h.ispis();
h = h.add(75);
h.ispis();
*/
PerformanceCalculator pc;
double protekloVreme;

ifstream file;
int steps = 0;
BinHeap h;
/*
cout << "Min = " <<h.getMin()<<endl;

h.ispis();
h = h.deleteMin();
h.ispis();

h = h.deleteMin();
h.ispis();

pc.start();
h.destroy(steps);
pc.stop();
protekloVreme = pc.elapsedMillis();
cout << "Vreme: " << protekloVreme << endl;

h.ispis();
*/
while (true) {
	int b;
	cout <<endl<< "-----MENI-----" << endl;
	cout << endl;
	cout << "1) Stvaranje reda" << endl;
	cout << "2) Da li je red prazan" << endl;
	cout << "3) Brisanje celog hipa" << endl;
	cout << "4) Brisanje min-a" << endl;
	cout << "5) Umetanje elementa u hip" << endl;
	cout << "6) Dohvati min bez brisanja" << endl;
	cout << "7) Izlaz" << endl;

	cout << endl << "Vas izbor? ";
	cin >> b;

	switch (b)
	{
	case 1:
		file.open("test_10.txt");
		int i;

		while (file >> i) {
			//cout << i << endl;
			h = h.add(i, steps);
			//h.ispis();
		}
		cout<<endl << "Hip:"<< endl;
		h.ispis();

		file.close();
		break;
	case 2:
		if (h.getHead() == nullptr) {
			cout << "Red je prazan" << endl;
		}
		else {
			cout << "Red nije prazan" << endl;
		}
		break;
	case 3:
		h=h.destroy(steps);
		break;
	case 4:
		cout << endl << "Min = " << h.getMin() << endl;
		h = h.deleteMin(steps);
		h.ispis();
		cout << endl << "Hip:" << endl;
		h.ispis();
		break;
	case 5:
		int x;
		cout << "Unesite vrednost ";
		cin >> x;
		h = h.add(x,steps);
		cout << endl << "Hip:" << endl;
		h.ispis();
		break;
	case 6:
		cout << endl << "Min = " << h.getMin() << endl;
		break;
	case 7:
		exit(1);
		break;
	default:
		break;
	}
}
system("pause");
return 0;
}