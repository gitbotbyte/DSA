class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;
        string res;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (st.empty()) {
                st.push({c, 1});
                continue;
            } else if (st.top().first != c) {
                st.push({c, 1});
                continue;
            } else if (st.top().second < (k - 1)) {
                st.top().second++;
                continue;
            }
            st.pop();
        }
            while (!st.empty()) {
                pair<char, int> p = st.top();
                st.pop();
                while (p.second--) {
                    res.push_back(p.first);
                }
            }
        reverse(res.begin(),res.end());
        return res;
    }
};