// 数据结构第一次上机.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
typedef char ET;
typedef struct
{
	ET  *listArray;
	int listLength;
	int listSize;
	int listCurpos;
}List;
bool listCreate(List &l, int maxsize)
{
	if (maxsize<0 || maxsize>MAXSIZE)
		return false;
	l.listArray = new ET[maxsize];
	if (l.listArray == NULL) return false;
	l.listSize = maxsize;
	l.listLength = 0;
	l.listCurpos = 0;
	return true;
}
bool listClear(List &l)
{
	if (l.listArray != NULL)
	{
		delete[] l.listArray;
		l.listArray = NULL;
	}
	l.listSize = 0;
	l.listLength = 0;
	l.listCurpos = 0;
	return true;
}
int GetlistLength(List &l)
{
	return l.listLength;
}
ET listGet(List &l, int i)
{
	return l.listArray[i];
}
int listLocate(List &l, ET const &it)
{
	int i = 0;
	while (l.listArray[i] != it)
	{
		i++;
	}
	return i;
}
bool listInsert(List &l, ET const &it)
{
	int i;
	if (l.listLength >= l.listSize)
		return false;
	for (i = l.listLength; i>l.listCurpos; i--)
	{
		l.listArray[i] = l.listArray[i - 1];
	}
	l.listArray[l.listCurpos] = it;
	l.listLength++;
	return true;
}
bool listDelete(List &l, ET &it)
{
	int i;
	if (l.listLength <= 0)
		return false;
	it = l.listArray[l.listCurpos];
	for (i = l.listCurpos; i<l.listLength - 1; i++)
	{
		l.listArray[i] = l.listArray[i + 1];
	}
	if (l.listCurpos = l.listLength - 1)
		l.listCurpos--;
	l.listLength--;
	return true;
}
bool merg(List &l1, List &l2,List &l3)
{
	int i, j = 0;
	if (l1.listLength + l2.listLength>MAXSIZE)
		return false;
	l3.listLength = l1.listLength + l2.listLength;
	for (i = 0; i < l1.listLength; i++)
	{
		l3.listArray[i] = l1.listArray[i];
	}
	for (i = l1.listLength; i < l1.listLength + l2.listLength; i++)
	{
		l3.listArray[i] = l2.listArray[j];
		j++;
	}
	return true;
}
void listDisplay(List &l)
{
	int i;
	if (l.listArray != NULL)
		for (i = 0; i<l.listLength; i++)
			printf("%c ", l.listArray[i]);
	printf("\n");
}
int main()
{
	int i;
	char t;
	List test1, test2,test3;
	listCreate(test1, 1000);
	listCreate(test2, 1000);
	listCreate(test3, 1000);
	char a[4] = { 'd','c','b','a' };
	char b[4] = { 'k','j','i','h' };
	for (i = 0; i<4; i++)
	{
		listInsert(test1, a[i]);
	}
	listDisplay(test1);
	i = listLocate(test1, 'a');
	printf("%d\n", i);
	printf("%c\n", listGet(test1, 3));
	test1.listCurpos = 2;
	listDelete(test1, t);
	listDisplay(test1);
	for (i = 0; i<4; i++)
	{
		listInsert(test2, b[i]);
	}
	merg(test1, test2,test3);
	listDisplay(test3);
	return 0;
}
