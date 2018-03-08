#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "algorithm.h"


#define ARRAYSIZE  30

void MakeData( int a[ ] ) 
{
	srand( ( unsigned )time( NULL ) );

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		*( a + i ) = rand() % ( ARRAYSIZE *3);
		cout << *( a + i ) << " ";
	}
	cout << endl;
}

int main( int args, char agrv[ ] )
{
// 	int *a = new int[2];
// 	*(a ) = 1;
// 	*( a + 1)  = 2;
// 	cout << *a << " " << *(a+1) <<endl;
// 	delete [] a;

	int a[ARRAYSIZE] = { 0 };
	MakeData( a );

	//WeakGroupSort( a, ARRAYSIZE );
	// MergeSort( a, 0, ARRAYSIZE - 1 );
	// InsertSort( a, ARRAYSIZE );
	ShellSort( a, ARRAYSIZE );
	for (int i = 0; i < ARRAYSIZE;  i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}