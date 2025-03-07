class Solution {
public:
    vector<int> seive(int left, int right) {
        int range = right - left + 1;
        vector<bool> isPrime(range, true);
        vector<int> primes;
        
        if (left == 1) isPrime[0] = false;

        for (int i = 2; i * i <= right; i++) {
            for (int j = max(i * i, (left + i - 1) / i * i); j <= right; j += i) {
                isPrime[j - left] = false;
            }
        }

        for (int i = 0; i < range; i++) {
            if (isPrime[i]) primes.push_back(i + left);
        }

        return primes;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = seive(left, right);
        if (primes.size() < 2) return { -1, -1 };

        int minDiff = INT_MAX, first = -1, second = -1;
        for (int i = 1; i < primes.size(); i++) {
            if (primes[i] - primes[i - 1] < minDiff) {
                minDiff = primes[i] - primes[i - 1];
                first = primes[i - 1];
                second = primes[i];
            }
        }

        return { first, second };
    }
};
