// test1112.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"stdlib.h"
#include"memory.h"
#include"string.h"
#define ARRY_NUMBER 9

typedef struct coorderate{
	int x;
	int y;
	int z;
}COORDERATE;

void show_array(int *array, int length)
{
	for(int i=0; i<length; i++)
	{
		printf("The value %d is %d\n", i+1, array[i]);
	}
}

//快速排序算法
void quick_sort(int *array_para, int L, int R)
{
	int x = array_para[L];
	int i=L;
	int j=R;
	if(L>=R)
	{
		return;
	}
	while(i<j)
	{
		while(i<j && array_para[j]>x) j--;
		array_para[i] = array_para[j];

		while(i<j && array_para[i]<x) i++;
		array_para[j] = array_para[i];
		
	}
	array_para[i]=x;
	quick_sort(array_para, L, i-1);
	quick_sort(array_para, i+1, R);
}

void quick_sort_coor(COORDERATE *coor, int L, int R)
{
	COORDERATE this_coor = coor[L];
	int i = L;
	int j = R;
	if(i>j)
	{
		return;
	}
	while(i<j)
	{
		while(i<j && (coor[j].x>this_coor.x || 
			(coor[j].x==this_coor.x && coor[j].y>this_coor.y) ||
			(coor[j].x==this_coor.x && coor[j].y==this_coor.y && coor[j].z>this_coor.z)))
		{
			j--;
		}
		coor[i] = coor[j];
		while(i<j && (coor[i].x<this_coor.x || 
			(coor[i].x==this_coor.x && coor[i].y<this_coor.y) ||
			(coor[i].x==this_coor.x && coor[i].y==this_coor.y && coor[i].z<this_coor.z)))
		{
			i++;
		}
		coor[j] = coor[i];
	}
	coor[i] = this_coor;
	quick_sort_coor(coor, L, i-1);
	quick_sort_coor(coor, i+1, R);
}

void remain_to_define(int **para_one, int length)
{
	*para_one = (int *)malloc(length*sizeof(int));
	//*para_one = new int[length];
	for(int i=0; i<length; i++)
	{
		//(*para_one)[i]= i*i;
		(*para_one)[i]= i*i;
	}
}

void quick_sort_test_two(int *para, int l, int r)
{
	int x=para[l];
	int i=l;
	int j=r;
	if(i>=j)
	{
		return;
	}
	while(i<j)
	{
		while(i<j && para[j]>x) j--;
		para[i]=para[j];
		while(i<j && para[i]<x) i++;
		para[j]=para[i];
	}
	para[i]=x;
	quick_sort_test_two(para, l, i-1);
	quick_sort_test_two(para, i+1, r);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arry[]={12,32,1,43,543,23,2,344,323};
	COORDERATE coor[]={{2,3,2}, {0,3,1}, {0,43,23}, {2,32,12}, {0,43,1654}, {8,23,87}, {2,32,1}};
	
	printf("The length of array is %d\n", sizeof(arry)/sizeof(int));

	int *arry_temp;
	arry_temp = (int *)malloc(ARRY_NUMBER*sizeof(int));

	memset(arry_temp, 0, ARRY_NUMBER*sizeof(int));
	//打印出数组各个元素的值
	show_array(arry_temp, ARRY_NUMBER);

	memcpy_s(arry_temp,ARRY_NUMBER*sizeof(int), arry, sizeof(arry));
	//打印出数组各个元素的值
	show_array(arry_temp, ARRY_NUMBER);

	//system("PAUSE");

	//下面快速排序算法
	quick_sort(arry_temp, 0, ARRY_NUMBER-1);
	show_array(arry_temp, ARRY_NUMBER);

	quick_sort_coor(coor, 0, sizeof(coor)/sizeof(COORDERATE)-1);
	for(int i=0; i<sizeof(coor)/sizeof(COORDERATE); i++)
	{
		printf("Sorted coor is:(%d, %d, %d)\n", coor[i].x, coor[i].y, coor[i].z);
	}

	//测试 remain_to_define
	int *test_value;
	int test_length = 8;
	remain_to_define(&test_value, test_length);
	for(int i=0; i<test_length; i++)
	{
		printf("The value of test_value[%d]:%d\n", i, test_value[i]);
	}
	//test_value函数本来是已经赋值了，这里面应用memcpy再次赋值
	memcpy_s(test_value, (test_length)*sizeof(int), arry, sizeof(arry)-8);
	show_array(test_value, test_length);
	//测试第二次排序算法
	quick_sort_test_two(test_value, 0, test_length-1);
	show_array(test_value, test_length);
	return 0;
}