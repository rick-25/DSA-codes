#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "ds.h"

using namespace std;

#define ln '\n'
#define ll long long
#define MOD 1000000007



class Solution {
public: 
    int onceCount(vector<int>& arr, int l, int r) 
    {
        int ans = 0;
        for(int i=l; i<r; i++) {
            if(arr[i])
                ans++;
        }
        return ans;
    }
    string getDecimalTarget(vector<int>& arr, int once) 
    {
        if(once == 0) {
            return "0";
        }

        int cnt = 0;
        string ans = "";
        
        int l = arr.size();
        for(int i=arr.size()-1; i>-1 && once; i--) {
            if(arr[i])
                once--;
            l = i;
        }
        
        for(int i=l; i<arr.size(); i++) 
            ans.push_back(48+arr[i]);
        

        return ans;
    }

    int checkStr(vector<int>& arr, string decimalTar, int i) 
    {
        if(decimalTar[0] == '0')  {
            if(arr[i])
                return -1;
            else 
                return i+1;
        }

        while(i < arr.size() && arr[i] == 0) {
            i++;
        }

        for(int p=0; p<decimalTar.size(); i++, p++) {
            if(arr[i] != (decimalTar[p]-48)) 
                return -1;
        }

        return i;
    }
public:
    vector<int> threeEqualParts(vector<int>& arr) 
    {
        vector<int> ans = {-1, -1};
        int oneCnt = onceCount(arr, 0, arr.size());
        if(oneCnt % 3 != 0)
            return ans;

        string decimalTarget = getDecimalTarget(arr, oneCnt/3);

        int firstIndex = checkStr(arr, decimalTarget, 0); 
        if(firstIndex < 0)
            return ans;
        ans[0] = firstIndex-1;

        int secondIndex = checkStr(arr, decimalTarget, firstIndex);
        if(secondIndex < 0)
            return vector<int>({-1, -1});
        ans[1] = secondIndex;

        if(ans[1] > arr.size()-decimalTarget.size() || ans[0] >= ans[1])
            return vector<int>({-1, -1});

        return ans;
    }
};


int main()
{	//Test the solution code here
    Solution obj;
    vector<int> test = {0, 0, 0};
    vector<int> ans = obj.threeEqualParts(test);
    cout << ans[0] << ", " << ans[1] << ln;
    return 0;
}

