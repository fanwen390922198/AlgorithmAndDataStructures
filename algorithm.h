#pragma once
#include <iostream>
using namespace std;


// 归并排序
// 相关原理请参考此篇博客: http://blog.csdn.net/lemon_tree12138/article/details/51517753
void Merge( int a[ ], int low, int mid, int high );

// 弱分治（非递归）,就是将序列先按照最小单位(2)分成很多组,进行合并，逐渐增大分组单位2倍数增加
void    WeakGroupSort( int a[ ], int length );

// 归并排序，递归实现
void MergeSort( int a[ ], int start, int end );

/************************************************************************/
/*  希尔排序                                                            */
/************************************************************************/	
// 是插入排序的一种又称“缩小增量排序”，是直接插入排序算法的一种更高效的改进版本。希尔排序是非稳定的算法；
// 希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法；随着增量的逐渐减少，每组包含的关键词越来越多，
// 当增量减至1时，整个文件恰被分为一组，算法便终止。

void InsertSort( int a[ ], size_t size )
{
	for (unsigned int p = 1; p < size; p++)  // 总共需要遍历size -1 个数
	{
		int tmp = a[p];
		unsigned int i;
		for ( i = p; i > 0; i--)      // 找到存放a[p]的位置
		{
			if (a[i -1] > tmp)
				a[i] = a[i-1];
			else if (a[i - 1] <= tmp)
			{
				// 找到存放的位置，直接退出本轮循环
				break;
			}
		}
		a[i] = tmp;
	}
}

void ShellSort( int a[ ], size_t size )
{
	unsigned int increment;
	unsigned int count;
	for (increment = size / 2; increment > 0; increment /= 2)
	{
		for (count = 0; count < increment; count++)
		{
			for (unsigned int i = count + increment; i < size; i += increment)
			{
				int tmp = a[i];
				unsigned int p;
				for (p = i; p > count; p -= increment)
				{
					if (a[p - increment] > tmp)
						a[p] = a[p - increment];
					else
						break;
				}
				a[p] = tmp;
			}
		}
	}
}

/************************************************************************/
/* 快速排序                                                             */
/************************************************************************/
/*
	快速排序是采用的分治法，每次选定一个基本，将大于基本的放到一边，小于基准的放到另一边，
	快速排序的平均算法复杂度为O(nlogn)
*/

// 双边循环法
template<typename T>
void my_qsort( T tarray[ ], int start, int end )
{
	if (start == end)
		return;

	// 选一个基准，那我们实验就选第一个为基准
	T tPos = tarray[start];
	int i = start;
	int j = end;

	while (i < j)
	{
		while (( i < j ) && ( tarray[i] <= tPos ))
			i++;

		while (( j > i ) && ( tarray[j] > tPos ))
			j--;
		
		if (j > i)
		{
			T temp = tarray[i];
			tarray[i] = tarray[j];
			tarray[j] = temp;
		}
	}

	if (tarray[i] < tPos)  // 如果最后的位置的数比基本要小
	{
		tarray[start] = tarray[i];
		tarray[i] = tPos;
	}
		
	my_qsort( tarray, start, i - 1 );
	my_qsort( tarray, i, end);
}

template<typename T>
void printA( T tarray[ ], int iSize )
{
	for (int i = 0; i < iSize; i++)
	{
		cout << tarray[i] << " ";
	}
	cout << endl;
}

template<typename T>
void my_swap( T& a, T& b )
{
	T temp = a;
	a = b;
	b = temp;
}


// 单边循环法
template<typename T>
void my_qsort2( T tarray[ ], int iSize)
{
	if (iSize <= 1) return;

	T tPivot = tarray[0];
	int mark = 0;
	for (int i = 1; i < iSize; i++)
	{
		if (tarray[i] <= tPivot)
		{
			if (tarray[i] != tPivot)
				my_swap<T>( tarray[i], tarray[mark] );
			mark++;
		}
	}
	
	if (mark == 0 && mark < iSize)
		mark++;

	my_qsort2( tarray, mark );
	my_qsort2( tarray + mark, iSize - mark );
}
