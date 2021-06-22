class Solution {
	bool match(vector<vector<int>>& indexmap, string s)
	{
		int pointers[26];
		for(int i=0; i<26; i++)	pointers[i] = 0;

		int index = -1;
		for(int i=0; i<s.size(); i++)
		{
			char cur = s[i];
			int ind = cur - 'a';


			for( ; pointers[ind] < indexmap[ind].size() && indexmap[ind][pointers[ind]] <= index; pointers[ind]++);
			if(pointers[ind] >= indexmap[ind].size())
				return false;


			index = indexmap[ind][pointers[ind]];
			pointers[ind]++;
		}

		return true;
	}
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        vector<vector<int>> indexmap(26);
        for(int i=0; i<s.size(); i++)
			indexmap[s[i]-'a'].push_back(i);

		int ans = 0;
		for(int i=0; i<words.size(); i++)
		{
			if(words[i].size() <= s.size() && match(indexmap, words[i]))
				ans++;
		}

		return ans;
    }
};
