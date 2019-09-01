#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// C Program to shuffle a given array

// A utility function to swap to integers
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// A utility function to print an array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// A function to generate a random permutation of arr[]
void randomize(int arr[], int n)
{
	// Use a different seed value so that we don't get same
	// result each time we run this program
	srand(time(NULL));

	// Start from the last element and swap one by one. We don't
	// need to run for the first element that's why i > 0
	for (int i = n - 1; i > 0; i--)
	{
		// Pick a random index from 0 to i
		int j = rand() % (i + 1);

		// Swap arr[i] with the element at random index
		swap(&arr[i], &arr[j]);
	}
}
//End of C Program to shuffle a given array

char** setovanjeMatrice(char** matrica, int m, int n, char c) {
	int i = 0, j = 0;

	printf("\n");
	matrica = (char*)malloc(m * sizeof(char*));
	for (i = 0; i < m; i++) {
		matrica[i] = (char*)malloc(n * sizeof(char));
		for (j = 0; j < n; j++)
		{
			matrica[i][j] = c;
		}

	}
	return matrica;
}

void stampaj(char** matrica, int m, int n) {
	int i = 0, j = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c", matrica[i][j]);
		}
		printf("\n");
	}
}

void mogucnosti(char** matrica, int* mog, int x, int y, int m, int n) {
	char c = 255;
	if (x + 2 < n) {
		if (matrica[x + 2][y] == c) { mog[0] = 0; }
		else mog[0] = 1;
	}
	else {
		mog[0] = 0;
	}

	if (x - 2 > 0) {
		if (matrica[x - 2][y] == c) { mog[1] = 0; }
		else mog[1] = 1;
	}
	else {
		mog[1] = 0;
	}

	if (y + 2 < m) {
		if (matrica[x][y + 2] == c) { mog[2] = 0; }
		else mog[2] = 1;
	}
	else {
		mog[2] = 0;
	}

	if (y - 2 > 0) {
		if (matrica[x][y - 2] == c) { mog[3] = 0; }
		else mog[3] = 1;
	}
	else {
		mog[3] = 0;
	}

}

void DFS(char** matrica, int j, int k, int m, int n) {
	int x = j, y = k, b = 0, rnd = 0, g = 0, i = 0, p = 0;
	int arr[] = { 0,1, 2, 3 };
	char c = 178;
	int* stek;
	int mog[4];//mogucnosti

	stek = (int*)malloc(2 * m*n * sizeof(int));

	while (b >= 0) {//dok stek nije prazan

		i = 0;p = 0;
		//ako cvor nije posecen
		if (matrica[x][y] == c) {
			matrica[x][y] = 255;
			stek[b] = x;b++; //x kordinata ide na stek
			stek[b] = y;b++; //y kordinata ide na stek
		}
		//dobio sam mogucnosti
		mogucnosti(matrica, mog, x, y, m, n);

		//sad imam niz sa random rasporedom 0123
		g = sizeof(arr) / sizeof(arr[0]);
		randomize(arr, g);
		//printArray(arr, g);

		//ako nema opcija
		if ((mog[0] == 0) && (mog[1] == 0) && (mog[2] == 0) && (mog[3] == 0)) { p = 5; }
		else {
			while (mog[arr[i]] != 1) i++;
			p = arr[i];
		}

		if (p == 0) {
			x = x + 2;
			matrica[x - 1][y] = 255;
		}
		else if (p == 1) {
			x = x - 2;
			matrica[x + 1][y] = 255;
		}
		else if (p == 2) {
			y = y + 2;
			matrica[x][y - 1] = 255;
		}
		else if (p == 3) {
			y = y - 2;
			matrica[x][y + 1] = 255;
		}
		else {
			b--;
			y = stek[b];
			b--;
			x = stek[b];
			//b--;
		}

		//printf("x=%d y=%d\n", x, y);

	}
}

