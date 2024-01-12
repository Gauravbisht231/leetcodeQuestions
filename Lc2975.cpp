class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        unordered_map<int,int> mp, mk;
        mp[m - 1]++;
        mk[n - 1]++;
        int a = hFences.size(), b = vFences.size();
        for (int i = 0; i < a; i++) {
            mp[hFences[i] - 1]++;
            mp[m - hFences[i]]++;
        }
        for (int i = 0; i < b; i++) {
            mk[vFences[i] - 1]++;
            mk[n - vFences[i]]++;
        }
        for (int i = 0; i < a; i++)
            for (int j = 0; j < a; j++)
                if (abs(hFences[j] - hFences[i]) != 0)
                    mp[abs(hFences[j] - hFences[i])]++;
        for (int i = 0; i < b; i++)
            for (int j = 0; j < b; j++)
                if (abs(vFences[j] - vFences[i]) != 0)
                    mk[(vFences[j] - vFences[i])]++;
        long long mx = -1;
        for (auto i : mp)
            for (auto j : mk)
                if (i.first == j.first) {
                    long long t = ((long long)i.first*(long long)i.first)%(1e9+7);
                    mx = max(mx, t);
                }
        return mx;
    }
};