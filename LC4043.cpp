class Solution {
public:
    int countRotations(string s, int tar) {
        int n = s.size();
        int ans = 0;

        for(int k=0; k<n; k++) {
            int cnt = 0;
            for(int i=0; i<n-1; i++) {
                if(s[i] == s[i+1]) cnt++;
            }
            if(cnt == tar) ans++;

            string tmp =s.substr(1);
            tmp += s[0];
            s = tmp;

            // char c = s[0];
            // for(int i=0; i<n-1; i++) {
            //     s[i] = s[i+1];
            // }
            // s[n-1] = c;
        }

        return ans;
    }
};