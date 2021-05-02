#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ln '\n'
#define ll long long



void solve() 
{
	ll n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];	
	
	ll stk = 0, maxDepth = 0, depthPos = 0; // Variables for first query
	ll maxLen = 0, lastZero = -1, maxLenStart = -1; // Variables for second query

	for(int i=0; i<n; i++) 
	{
		if(arr[i] == 1)
			stk++;
		else
			stk--;

		if(stk > maxDepth) 
		{
			depthPos = i;
			maxDepth = stk;
		}

		if(stk == 0) // stack is empty
		{
			if(i - lastZero > maxLen) 
			{
				maxLenStart = lastZero;
				maxLen = i - lastZero;
			}
			lastZero = i;
		}
	}


	cout << maxDepth << ' ' << ++depthPos << ' ' <<  maxLen << ' ' << maxLenStart+2 << ln;
}


int main()  	
{

#ifndef ONLINE_JUDGE	
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
    
    ll t = 1;
    // cin >> t;
    while(t--)
	solve();
	
    return 0;
}
