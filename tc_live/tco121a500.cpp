#include <iostream>
#include <vector>

using namespace std;

class EllysFractions {
    public:
        long long getCount(int N) {
            return 0;
        }
};

long long comp(int n) {
    long long ret = 1;
    /*
    double x = 1;
    for (int i = 1; i <= n / 2; ++i) {
        x = x * (n - i + 1) / i;
        ret += (long long)x;
    }
    */
    return (ret << (n - 1));
}

int main(void) {
    vector<int> prime;
    bool isPrime[251];
    long long res[251];
    res[1] = 0;
    for (int i = 2; i <= 250; ++i)
        isPrime[i] = true;
    for (int i = 2; i <= 250; ++i) {
        if (isPrime[i]) {
            prime.push_back(i);
            for (int j = i + i; j <= 250; j += i)
                isPrime[j] = false;
        }
    }
    //cout << prime.size() << endl;
    //for (int i = 0; i < 53; ++i)
    //    cout << prime[i] << endl;
    vector<int> num(prime.size());
    for (int p = 0; p < prime.size(); ++p)
        num[p] = 0;
    for (int i = 2; i <= 250; ++i) {
        int x = i;
        for (int p = 0; p < prime.size(); ++p) {
            while (x % prime[p] == 0) {
                x /= prime[p];
                ++num[p];
            }
            if (x == 1) break;
        }
        int nz = 0;
        for (int p = 0; p < prime.size(); ++p) {
            if (num[p] > 0)
                ++nz;
        }
        res[i] = comp(nz);
        //cout << "nz = " << nz << endl;
        cout << "res[" << i << "] = " << res[i] << "LL;" << endl;
    }
    
    return 0;
}