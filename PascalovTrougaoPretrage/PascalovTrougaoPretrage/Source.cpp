#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

long long int factorial(int n)
{
	long double f = 1;

	for (int i = n;i > 0;i--) {
		f = f * i;
	}

	return f;
}

long long int* formReda(int n) {
	long long int* red = new long long int[n+1];
	long long int nf=factorial(n);
	long long int kf, izrazf;

	for (int k = 0; k <= n; k++)
	{
		kf = factorial(k);
		izrazf = factorial(n-k);
		red[k]=nf/(kf*izrazf);
	}

	return red;
}

long double* formReda2(long double n) {
	long double* red = new long double[n + 1];
	red[0] = 1;
	for (int k = 1; k <= n; k++)
	{
		red[k] = red[k - 1] * ((n - k + 1) / k);
	}

	return red;
}

void ispis(long double* red,int n) {
	
	cout << endl;
	for (int i=0;i <= n;i++) {
		cout << red[i] <<fixed<< setprecision(0) <<" ";
	}
	cout << endl;
}

int ternarna(long double* red, long double key, int n) {
	int mid = 0, low = 0, high = n, mid1 = 0, mid2 = 0, korak = 0;

	auto start = chrono::steady_clock::now();

	mid = low + (high - low) / 2;
	high = mid;

	while (low <= high) {
		korak = (high - low) / 3;
		mid1 = low + korak;
		mid2 = high - korak;

		if (key == red[low]) { 
			cout << endl<< "Kljuc nadjen" << endl;
			auto end = chrono::steady_clock::now();
			auto diff = end - start;
			cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
			return low;
		}
		if (key == red[high]){
			cout << endl << "Kljuc nadjen" << endl;
			auto end = chrono::steady_clock::now();
			auto diff = end - start;
			cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
			return high;
		}
		if (red[mid1] == key) {
			cout << endl << "Kljuc nadjen" << endl;
			auto end = chrono::steady_clock::now();
			auto diff = end - start;
			cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
			return mid1;
		}
		if (red[mid2] == key) {
			cout << endl << "Kljuc nadjen" << endl;
			auto end = chrono::steady_clock::now();
			auto diff = end - start;
			cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
			return mid2;		
		}
		
		if (key > red[mid1]&&key < red[mid2]) {
			low = mid1 + 1;
			high = mid2 - 1;
		}
		else if(key<red[mid1])
		{
			high = mid1 - 1;
		}
		else if (key>red[mid2])
		{
			low = mid2 + 1;
		}
	}

	if (low == high) {
		cout <<endl<< "Trazeni kljuc ne postoji." << endl;
	}

	cout << endl << "Trazeni kljuc ne postoji." << endl;
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;

	return 0;
}

int interpolaciono(long double* red, long double key, int n) {
	int mid = 0, high = n, low = 0 ;
	
	/*
	if (key<red[low] || key>red[high]) {
		cout << "Kljuc ne postoji!";
		return -1;
	}*/

	auto start = chrono::steady_clock::now();

	mid = low + (high - low) / 2;
	high = mid;

	while (low <= high) {
		mid = low + (int)((high - low)*((double)(key - red[low]) / (red[high] - red[low])));
		if (key == red[mid]) {
			cout << endl << "Kljuc nadjen" << endl;
			auto end = chrono::steady_clock::now();
			auto diff = end - start;
			cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
			return 1;
		}
		else if (key < red[mid]) {
			high = mid - 1;
		}
		else if (key > red[mid]) {
			low = mid + 1;
		}
	}

	if (low == high) {
		cout << endl << "Trazeni kljuc ne postoji." << endl;
		return 0;
	}

	cout << endl << "Trazeni kljuc ne postoji." << endl;
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
	
	

	return 0;
}

