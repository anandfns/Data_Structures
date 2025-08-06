//**********************Brute Force****************************

vector<vector<int>> sum3(vector<int> arr){
    int n = arr.size();
    set<vector<int>> s; // To check if the triplet is repeating or not , because we need unique triplets
    vector<vector<int>> ans; // we will store all the triplet in this 2D vector
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> unsorted = {arr[i] , arr[j], arr[k]}; // Storing the triplets in a temporary 1D vector, w'll use it as a row
                    sort(unsorted.begin(), unsorted.end());           // Sorting the array before storing it in a set, to get unique triplets
                    if(s.find(unsorted) == s.end()) {
                        ans.push_back(unsorted);
                    }

                    s.insert(unsorted);
                }
            }
        }
    }

    return ans;
}

// *************************Optimal*********************************
