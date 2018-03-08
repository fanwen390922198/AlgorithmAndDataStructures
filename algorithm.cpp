#pragma once
#include <iostream>
using namespace std;

/*
�鲢����
���ԭ����ο���ƪ����: http://blog.csdn.net/lemon_tree12138/article/details/51517753
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

// �����Σ��ǵݹ飩,���ǽ������Ȱ�����С��λ(2)�ֳɺܶ���,���кϲ�����������鵥λ2��������
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

		// ��ʣ������ݽ��У��˴�����һ���Ż��������ظ�����
		if (!( ( group_size > 2 ) && ( ( length%group_size ) == ( length % ( group_size / 2 ) ) ) ))
		{
			Merge( a, group_sum*group_size, group_sum*group_size + group_size / 2 - 1, length - 1 );
		}

		// ���һ�κϲ�,ֻ������size�����л��ߴ˲���
		if (( 1 == group_sum ) && ( group_size < length ))
		{
			Merge( a, 0, group_sum*group_size - 1, length - 1 );
		}

		group_size *= 2;
	}
}


// �鲢���򣬵ݹ�ʵ��
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


