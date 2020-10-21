#include<iostream>
#include<iomanip>
#include<ctime>

#define out(X) (cout << #X << " = " << X << endl)

using namespace std;

void lesson_05 () {
	const int m = 5, n = 4;

	int matr[m][n] = {0};
	int cube[m][m][m];
	srand(time(0));


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matr[i][j] = rand() % 100;
			cout << setw(3) << matr[i][j];
		}
		cout << endl;
	}
	cout << endl << "Matrix7.\n";
	int k = 2;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == k) {
				cout << setw(3) << matr[i][j];
			}
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		cout << setw(3) << matr[k][i];
	}

	cout << "\nMatrix18:\n";
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += matr[i][k];
	}
	out(sum);

	cout << "\nMatrix24:\n";

	for (int i = 0; i < n; i++)
	{
		int max = matr[0][i];
		for (int j = 1; j < m; j++)
		{
			if (max < matr[j][i]) {
				max = matr[j][i];
			}
		}
		cout << i << "_";
		out(max);
	}
	
	cout << "\nMatrix35:\n";

	bool b = true;
	for (int i = 0; i < n; i++)
	{
		b = true;
		for (int j = 0; j < m; j++)
		{
			if (matr[j][i] % 2 == 0) {
				b = false;
				break;
			}
		}
		if (b) {
			out(i);
			break;
		}
	}
	if (!b) {
		cout << "-1\n";
	}

	cout << "\nMatrix41:\n";

	for (int i = 0; i < m; i++)
	{
		int col[m];
		for (int j = 0; j < n; j++)
		{
			for (int k = i + 1; k < m; k++)
			{
				if (matr[j][i] == matr[j][k]) {

				}
			}
		}

	}


}
