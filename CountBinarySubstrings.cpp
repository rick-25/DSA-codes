
class Solution {
public:
    int countBinarySubstrings(string s) {

        int ans = 0, zeros = 0, ones = 0;

        for(int i = 0; i < s.size(); i++) 
        {
            if(s[i] == '0' && i - 1 > 0 && s[i-1] == '1')         zeros = 0;
            else if(s[i] == '1' && i - 1 > 0 && s[i-1] == '0')    ones = 0;


            if(s[i] == '0') zeros++;
            else            ones++;

            if(s[i]=='0')
            {
                if(ones > 0)
                {
                    ones--;
                    ans++;
                }
            }
            else 
            {
                if(zeros > 0)
                {
                    zeros--;
                    ans++;
                }
            }
        }

        return ans;
    }
};
