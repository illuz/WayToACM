#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repu(i, a, b) for (int i = (a); i < (b); i++)
#define repf(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define swap(a, b) {int t = a; a = b; b = t;}
#define mc(a) memset(a, 0, sizeof(a))
#define ms(a, i) memset(a, i, sizeof(a))
#define sqr(x) ((x) * (x))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)

class GearsDiv2 {
public:
	int getmin(string s) {
		int len = s.size();
		s += s[0];
		int sum = 0;
		for(int i = len - 1; i >= 0; i--)
			if (s[i] == s[i + 1]) {
				sum++;
				//i--;
				s[i] = ' ';
			}
		return sum;
	}
};

int main() {
	string a;
	cin >> a;
	GearsDiv2 b;
	cout <<b.getmin(a) << endl;
	return 0;
}

