#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

       
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        
        int maxFreq = 0;
        char maxChar = s[0];
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = char('a' + i);
            }
        }

        
        int minFreq = INT_MAX;
        char minChar = maxChar;
        bool found = false;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0 && char('a' + i) != maxChar) {
                if (freq[i] < minFreq) {
                    minFreq = freq[i];
                    minChar = char('a' + i);
                    found = true;
                }
            }
        }

        
        if (!found) {
            cout << s << "\n";
            continue;
        }

        
        for (int i = 0; i < n; i++) {
            if (s[i] == minChar) {
                s[i] = maxChar;
                break;
            }
        }

        cout << s << "\n";
    }

    return 0;
}
