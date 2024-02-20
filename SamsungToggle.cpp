#include<bits/stdc++.h>
using namespace std;
/*
Question: Find the Maximum rows having all ones in the binary if you are allowed to toggle columns in the matrix for exactly k number of times

*/

							// SAMSUNG QUESTION: RECURSIVE + MEMOIZED: 
int helper(int col, int k, vector<vector<int>> &mat, int n, int m, vector<vector<int>> &memo){
 // base cases:
 if(k==0){
	int amp=0;
	for(auto it: mat){
		int cnt1= count(it.begin(),it.end(), 1);
		if(cnt1== it.size()) amp++;
	}
	return amp;
	
 }
 if(col>=m) return 0;
 if(memo[col][k]!=-1) return memo[col][k];
 // two choices:
 // flip column or not flip 
int maxi=0;
// flip column
for(int i=0; i<n; i++){
	mat[i][col]= !mat[i][col];
}
maxi= max({maxi, helper(col+1, k-1, mat, n, m, memo), helper(col, k-1, mat, n, m, memo)});

// not flip column
for(int i=0; i<n; i++){
	mat[i][col]= !mat[i][col];
}
maxi= max(maxi, helper(col+1, k, mat, n, m, memo));
return memo[col][k]= maxi;

}
int findMax(int n, int m, int k, vector<vector<int>> &mat){
	int maxi=0;
	vector<vector<int>> memo(m+1, vector<int> (k+1,-1));
	maxi= max(maxi, helper(0, k, mat, n, m, memo));
	return maxi;
}
int main(){
int t;
cin>>t;
while(t--){
	int n, m, k;
	cin>>n>>m>>k;
	vector<vector<int>> mat(n+1, vector<int> (m, 0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>mat[i][j];
		}
	}

	cout<<findMax(n, m, k, mat)<<endl;
}

return 0;
}