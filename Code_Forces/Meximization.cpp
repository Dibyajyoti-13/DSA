//Question - https://codeforces.com/contest/1497/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> freq(101, 0);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        for(int i = 0; i <= 100; i++) {
            if(freq[i] > 0) {
                cout << i << " ";
                freq[i]--;
            }
        }

        for(int i = 0; i <= 100; i++) {
            while(freq[i]--) {
                cout << i << " ";
            }
        }

        cout << "\n";
    }
}
