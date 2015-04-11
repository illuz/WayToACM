/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        SBT.cpp
*  Create Date: 2014-11-05 23:00:26
*  Descripton:  SBT from qifeng
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const unsigned int MAX_N=100001;
int ZUISHAO;     //最低工资
int ADD_PAY=0;
unsigned int C_NUM=0;
int front = 0;
struct node
{
	int key;
	int size, llink, rlink;
}OIER[MAX_N];
void LeftRotate(int &x)//左旋
{
	int y = OIER[x].rlink;
	if (y == 0) return;
	OIER[x].rlink = OIER[y].llink;
	OIER[y].llink = x;
	OIER[y].size = OIER[x].size;
	OIER[x].size = OIER[OIER[x].llink].size+OIER[OIER[x].rlink].size+1;
	x = y;
}
void RightRotate(int &x)//右旋
{
	int y = OIER[x].llink;
	if (y == 0) return;
	OIER[x].llink = OIER[y].rlink;
	OIER[y].rlink = x;
	OIER[y].size = OIER[x].size;
	OIER[x].size = OIER[OIER[x].llink].size+OIER[OIER[x].rlink].size+1;
	x = y;
}
void Maintain(int &root, bool flag)//维护 SBT 树
{
	if (!root) return;
	if (flag)
	{
		if(OIER[root].llink && OIER[OIER[root].llink].llink
				&& (!OIER[root].rlink || OIER[OIER[OIER[root].llink].llink].size > OIER[OIER[root].rlink].size))
			RightRotate(root);
		else if(OIER[root].llink && OIER[OIER[root].llink].rlink
				&& (!OIER[root].rlink || OIER[OIER[OIER[root].llink].rlink].size > OIER[OIER[root].rlink].size))
		{
			LeftRotate(OIER[root].llink);
			RightRotate(root);
		}
		else return;
	}
	else
	{
		if (OIER[root].rlink && OIER[OIER[root].rlink].rlink
				&& (!OIER[root].llink || OIER[OIER[OIER[root].rlink].rlink].size > OIER[OIER[root].llink].size))
			LeftRotate(root);
		else if (OIER[root].rlink && OIER[OIER[root].rlink].llink
				&& (!OIER[root].llink || OIER[OIER[OIER[root].rlink].llink].size > OIER[OIER[root].llink].size))
		{
			RightRotate(OIER[root].rlink);
			LeftRotate(root);
		}
		else return;
	}
	Maintain(OIER[root].llink, true);
	Maintain(OIER[root].rlink, false);
	Maintain(root, true);
	Maintain(root, false);
}
void Insert(int &root, int x)//插入关键字 x
{
	if (!root)
	{
		root = ++front;
		OIER[root].key = x;
		OIER[root].size = 1;
	}
	else
	{
		++OIER[root].size;
		Insert(x <= OIER[root].key ? OIER[root].llink : OIER[root].rlink, x);
		Maintain(root, x <= OIER[root].key);
	}
}
int Delete(int &root)//删除
{
	int t=0,sum=0;
	if(!root) return root;
	if(OIER[root].key+ADD_PAY<ZUISHAO) {
		sum+=OIER[OIER[root].llink].size+1;
		OIER[root].size-=sum;
		OIER[root].llink=0;
		t=Delete(OIER[root].rlink);
		sum+=t;
		OIER[root].size-=t;
		OIER[OIER[root].rlink].size=OIER[root].size;
		root=OIER[root].rlink;
	}
	else {
		t=Delete(OIER[root].llink);
		sum=t;
		OIER[root].size-=t;
	}
	return sum;
}      
int Select(int R, int x)//返回第 x 大的元素
{
	if(OIER[R].rlink==0)OIER[OIER[R].rlink].size=0;
	int r = OIER[OIER[R].rlink].size+1;
	if (x<r) return Select(OIER[R].rlink, x);
	else
		if (x>r) return Select(OIER[R].llink, x-r);
	if(x==r) return OIER[R].key;
}

int main(void)
{
	unsigned int N;
	char command;
	int pay,root=0;
	int i;
	fin>>N>>ZUISHAO;
	for(i=1;i<=N;i++)
	{
		fin>>command>>pay;
		if(command=='I'){
			if(pay>=ZUISHAO)Insert(root,pay-ADD_PAY);                                              
		}
		if(command=='F'){
			if(pay>OIER[root].size) fout<<-1<<endl;
			else   fout<<Select(root, pay)+ADD_PAY<<endl;
		}
		if(command=='A')ADD_PAY+=pay;
		if(command=='S'){
			ADD_PAY-=pay;
			C_NUM+=Delete(root);
		}
	}
	fout<<C_NUM<<endl;
	return 0;
}
