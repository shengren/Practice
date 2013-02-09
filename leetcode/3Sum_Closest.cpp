class Solution {
    bool binarySearch(vector<int> &num, int beg, int end, int target) {
        if (beg == end)
            return false;
        if (beg + 1 == end)
            return num[beg] == target;
        int mid = (beg + end) / 2;
        if (num[mid] == target)
            return true;
        else if (num[mid] > target)
            return binarySearch(num, beg, mid, target);
        else
            return binarySearch(num, mid + 1, end, target);
    }
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        for (int k = 0; ; ++k) {
            int x = target + k;
            for (int i = 0; i < num.size(); ++i)
                for (int j = i + 1; j < num.size(); ++j) {
                    int third = x - num[i] - num[j];
                    if (binarySearch(num, j + 1, num.size(), third))
                        return x;
                }
            
            if (k == 0)
                continue;
            x = target - k;
            for (int i = 0; i < num.size(); ++i)
                for (int j = i + 1; j < num.size(); ++j) {
                    int third = x - num[i] - num[j];
                    if (binarySearch(num, j + 1, num.size(), third))
                        return x;
                }
        }
    }
};
