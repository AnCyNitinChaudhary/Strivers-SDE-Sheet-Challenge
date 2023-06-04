#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
	vector<vector<long long int>> answer;
	for (int i = 0; i < n; i++){
		vector<long long int> row(i + 1, 1);
		for (int j = 1; j < i; j++){
			row[j] = answer[i - 1][j] + answer[i - 1][j - 1];
		}
		answer.push_back(row);
	}
	return answer;
}
