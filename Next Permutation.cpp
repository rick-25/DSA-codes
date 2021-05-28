class Solution {
	void fill(vector<int>& nums, multiset<int>& s, int i) {
		int x = i;
		for(int y : s) 
				nums[x++] = y; 
	}

public:
    void nextPermutation(vector<int>& nums) 
	{
		multiset<int> s;
		for(int i=nums.size()-1; i>-1; i--)
		{
			s.insert(nums[i]);
			multiset<int>::iterator it = ++s.find(nums[i]);

			if(it == s.end()) 
			{
				if(i == 0) 
					sort(nums.begin(), nums.end());
				continue;
			}
			
			while(it != s.end() && *it <= nums[i]) 
				it++;
			if(it == s.end())	continue;

			int target = *it;
			s.erase(it);

			nums[i] = target;

			fill(nums, s, i+1);
			break;
		}
    }
};
