/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2416.cpp
*  Create Date: 2015-03-22 00:40:38
*  Descripton:  BFS
*/

#include <bits/stdc++.h>

using namespace std;

int n, tmp;
queue<pair<string, int> > q;
set<string> s;
string start, target;
pair<string, int> state;

int main() {
    cin >> n;
    while (n--) {
        cin >> start >> target;
        s.clear();
        while (!q.empty())
            q.pop();

        // BFS
        q.push(make_pair(start, 0));
        s.insert(start);
        while (!q.empty()) {
            state = q.front();
            q.pop();
            if (state.first == target) {
                cout << state.second << endl;
                break;
            }
            // increase or decrease
            for (int i = 0; i < 4; ++i) {
                tmp = state.first[i] - '1';
                // increase
                state.first[i] = '1' + (tmp + 1) % 9;
                if (s.find(state.first) == s.end()) {
                    q.push(make_pair(state.first, state.second + 1));
                    s.insert(state.first);
                }
                // decrease
                state.first[i] = '1' + (tmp + 8) % 9;
                if (s.find(state.first) == s.end()) {
                    q.push(make_pair(state.first, state.second + 1));
                    s.insert(state.first);
                }
                // recover
                state.first[i] = '1' + tmp;
            }

            // swap
            for (int i = 0; i < 3; ++i) {
                swap(state.first[i], state.first[i + 1]);
                if (s.find(state.first) == s.end()) {
                    q.push(make_pair(state.first, state.second + 1));
                    s.insert(state.first);
                }
                swap(state.first[i], state.first[i + 1]);
            }
        }
    }
    return 0;
}

