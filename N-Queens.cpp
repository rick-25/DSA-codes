class Solution {
	vector<vector<string>> ans; // Global ans
public:
    vector<vector<string>> solveNQueens(int n) 
    {
	    vector<pair<int, int>> queens; // it contains location of all queens in all row
		solve(n, queens, 0);
		return  ans;
    }

	void solve(int n, vector<pair<int, int>> &queens, int row /*Current row*/ )
	{
		if(row == n) // Base case (queens path is valid)
		{
			vector<string> data;
			for(auto i : queens) 
			{
				int col = i.second;
				string temp;
				for(int i=0; i<n; i++) 
				{
					if(i == col)
						temp.push_back('Q');
					else 
						temp.push_back('.');
				}
				data.push_back(temp);
			}
			
			ans.push_back(data);
			return;
		}
    
    
		for(int i=0; i<n; i++) //checking every col of given row, is it valid for placing queen or not
		{
			if(valid(queens, row, i)) 
			{
				queens.push_back({row, i});
				solve(n, queens, row+1);
				queens.pop_back();
			}
		}
	}

	bool valid(vector<pair<int, int>> &queens, int r, int c) //Queen position validity checker
	{
		for(pair<int, int> coordinate : queens) {
			if(coordinate.second == c)	return false;

			int diff = r - coordinate.first;

			if(c == coordinate.second + diff || c == coordinate.second - diff)	
				return false;
		}
		return true;
	}
};
