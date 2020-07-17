#include <iostream>
using namespace std;

//The number of discs
const int n=3;


void show(int tower[][3])
{
	int i, j;
	char c;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
			cout << tower[i][j] << '\t';
		cout << endl;
	}
	cout << "Enter any letter to continue...\n";
	cin >> c;
	cout << endl<<endl;
}


int posiDisc(int tower[][3], int p)
{
	int i = 0;
	for (i; i < n; i++)
		if (tower[i][p] != 0)
			return i;
	return i;
}


int destdisc(int tower[][3], int p)
{
	int i = 0;
	for (i = n - 1; i >= 0; i--)
		if (tower[i][p] == 0)
			return i;
	return i;
}


void hanoi(int tower[][3], int n, int p1, int p2)
{
	int disc, position, destination;
	if (n > 0)
	{
		hanoi(tower, n - 1, p1, 6 - p1 - p2);
		show(tower);
		cout << "disc number " << n << " from peg " << p1 << " to peg " << p2 << endl;
		position = posiDisc(tower, p1 - 1);
		disc = tower[position][p1 - 1];
		tower[position][p1 - 1] = 0;
		destination = destdisc(tower, p2 - 1);
		tower[destination][p2 - 1] = disc;
		hanoi(tower, n - 1, 6 - p1 - p2, p2);
	}
}


int main(int argc, char** argv)
{
	int tower[n][3] = { 0 };

	
	for (int i = 0; i < n; i++)
		tower[i][0] = i + 1;

	hanoi(tower, n, 1, 3);

	show(tower);
	return 0;
}