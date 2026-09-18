class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> l(26, n), r(26);

        for (int i = 0; i < n; i++) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            if (i != l[s[i] - 'a']) continue;

            int e = r[s[i] - 'a'];
            bool ok = true;

            for (int j = i; j <= e; j++) {
                if (l[s[j] - 'a'] < i) {
                    ok = false;
                    break;
                }
                e = max(e, r[s[j] - 'a']);
            }

            if (ok) v.push_back({e, i});
        }

        sort(v.begin(), v.end());

        vector<string> ans;
        int p = -1;

        for (auto [e, b] : v) {
            if (b > p) {
                ans.push_back(s.substr(b, e - b + 1));
                p = e;
            }
        }

        return ans;
    }
};