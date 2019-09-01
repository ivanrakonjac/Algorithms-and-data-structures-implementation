#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node {
	Node* left = nullptr;
	Node* right = nullptr;
	int key;
};

Node* umetanje(int novi, Node* root) {
	Node* p = root;
	Node* q = nullptr;
	Node* temp = nullptr;
	int c = 0;

	while (p != nullptr) {
		q = p;
		if (novi == p->key) {
			while (true) {
				if (p->left != nullptr) {
					if (p->left->key == p->key) {
						p = p->left;
					}
					else if (p->left->key < p->key) {
						c = 1;
						break;
					}
				}
				else {
					c = 1;
					break;
				}
			}
		}
		else if (novi < p->key) {
			p = p->left;
		}
		else {
			p = p->right;
		}

		if (c == 1) break;
	}

	if (q == nullptr) {
		root = new Node;
		root->key = novi;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (novi == q->key) {
		temp = new Node;
		temp->key = novi;
		temp->left = q->left;
		temp->right = nullptr;
		q->left = temp;
	}
	else if (novi < q->key) {
		q->left = new Node;
		q->left->key = novi;
		q->left->left = nullptr;
		q->left->right = nullptr;
	}
	else{
		q->right = new Node;
		q->right->key = novi;
		q->right->left = nullptr;
		q->right->right = nullptr;
	}

	return root;
}

void stampanje(Node* root) {
	Node* next = root;
	queue <Node*> red;

	if (root == nullptr) {
		cout << endl << "Stablo je obrisano ili nije formirano!" << endl;
	}
	else {
		red.push(next);
		while (!red.empty()) {
			next=red.front();
			red.pop();
			cout << next->key<<" ";
			if (next->left != nullptr) {
				red.push(next->left);
			}
			if (next->right != nullptr) {
				red.push(next->right);
			}
		}
	}
}

Node* brisanjeStabla(Node* root) {
	Node* next = root;
	queue <Node*> red;

	if (root == nullptr) {
		cout << endl << "Stablo je obrisano ili nije formirano!" << endl;
	}
	else {
		red.push(next);
		while (!red.empty()) {
			next = red.front();
			red.pop();

			if (next->left != nullptr) {
				red.push(next->left);
			}
			if (next->right != nullptr) {
				red.push(next->right);
			}

			delete next;
		}
	}
	return nullptr;
}

Node* search(Node* root, int key) {
	Node* p = root;

	while ((p != nullptr) && (key != p->key)) {
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	return p;
}

int inorder(Node* root) {
	Node* next = root;
	stack <Node*> s;
	int brojac = 1;
	int prethodni = 0;
	int maxPon = 0;
	int maxVal = 0;
	
	while (1) {
		while (next != nullptr) {
			s.push(next);
			next = next->left;
		}
		if (!s.empty()) {
			next = s.top();
			if (prethodni == next->key) {
				brojac++;
			}
			else {
				if (brojac > maxPon) {
					maxPon = brojac;
					maxVal = prethodni;
					brojac = 1;
				}
			}
			prethodni = next->key;
			s.pop();
			cout << next->key << " ";
			next = next->right;
		}
		else {
			if (brojac > maxPon) {
				maxPon = brojac;
				maxVal = prethodni;
				brojac = 1;
			}
			return maxVal;
		}
	}

	return maxVal;
}

bool brisanjeKljuca(Node* root, int key) {
	Node* p = root;
	Node* q = nullptr;
	Node* rp = nullptr;
	Node* f = nullptr;
	Node* s = nullptr;

	while ((p != nullptr) && (p->key != key)) {
		q = p;
		if (key < p->key) p=p->left;
		else p = p->right;
	}

	if (p == nullptr) {
		cout << endl << "Neuspesna pretraga!" << endl;
		return false;
	}
	
	if (p->left == nullptr) {
		rp = p->right;
	}
	else if (p->right == nullptr) {
		rp = p->left;
	}
	else {
		f = p;
		rp = p->right;
		s = rp->left;
		while (s != nullptr) {
			f = rp;
			rp = s;
			s = rp->left;
		}
		if (f != p) {
			f->left = rp->right;
			rp->right = p->right;
		}
		rp->left = p->left;
	}

	if (q == nullptr) root = rp;
	else if (p == q->left) {
		q->left=rp;
	}
	else {
		q->right = rp;
	}

	delete p;

	return true;
	
}



int main() {
	
	Node* root = nullptr;
	Node* s = nullptr;
	int izbor = 0,novi=0,brEl = 0,key=0,maxVal=0;
	bool check = false;

	while (true)
	{
		cout << endl << "MENI:" << endl;
		cout << "1) Formiranje stabla" << endl;
		cout << "2) Pretraga stabla" << endl;
		cout << "3) Umetanje " << endl;
		cout << "4) Ispis " << endl;
		cout << "5) Brisanje kljuca " << endl;
		cout << "6) Brisanje stabla " << endl;
		cout << "7) Kljuc sa najvecim br ponavljanja " << endl;
		cout << "8) Kraj " << endl;
		
		cout <<endl << "Vas izbor? ";
		cin >> izbor;
		cout << endl;

		switch (izbor)
		{
		case 1:
			cout <<endl<< "Sa koliko elemenata zelite da formirate stablo? ";
			cin >> brEl;
			cout << endl;
			for (int i = 0; i < brEl; i++)
			{
				cout << "Vrednost kljuca? ";
				cin >> novi;
				root = umetanje(novi, root);
			}
			break;
		case 2:
			cout << "Vrednost kljuca za pretragu? ";
			cin >> key;
			s=search(root, key);

			if (s == nullptr) {
				cout << endl << "Neuspesna pretraga!" << endl;
			}
			else if (s->key == key) {
				cout << endl << "Uspesna pretraga!" << endl;
			}
			break;
		case 3:
			cout << "Vrednost kljuca? ";
			cin >> novi;
			root = umetanje(novi, root);
			break;
		case 4:
			stampanje(root);
			break;
		case 5:
			cout << "Vrednost kljuca? ";
			cin >> key;
			check=brisanjeKljuca(root,key);
			if (check) {
				cout << endl << "Uspesno brisanje!" << endl;
			}
			break;
		case 6:
			root=brisanjeStabla(root);
			cout <<endl<< "Stablo je obrisano!" << endl;
			break;
		case 7:
			maxVal=inorder(root);
			cout << endl << "Element sa najvise ponavljanaj je: " << maxVal << endl;
			break;
		case 8:
			exit(1);
		default:
			break;
		}
	}

	return 0;
}