int main() {
	int i = 0, j = 0, m = 0, n = 0, g = 0, xr = 0, yr = 0, x = 0, y = 0, brojac = 0,brojac2=0;
	char c = 178;
	char **matrica = NULL;
	int numbers[4];//za broj mogucnosti

	int opcija = 0;
	int xu = 0, yu = 0, xi, yi;
	int* izlazi = NULL;
	int brojIzlaza = 1, brKordProlaza = 0;

	char cc = 255;
	char cc1 = 255, cc2 = 176, cc3 = 177;
	int* stack = NULL;
	int* stack2 = NULL;

	int koordinate = 0;

	int xp = 0, yp = 0, xj = 0, yj = 0;

	while (1) {

		opcija = 0;

		printf("\n***********MENI***********\n");
		printf("1)  Napravi lavirint rucno\n");
		printf("2)  Generisi lavirint pomocu DFS-a\n");
		printf("3)  Ispisi lavirint\n");
		printf("4)  Resi lavirint\n");
		printf("5)  Nadji Pericu\n");
		printf("6)  Obrisi lavirint\n");
		printf("7)  Kraj\n");

		printf("\nOdaberi jednu od opcija.\n");
		scanf_s("%d", &opcija);

		if ((opcija < 1) || (opcija > 7)) {
			printf("\nMorate odabrati jednu od ponudjenih opcija!\n");
		}
		else if (opcija == 7) {
			if (matrica != NULL) {
				for (i = 0;i < m;i++) {
					free(matrica[i]);
				}
				free(matrica);
				matrica = NULL;
			}
			exit(1);
		}
		else {

			switch (opcija)
			{
			case 1:
				if (matrica == NULL) {
					printf("\nUnesite broj vrsta: ");
					scanf("%d", &m);

					printf("\nUnesite broj kolona: ");
					scanf("%d", &n);

					m = m * 2 + 1;
					n = n * 2 + 1;

					//setovanje matrice
					matrica = setovanjeMatrice(matrica, m, n, c);

					printf("\nUnesite koordinate ulaza\n");
					printf("x= ");
					scanf("%d", &xu);
					printf("y= ");
					scanf("%d", &yu);

					if ((xu % 2 == 0) || (yu % 2 == 0)) {
						printf("\nUneli ste koridinate zida.\nUnesite ponovo koordinate ulaza\n");
						printf("x= ");
						scanf("%d", &xu);
						printf("y= ");
						scanf("%d", &yu);
					}
					matrica[yu][xu] = 176;

					izlazi = (int*)malloc(2 * brojIzlaza * sizeof(int));

					printf("\nUnesite broj izlaza: ");
					scanf("%d", &brojIzlaza);

					printf("\n");
					for (i = 0;i < 2 * brojIzlaza;i = i + 2) {
						printf("Unesite koordinate %d. izlaza\n", i + 1);
						printf("x= ");
						scanf("%d", &xi);
						printf("y= ");
						scanf("%d", &yi);
						if ((xi % 2 == 0) || (yi % 2 == 0)) {
							printf("\nUneli ste koridinate zida.\nUnesite ponovo koordinate izlaza\n");
							printf("x= ");
							scanf("%d", &xi);
							printf("y= ");
							scanf("%d", &yi);
						}
						izlazi[i] = xi;
						izlazi[i + 1] = yi;
						matrica[yi][xi] = 176;
					}

					printf("Unesite broj kordinata prolaza koje zelite da unesete\n");
					scanf("%d", &brKordProlaza);

					for (i = 0;i < brKordProlaza;i++) {
						printf("Unesite kordinate prolaza\n", i + 1);
						scanf("%d %d", &xr, &yr);
						matrica[yr][xr] = 255;
					}
				}
				else {
					printf("\nMatrica je formirana, ako zelite da je formirate rucno prvo je obrisite.\n");
				}

				break;
			case 2:
				koordinate == 0;

				if (matrica == NULL) {
					printf("\nUnesite broj vrsta: ");
					scanf("%d", &m);

					printf("\nUnesite broj kolona: ");
					scanf("%d", &n);

					stack = (int*)malloc(2 * m*n * sizeof(int));
					stack2 = (int*)malloc(2 * m*n * sizeof(int));

					m = m * 2 + 1;
					n = n * 2 + 1;

					//setovanje matrice
					matrica = setovanjeMatrice(matrica, m, n, c);

					printf("\nUnesite koordinate ulaza\n");
					printf("x= ");
					scanf("%d", &xu);
					printf("y= ");
					scanf("%d", &yu);

					if ((xu % 2 == 0) || (yu % 2 == 0)) {
						printf("\nUneli ste koridinate zida.\nUnesite ponovo koordinate ulaza\n");
						printf("x= ");
						scanf("%d", &xu);
						printf("y= ");
						scanf("%d", &yu);
					}
					matrica[yu][xu] = cc3;
					
					izlazi = (int*)malloc(2 * brojIzlaza * sizeof(int));

					printf("\nUnesite broj izlaza: ");
					scanf("%d", &brojIzlaza);

					printf("\n");
					for (i = 0;i < 2 * brojIzlaza;i = i + 2) {
						printf("Unesite koordinate izlaza\n");
						printf("x= ");
						scanf("%d", &xi);
						printf("y= ");
						scanf("%d", &yi);
						if ((xi % 2 == 0) || (yi % 2 == 0)) {
							printf("\nUneli ste koridinate zida.\nUnesite ponovo koordinate izlaza\n");
							printf("x= ");
							scanf("%d", &xi);
							printf("y= ");
							scanf("%d", &yi);
						}
						izlazi[i] = xi;
						izlazi[i + 1] = yi;
						
						matrica[yi][xi] = cc2;
					}

					printf("\n");
					stampaj(matrica, m, n);

					DFS(matrica, xu, yu, m, n);

				}
				else {
					printf("\nMatrica je formirana, ako zelite da je generisete prvo je obrisite.\n");
				}
				break;
			case 3:
				if (matrica == NULL) {
					printf("\nMatrica jos nije formirana ili je obrisana.\n");
				}
				else {
					printf("\n");
					stampaj(matrica, m, n);
				}
				break;
			case 4:
				brojac = 0;
				if (matrica == NULL) {
					printf("\nMatrica jos nije formirana ili je obrisana.\n");
				}
				else {
					//char cc1 = 255, cc2 = 176-izlaz, cc3 = 177;

					
					//stampaj(matrica, m, n);

					if (koordinate == 0) {
						x = xu;y = yu;
					}
					else {
						x = xp;y = yp;
						for (i = 0;i < m;i++) {
							for (j = 0;j < n;j++) {
								if ((matrica[i][j] == '*')|| (matrica[i][j] == 'J')) {
									matrica[i][j] = cc1;
								}
							}
							matrica[yp][xp] = cc3;
							matrica[yi][xi] = cc2;
						}
						stampaj(matrica, m, n);

						scanf("%d", &i);
					}
					
					
					stack[brojac] = x; brojac++;
					stack[brojac] = y; brojac++;
					while (brojac>=0) {

						if ((y + 1 < m) && ((matrica[y + 1][x] == cc1) || (matrica[y + 1][x] == cc2) || (matrica[y + 1][x] == cc3))) {

							y = y + 1;
							stack[brojac] = x; brojac++;
							stack[brojac] = y; brojac++;
							if (matrica[y][x] == cc2) {
								printf("\nObrada je gotova!\n");
								break;
							}
							matrica[y][x] = '*';
							//stampaj(matrica, m, n);
						}
						else if ((x + 1 < n) && ((matrica[y][x + 1] == cc1) || (matrica[y][x + 1] == cc2) || (matrica[y][x + 1] == cc3))) {

							x = x + 1;
							stack[brojac] = x; brojac++;
							stack[brojac] = y; brojac++;
							if (matrica[y][x] == cc2) {
								printf("\nObrada je gotova!\n");
								break;
							}
							matrica[y][x] = '*';

							//stampaj(matrica, m, n);
						}
						else if ((y - 1 > 0) && ((matrica[y - 1][x] == cc1) || (matrica[y - 1][x] == cc2) || (matrica[y - 1][x] == cc3))) {

							y = y - 1;
							stack[brojac] = x; brojac++;
							stack[brojac] = y; brojac++;
							if (matrica[y][x] == cc2) {
								printf("\nObrada je gotova!\n");
								break;
							}
							matrica[y][x] = '*';

							//stampaj(matrica, m, n);
						}
						else if ((x - 1 > 0) && ((matrica[y][x - 1] == cc1) || (matrica[y][x - 1] == cc2) || (matrica[y][x - 1] == cc3))) {

							x = x - 1;
							stack[brojac] = x; brojac++;
							stack[brojac] = y; brojac++;
							if (matrica[y][x] == cc2) {
								printf("\nObrada je gotova!\n");
								break;
							}
							matrica[y][x] = '*';

							//stampaj(matrica, m, n);
						}
						else {
							brojac--;
							y = stack[brojac];
							brojac--;
							x = stack[brojac];
							//b--;
						}
					}
					//end_while
					//free(stack);
				}
				//end_if
				break;
			case 5:
				brojac2 = 0;
				koordinate = 1;
				if (matrica == NULL) {
					printf("\nMatrica jos nije formirana ili je obrisana.\n");
				}
				else {
					//char cc1 = 255, cc2 = 176-izlaz, cc3 = 177;

					printf("\nUnesite koordinate Perice\n");
					printf("x= ");
					scanf("%d", &xp);
					printf("y= ");
					scanf("%d", &yp);

					if ((xp % 2 == 0) || (yp % 2 == 0)) {
						printf("\nUneli ste koridinate zida.\nUnesite ponovo koordinate ulaza\n");
						printf("x= ");
						scanf("%d", &xp);
						printf("y= ");
						scanf("%d", &yp);
					}
					matrica[yp][xp] = 'P';

					printf("\nUnesite koordinate Jovice\n");
					printf("x= ");
					scanf("%d", &xj);
					printf("y= ");
					scanf("%d", &yj);

					if ((xj % 2 == 0) || (yj % 2 == 0)) {
						printf("\nUneli ste koridinate zida.\nUnesite ponovo koordinate ulaza\n");
						printf("x= ");
						scanf("%d", &xj);
						printf("y= ");
						scanf("%d", &yj);
					}
					matrica[yj][xj] = 'J';

					x = xj;y = yj;
					stack2[brojac2] = x; brojac2++;
					stack2[brojac2] = y; brojac2++;
					while (brojac2 >= 0) {

						if ((y + 1 < m) && ((matrica[y + 1][x] == cc1) || (matrica[y + 1][x] == cc2) || (matrica[y + 1][x] == cc3) || (matrica[y + 1][x] == 'P'))) {

							y = y + 1;
							stack2[brojac2] = x; brojac2++;
							stack2[brojac2] = y; brojac2++;
							if (matrica[y][x] == 'P') {
								printf("\nObrada je gotova!\n");
								break;
							}
							matrica[y][x] = '*';
							//stampaj(matrica, m, n);
						}
						else if ((x + 1 < n) && ((matrica[y][x + 1] == cc1) || (matrica[y][x + 1] == cc2) || (matrica[y][x + 1] == cc3) || (matrica[y][x + 1] == 'P'))) {

							x = x + 1;
							stack2[brojac2] = x; brojac2++;
							stack2[brojac2] = y; brojac2++;
							if (matrica[y][x] == 'P') {
								printf("\nObrada je gotova!\n");
								break;
							}
							matrica[y][x] = '*';

							//stampaj(matrica, m, n);
						}
						else if ((y - 1 > 0) && ((matrica[y - 1][x] == cc1) || (matrica[y - 1][x] == cc2) || (matrica[y - 1][x] == cc3) || (matrica[y - 1][x] == cc3))) {

							y = y - 1;
							stack2[brojac2] = x; brojac2++;
							stack2[brojac2] = y; brojac2++;
							if (matrica[y][x] == 'P') {
								printf("\nObrada je gotova!\n");
								break;
							}
							matrica[y][x] = '*';

							//stampaj(matrica, m, n);
						}
						else if ((x - 1 > 0) && ((matrica[y][x - 1] == cc1) || (matrica[y][x - 1] == cc2) || (matrica[y][x - 1] == cc3) || (matrica[y][x - 1] == 'P'))) {

							x = x - 1;
							stack2[brojac2] = x; brojac2++;
							stack2[brojac2] = y; brojac2++;
							if (matrica[y][x] == 'P') {
								printf("\nObrada je gotova!\n");
								break;
							}
							matrica[y][x] = '*';

							//stampaj(matrica, m, n);
						}
						else {
							brojac2--;
							y = stack2[brojac2];
							brojac2--;
							x = stack2[brojac2];
							//b--;
						}
					}
					//end_while
					//free(stack2);
				}
				//end_if

				break;
			case 6:
				if (matrica == NULL) {
					printf("\nMatrica jos nije formirana ili je obrisana.\n");
				}
				else {
					for (i = 0;i <m ;i++) {
					free(matrica[i]);
					}
					free(matrica);
					matrica = NULL;
				}
				break;
			}
			//end_switch
		}
		//end_if
	}
	//end_while

	system("pause");

}
//end_main