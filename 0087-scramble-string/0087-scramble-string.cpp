#include <string>
#include <vector>
using namespace std;

class Solution {
    string a, b;
    int n;
    
    vector<vector<vector<int>>> memo;

    bool solve(int i, int j, int len) {
        int& res = memo[i][j][len];
        if (res != 0) return res == 1;

       
        if (a.compare(i, len, b, j, len) == 0) { res = 1; return true; }

        
        int cnt[26] = {0};
        for (int k = 0; k < len; k++) {
            cnt[a[i + k] - 'a']++;
            cnt[b[j + k] - 'a']--;
        }
        for (int c : cnt) {
            if (c != 0) { res = -1; return false; }
        }

       
        for (int k = 1; k < len; k++) {
        
            if (solve(i, j, k) && solve(i + k, j + k, len - k)) { res = 1; return true; }
        
            if (solve(i, j + len - k, k) && solve(i + k, j, len - k)) { res = 1; return true; }
        }

        res = -1;
        return false;
    }

public:
    bool isScramble(string s1, string s2) {
        a = s1; b = s2; n = s1.size();
        memo.assign(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));
        return solve(0, 0, n);
    }
};