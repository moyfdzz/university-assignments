#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

#define N 4

bool DFS(char board[N][N], int i, int j, vector<vector<bool> > &visited, int length, string word, string curr){
	if(length == 0) {
		return curr == word;
	}

	visited[i][j] = true;
	bool rec = false;

	for(int row = i - 1; row <= i + 1 && row < 4; ++row) {
		for(int col = j-1; col <= j + 1 && col < 4; ++col) {
			if(row >- 1 && col >- 1 && !visited[row][col]) {
				rec = rec || DFS(board, row,col,visited,length-1,word,curr+board[row][col]);
			}
		}
	}

	visited[i][j] = false;

	return rec;
}

int main(){
    int n, m, score, length;
	char board[N][N];
	vector<vector<bool> > visited(N, vector<bool>(N,false));
    vector<string> dictionary;
    bool complete;
	string curr;

	cin >> n;

	for(int a = 0; a < n; a++) {
		score = 0;

		for(int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> board[j][k];
			}
		}

		cin >> m;

		dictionary.clear();

        string word;

		for (int h = 0; h < m; h++) {
			cin >> word;

			dictionary.push_back(word);
		}

		for (int z = 0; z < dictionary.size(); z++) {
			word = dictionary[z];
			length = word.length();
			complete = false;

			for(int i = 0; i < N && !complete; i++) {
				for(int j = 0; j < N && !complete; ++j) {
					curr = "";
					curr += board[i][j];
					complete = DFS(board, i, j, visited, length - 1, word, curr);
				}
			}
			if(complete){
				if(word.length() > 7) {
					score += 11;
				} 
                else if (word.length() == 7) {
					score += 5;
				} 
                else if (word.length() == 6) {
					score += 3;
				} 
                else if (word.length() == 5){
					score += 2;
				} 
                else if (word.length() < 5){
					score += 1;
				}

			}
		}

		cout << "Game " << a + 1 << ": " << score << endl;
	}

	return 0;
}