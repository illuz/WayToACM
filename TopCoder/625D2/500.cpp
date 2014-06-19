#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class IncrementingSequence {
public:
	int vis[55];
	string canItBeDone(int k, vector <int> A) {
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < A.size(); i++) {
			bool flag = false;
			int tmp = A[i];
			for (; tmp <= A.size(); tmp += k) {
				if (vis[tmp] == 0) {
					vis[tmp] = 1;
					flag = true;
					break;
				}
			}
			if (!flag) {
				return "IMPOSSIBLE";
			}
		}
		return "POSSIBLE";
	}
};

const int N = 0;

int main()
{
	int test[] = {5,3,3,2,1};
	vector<int> tt (test, test + 5);
	IncrementingSequence A;
	cout << A.canItBeDone(2, tt);
	return 0;
}

