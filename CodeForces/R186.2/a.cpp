#include <iostream>
using namespace std;
int main()
{
	long long n;
	long long a, b;
	cin >> n;
	if (n >= 0)
		cout << n << endl;
	else
	{
		a = -n % 10;
		b = -n / 100 * 10 + a;
		if (b < -n / 10)
			cout << -b << endl;
		else
			cout << -(-n / 10) << endl;
	}
	return 0;
}
