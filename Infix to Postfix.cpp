#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ln '\n'
#define ll long long

// 2
// 15
// ((A+B)*D)^(E-F)
// 19
// A+(B*C-(D/E^F)*G)*H

// Example Output

// AB+D*EF-^
// ABC*DEF^/G*-H*+

int pre(char c) 
{
	if(c == '+' || c == '-')
		return 1;
	if(c == '*' || c == '/')
		return 2;
	if(c == '^')
		return 3;
	return -1;
}

void solve()
{
	ll n;
	string s;
	cin >> n >> s;

	
	stack<char> stk;
	string ans;

	for(int i=0; i<s.size(); i++)
	{
		if(isalpha(s[i])) {
			ans.push_back(s[i]);
		}
		else if(s[i] == '(') {
			stk.push(s[i]);
		}
		else if(s[i] == ')') {
			while(!stk.empty()) {
				char cur = stk.top();
				stk.pop();

				if(cur == '(')	break;

				ans.push_back(cur);
			}
		}
		else {
			while(!stk.empty() && stk.top() != '(' &&  pre(s[i]) <= pre(stk.top())) {
				ans.push_back(stk.top());	
				stk.pop();
			}
			stk.push(s[i]);
		}
	}
	while(!stk.empty())
	{
		ans.push_back(stk.top());
		stk.pop();
	}


	cout << ans << ln;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	ll t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
