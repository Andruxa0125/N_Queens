bool isValid(const vector<string>& v, int row, int pos, int A)
// index of where the queen was placed
{
	int i = 0;

	// check above
	while (i < row)
	{
		if (v[i][pos] == 'Q')
			return false;
		i++;
	}

	// check left diagonal
	int r = row - 1;
	int p = pos - 1;
	while (r >= 0 && pos >= 0)
	{
		if (v[r][p] == 'Q')
			return false;
		r--;
		p--;
	}

	// check right diagonal
	r = row - 1;
	p = pos + 1;
	while (r >= 0 && p < A)
	{
		if (v[r][p] == 'Q')
			return false;
		r--;
		p++;
	}

	return true;
}

void helper(int A, vector<string>& cur, int row, vector<vector<string>>& result)
{
	if (row == A)// we have just placed last Q, and it is valid=>it should be a solution.
	{
		result.push_back(cur);
		return;
	}

	for (int pos = 0; pos < A; pos++)
	{
		cur[row][pos] = 'Q';
		if (isValid(cur, row, pos, A))
		{
			// it is all valid so far=>move on to the next row
			helper(A, cur, row + 1, result);
		}
		cur[row][pos] = '.';
	}
}
void fillBoard(vector<string>& board, int A)
{
	int z = 0;
	string filler = "";
	while (z < A)
	{
		filler += '.';
		z++;
	}
	z = 0;
	while (z < A)
	{
		board.push_back(filler);
		z++;
	}
}

vector<vector<string> > Solution::solveNQueens(int A)
{
	// board
	vector<string> board;
	fillBoard(board, A);

	//variable for final result
	vector<vector<string>> result;

	helper(A, board, 0, result);

	return result;
}

