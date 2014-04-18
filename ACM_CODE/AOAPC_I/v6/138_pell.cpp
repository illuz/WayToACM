/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        138_pell.cpp
*  Create Date: 2014-04-17 16:01:17
*  Descripton:  pell 
*/

#include <cstdio>

int main()
{
	int x1 = 3, y1 = 2, px = x1, py = y1, t;
	for (int i = 1; i <= 10; i++) {
		t = x1 * px + 2 * y1 * py;
		py = x1 * py + y1 * px;
		px = t;
		printf("%10d%10d\n", py / 2, (px - 1) / 2);
	}
	return 0;
}

