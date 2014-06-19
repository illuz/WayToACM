#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#include <cmath>
#include <vector>
using namespace std;

class AddMultiply {
public:
	vector <int> makeExpression(int y) {
		vector<int> v;
		v.push_back(251);
		v.push_back(2);
		v.push_back(y - 4);
		return v;
	}
};

const int N = 0;

int main()
{
	AddMultiply a;
	a.makeExpression(10);
	return 0;
}

