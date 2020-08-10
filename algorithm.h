#pragma once
#include <iostream>
using namespace std;


// �鲢����
// ���ԭ����ο���ƪ����: http://blog.csdn.net/lemon_tree12138/article/details/51517753
void Merge( int a[ ], int low, int mid, int high );

// �����Σ��ǵݹ飩,���ǽ������Ȱ�����С��λ(2)�ֳɺܶ���,���кϲ�����������鵥λ2��������
void    WeakGroupSort( int a[ ], int length );

// �鲢���򣬵ݹ�ʵ��
void MergeSort( int a[ ], int start, int end );

/************************************************************************/
/*  ϣ������                                                            */
/************************************************************************/	
// �ǲ��������һ���ֳơ���С�������򡱣���ֱ�Ӳ��������㷨��һ�ָ���Ч�ĸĽ��汾��ϣ�������Ƿ��ȶ����㷨��
// ϣ�������ǰѼ�¼���±��һ���������飬��ÿ��ʹ��ֱ�Ӳ��������㷨�������������𽥼��٣�ÿ������Ĺؼ���Խ��Խ�࣬
// ����������1ʱ�������ļ�ǡ����Ϊһ�飬�㷨����ֹ��

void InsertSort( int a[ ], size_t size )
{
	for (unsigned int p = 1; p < size; p++)  // �ܹ���Ҫ����size -1 ����
	{
		int tmp = a[p];
		unsigned int i;
		for ( i = p; i > 0; i--)      // �ҵ����a[p]��λ��
		{
			if (a[i -1] > tmp)
				a[i] = a[i-1];
			else if (a[i - 1] <= tmp)
			{
				// �ҵ���ŵ�λ�ã�ֱ���˳�����ѭ��
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
/* ��������                                                             */
/************************************************************************/
/*
	���������ǲ��õķ��η���ÿ��ѡ��һ�������������ڻ����ķŵ�һ�ߣ�С�ڻ�׼�ķŵ���һ�ߣ�
	���������ƽ���㷨���Ӷ�ΪO(nlogn)
*/

// ˫��ѭ����
template<typename T>
void my_qsort( T tarray[ ], int start, int end )
{
	if (start == end)
		return;

	// ѡһ����׼��������ʵ���ѡ��һ��Ϊ��׼
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

	if (tarray[i] < tPos)  // �������λ�õ����Ȼ���ҪС
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


// ����ѭ����
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
