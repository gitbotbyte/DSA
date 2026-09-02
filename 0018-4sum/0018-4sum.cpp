class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        vector<vector<int>> res;
        int n = a.size();
        if (n < 4) return res;
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 and a[i] == a[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i+1 and a[j] == a[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long sum = (long long)a[i] + a[j] + a[k] + a[l];
                    if (sum == target) {
                        res.push_back({a[i], a[j], a[k], a[l]});
                        k++;
                        l--;
                        while (k<l && a[k] == a[k -1])
                            k++;
                        while (k<l && a[l] == a[l + 1])
                            l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return res;   
    }
};