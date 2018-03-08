#pragma once
#include <iostream>
using namespace std;

/*
归并排序
相关原理请参考此篇博客: http://blog.csdn.net/lemon_tree12138/article/details/51517753
*/

void Merge( int a[ ], int low, int mid, int high );

// 弱分治（非递归）,就是将序列先按照最小单位(2)分成很多组,进行合并，逐渐增大分组单位2倍数增加
void    WeakGroupSort( int a[ ], int length );

// 归并排序，递归实现
void MergeSort( int a[ ], int start, int end );

/*
	希尔排序
	是插入排序的一种又称“缩小增量排序”，是直接插入排序算法的一种更高效的改进版本。希尔排序是非稳定的算法；
	希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法；随着增量的逐渐减少，每组包含的关键词越来越多，
	当增量减至1时，整个文件恰被分为一组，算法便终止。
*/

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



