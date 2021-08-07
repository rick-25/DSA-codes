class Solution {

    vector<int> dp;

    //Matrix to store is palindrome info i.e m[i][j](substr[i, j]) is palindrome or not 
    vector<vector<int>> matrix;

    //Algorithm to find all substring isPalindrome information in O(N^2) time complexity
    void findPalindrome(string str)
    {
        matrix = vector<vector<int>>(str.size(), vector<int>(str.size()));

        for(int i=0; i<str.size(); i++) 
        {
            int l,r;
            l = r = i;
            while(l >= 0 && r < str.size()) {
                if(str[l] != str[r])
                    break;
                matrix[l--][r++]  = 1;
            }

            l = i;
            r = i+1;
            while(l >= 0 && r < str.size()) {
                if(str[l] != str[r])
                    break;
                matrix[l--][r++]  = 1;
            }
        }
    }


    int help(string str, int start) 
    {

        if(start >= str.size()) 
            return -1;
        
        if(dp[start] > -1)  return dp[start];

        int ans = INT_MAX;
        for(int i=start; i<str.size(); i++) {
            if(matrix[start][i]) {
                ans = min(ans, help(str, i+1));
            }
        }

        dp[start] = ++ans;
        return dp[start];
    }

public:
    int minCut(string s) {
        dp = vector<int>(s.size(), -1);
        findPalindrome(s);
        return help(s, 0);
    }
};
