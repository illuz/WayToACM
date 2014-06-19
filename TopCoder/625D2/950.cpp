#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class ConundrumReloaded {
public:
	int minimumLiars(string ans) {
		int len = ans.length();
		int ret = 0, cnt = 0;
		vector<int> q;
		for (int i = 0; i < len; i++)
			if (ans[i] == '?') {
				q.push_back(i);
				cnt++;
			}
		if (cnt) {
			ret = dealUnbreak(ans.substr(q[cnt - 1] + 1) + ans.substr(0, q[0]));
			for (int i = 0; i < cnt - 1; i++)
				ret += dealUnbreak(ans.substr(q[i] + 1, q[i + 1] - q[i] - 1));
			return ret;
		}
		else {
			return dealBreak(ans);
		}
	}

	int dealBreak(string s) {
		int len = s.size();
		if (len == 0)
			return 0;

		bool cur;
		int ret1 = 0, ret2 = 1;

		// if 0 is honest
		cur = true;
		for (int i = 0; i < len; i++) {
			if (cur) {
				if (s[i] == 'L') {
					cur = false;
					ret1++;
				} else {
					cur = true;
				}
			} else {
				if (s[i] == 'L') {
					cur = true;
				} else {
					cur = false;
					ret1++;
				}
			}
		}
		if (cur == false)
			ret1 = 51;

		// if 0 is liyar
		cur = false;
		for (int i = 0; i < len; i++) {
			if (cur) {
				if (s[i] == 'L') {
					cur = false;
					ret2++;
				} else {
					cur = true;
				}
			} else {
				if (s[i] == 'L') {
					cur = true;
				} else {
					cur = false;
					ret2++;
				}
			}
		}
		if (cur == true)
			ret2 = 51;

		if (ret1 != 51 || ret2 != 51)
			return min(ret1, ret2);
		else
			return -1;
	}

	int dealUnbreak(string s) {
		int len = s.size();
		if (len == 0)
			return 0;

		bool cur;
		int ret1 = 0, ret2 = 1;

		// if 0 is honest
		cur = true;
		for (int i = 0; i < len; i++) {
			if (cur) {
				if (s[i] == 'L') {
					cur = false;
					ret1++;
				} else {
					cur = true;
				}
			} else {
				if (s[i] == 'L') {
					cur = true;
				} else {
					cur = false;
					ret1++;
				}
			}
		}

		// if 0 is liyar
		cur = false;
		for (int i = 0; i < len; i++) {
			if (cur) {
				if (s[i] == 'L') {
					cur = false;
					ret2++;
				} else {
					cur = true;
				}
			} else {
				if (s[i] == 'L') {
					cur = true;
				} else {
					cur = false;
					ret2++;
				}
			}
		}

		return min(ret1, ret2);
	}
};

int main()
{
	ConundrumReloaded A;
	cout << A.minimumLiars("LLL") << endl;
	return 0;
}