int hibridno(long double* red, long double key, int n) {
	int mid = 0, low = 0, high = n, mid1 = 0, mid2 = 0;
	long long int korak = 0;

	auto start = chrono::steady_clock::now();

	mid = low + (high - low) / 2;
	high = mid;

	while (low <= high) {

		if (key == red[low]) {
			cout << endl << "Kljuc nadjen" << endl;
			auto end = chrono::steady_clock::now();
			auto diff = end - start;
			cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
			return low;
		}
		if (key == red[high]) {
			cout << endl << "Kljuc nadjen" << endl;
			auto end = chrono::steady_clock::now();
			auto diff = end - start;
			cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
			return high;
		}

		korak = (high - low) / 3;
		mid1 = low + korak;
		mid2 = high - korak;

		if (key > red[mid1] && key < red[mid2]) {
			low = mid1 + 1;
			high = mid2 - 1;
		}
		else if (key<red[mid1])
		{
			high = mid1 - 1;
		}
		else if (key>red[mid2])
		{
			low = mid2 + 1;
		}
		else {
			if (key == red[low]) {
				cout << endl << "Kljuc nadjen" << endl;
				auto end = chrono::steady_clock::now();
				auto diff = end - start;
				cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
				return low;
			}
			if (key == red[high]) {
				cout << endl << "Kljuc nadjen" << endl;
				auto end = chrono::steady_clock::now();
				auto diff = end - start;
				cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
				return high;
			}
			if (red[mid1] == key) {
				cout << endl << "Kljuc nadjen" << endl;
				auto end = chrono::steady_clock::now();
				auto diff = end - start;
				cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
				return mid1;
			}
			if (red[mid2] == key) {
				cout << endl << "Kljuc nadjen" << endl;
				auto end = chrono::steady_clock::now();
				auto diff = end - start;
				cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
				return mid2;
			}
		}
	
		mid = low + (int)((high - low)*((double)(key - red[low]) / (red[high] - red[low])));
		if (key == red[mid]) {
			cout << endl << "Kljuc nadjen" << endl;
			auto end = chrono::steady_clock::now();
			auto diff = end - start;
			cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
			return 1;
		}
		else if (key < red[mid]) {
			high = mid - 1;
		}
		else if (key > red[mid]) {
			low = mid + 1;
		}

	}

	if (low == high) {
		cout << endl << "Trazeni kljuc ne postoji." << endl;
		return 0;
	}

	cout << endl << "Trazeni kljuc ne postoji." << endl;
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;

	return 0;
}





int main() {
	
	int izbor = 0,n=0;
	long double* red=nullptr;
	long double key = 0;

	while (true) {

		cout << endl;
		cout << "MENI: " << endl;
		cout << "1) Unos rednog broja reda za pretrazivanje" << endl;
		cout << "2) Unos kljuca za pretragu"<<endl;
		cout << "3) Ispis reda koji treba pretraziti" << endl;
		cout << "4) Ternarna pretraga" << endl;
		cout << "5) Interpolaciona pretraga" << endl;
		cout << "6) Hibridna pretraga" << endl;
		cout << "7) Kraj" << endl;

		cout <<endl<< "Vas izbor? ";
		cin >> izbor;
	
		switch (izbor)
		{
		case 1:
			if (red != nullptr) {
				delete[] red;
				n = 0;
			}
			cout <<endl<< "Unesite redni broj reda za pretrazivanje" << endl;
			cin >> n;

			red = formReda2(n);
			break;
		case 2:
			cout << endl << "Unesite kljuc za pretragu." << endl;
			cin >> key;
			break;
		case 3:
			if (red != nullptr) {
			ispis(red, n);
			}
			else {
				cout << endl << "Red je obrisan ili jos nije formiran." << endl;
			}
			break;
		case 4:
			ternarna(red, key, n);
			break;
		case 5:
			interpolaciono(red, key, n);
			break;
		case 6:
			hibridno(red, key, n);
			break;
		case 7:
			exit(1);
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

/*
if (red[mid1+1] == key) {
cout << endl << "Kljuc nadjen" << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
return mid1+1;
}
if (red[mid2 + 1] == key) {
cout << endl << "Kljuc nadjen" << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
return mid2 + 1;
}
if (red[mid1 - 1] == key) {
cout << endl << "Kljuc nadjen" << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
return mid1 - 1;
}
if (red[mid2 + 1] == key) {
cout << endl << "Kljuc nadjen" << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
return mid2 - 1;
}
if (red[high- 1] == key) {
cout << endl << "Kljuc nadjen" << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
return high - 1;
}
if (red[low + 1] == key) {
cout << endl << "Kljuc nadjen" << endl;
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
return low+1;
}
*/