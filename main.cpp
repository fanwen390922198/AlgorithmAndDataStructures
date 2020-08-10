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
	}
}

int main( int args, char agrv[ ] )
{
// 	int *a = new int[2];
// 	*(a ) = 1;
// 	*( a + 1)  = 2;
// 	cout << *a << " " << *(a+1) <<endl;
// 	delete [] a;

//	int Array[ARRAYSIZE] = { 2, 6, 5, 15, 5, 16 };
	int Array[ARRAYSIZE] = {};
	MakeData( Array );

	printA<int>( Array, ARRAYSIZE );

	//WeakGroupSort( a, ARRAYSIZE );
	// MergeSort( a, 0, ARRAYSIZE - 1 );
	// InsertSort( a, ARRAYSIZE );
	// ShellSort( a, ARRAYSIZE );
	// my_qsort<int>( Array, 0, ARRAYSIZE - 1 );

	my_qsort2<int>( Array, ARRAYSIZE );
//	my_qsort2<int>( Array+2, 3 );

	printA<int>( Array, ARRAYSIZE );

	return 0;
}