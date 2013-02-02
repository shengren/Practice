class Solution {
public:
    vector<int> grayCode(int n) {
        int total = 1 << n;
        vector<bool> has(total, false);
        vector<int> sequence;
        sequence.push_back(0);
        has[0] = true;
        
        int code = 0;
        while (--total) {
            int pos = 0;
            while (true) {
                int next_code = code ^ (1 << pos);
                if (!has[next_code]) {
                    code = next_code;
                    break;
                }
                ++pos;
            }
            sequence.push_back(code);
            has[code] = true;
        }
        return sequence;
    }
};
