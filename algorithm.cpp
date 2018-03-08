#pragma once
#include <iostream>
using namespace std;

/*
归并排序
相关原理请参考此篇博客: http://blog.csdn.net/lemon_tree12138/article/details/51517753
*/

void Merge( int a[ ], int low, int mid, int high )
{
	//	cout << "low=" << low << ";" << "mid=" << mid << ";" << "high=" << high << endl;
	if (low >= high) return;

	int *pArray = new int[high - low + 1];
	if (pArray == NULL)
	{
		cout << "memory is not enough" << endl;
		return;
	}

	int i = low;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
			pArray[k++] = a[i++];
		else
			pArray[k++] = a[j++];
	}

	while (i <= mid)
	{
		pArray[k++] = a[i++];
	}

	while (j <= high)
	{
		pArray[k++] = a[j++];
	}

	for (int p = 0; p < k; p++)
	{
		a[low + p] = pArray[p];
	}
	delete[ ] pArray;
}

// 弱分治（非递归）,就是将序列先按照最小单位(2)分成很多组,进行合并，逐渐增大分组单位2倍数增加
void    WeakGroupSort( int a[ ], int length )
{
	int group_size = 2;
	while (( length / group_size ) > 0)
	{
		//		cout << "---------group_size:" << group_size << endl;
		int group_sum = length / group_size;
		for (int i = 0; i < group_sum; i++)
		{
			Merge( a, i*group_size, ( i*group_size + ( i + 1 )*group_size - 1 ) / 2, ( i + 1 )*group_size - 1 );
		}

		// 对剩余的数据进行，此处算是一个优化，避免重复排序
		if (!( ( group_size > 2 ) && ( ( length%group_size ) == ( length % ( group_size / 2 ) ) ) ))
		{
			Merge( a, group_sum*group_size, group_sum*group_size + group_size / 2 - 1, length - 1 );
		}

		// 最后一次合并,只有奇数size的序列会走此步骤
		if (( 1 == group_sum ) && ( group_size < length ))
		{
			Merge( a, 0, group_sum*group_size - 1, length - 1 );
		}

		group_size *= 2;
	}
}


// 归并排序，递归实现
void MergeSort( int a[ ], int start, int end )
{
	if (start >= end)
	{
		return;
	}
	else
	{
		int mid = ( start + end ) / 2;
		MergeSort( a, start, mid );
		MergeSort( a, mid + 1, end );
		Merge( a, start, mid, end );
	}
}


