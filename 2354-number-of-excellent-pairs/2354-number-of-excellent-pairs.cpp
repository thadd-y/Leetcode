#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> unique(nums.begin(), nums.end());

        long long cnt[31] = {0};
        for (int x : unique) {
            cnt[__builtin_popcount(x)]++;
        }
        long long result = 0;
        for (int a = 1; a <= 30; a++) {
            for (int b = 1; b <= 30; b++) {
                if (a + b >= k) {
                    result += cnt[a] * cnt[b];
                }
            }
        }
        return result;
    }
};