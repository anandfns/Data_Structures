class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> isPrime(n+1, true); // assuming all element as prime / Prime ~ True
        for(int i=2; i<n; i++) {
            if(isPrime[i]) { // element - True / false 
                ans++;       // if element is True then it is a prime
                for(int j = 2*i; j<n; j = j+i) { // first comes the x2 of the element then +i for every next multiple of that element
                    isPrime[j] = false; // false ~ Not Prime
                }
            }
        }
        return ans;
    }
};