//******************we are accessing both the arrays from the bakside*******************

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1;
        int j = n - 1;
        int idx = m + n - 1;

        while(i >= 0 && j >= 0) {
            if(A[i] >= B[j]) {
                A[idx--] = A[i--];
            } else {
                A[idx--] = B[j--];
            }
        }

        while(j >= 0) { // for remaining elements in array B (IF ANY)
            A[idx--] = B[j--];
        }
    }
};