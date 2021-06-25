class Solution {
public:
//Idea of monotonic stack
    int largestRectangleArea(vector<int>& heights) {

		unordered_map<int, int> right; // value minimum till which right index 
		unordered_map<int, int> left; //value minimum till which left index
		stack<int> stk;

		for(int i=0; i<heights.size() || stk.size(); i++) {

			int curValue = (i < heights.size()) ? heights[i] : -1;
			
			while(stk.size() && (heights[stk.top()] > curValue)) {
				right[stk.top()] = i;
				stk.pop();
			}

			if(i < heights.size())
				stk.push(i);
		}

		for(int i=heights.size()-1; i>-1 || stk.size(); i--) {

			int curValue = (i >= 0) ? heights[i] : -1;
			
			while(stk.size() && (heights[stk.top()] > curValue)) {
				left[stk.top()] = i;
				stk.pop();
			}

			if(i >= 0)
				stk.push(i);
		}

		int ans = INT_MIN;
		for(int i=0; i<heights.size(); i++) 
			ans = max(ans, ((i - left[i]) + (right[i] - i) - 1) * heights[i]);
		
		return ans;
    }
};
