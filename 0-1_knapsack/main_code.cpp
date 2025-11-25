// Theory:
// How to Identify DP problem 
//     1.Need To choice Something from Something
//     2.Nedd a OPTIMAL solution
//     3.Need to call Recursion 2 times

// DP problem and variation:
//     1.0-1 knapsack(6)
//     2.Unbounded knapsack(5)
//     3.Fibonacci(7)
//     4.Longest Common Subsequence(15)
//     5.Longest Increasing Subsequence(10)
//     6.Kadane's Algorithm(6)
//     7.Matrix Chain Multiplication(7)
//     8.Dp on tree(4)
//     9.Dp on Grid(14)
//     10.others(5)
-------------------------------Memoization Approce --------------------------

#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

int knapsack(int val[],int wt[],int w, int n){
    if(n==0 || w==0){
        return 0;
    }

    //memoization
    if(dp[n][w] != -1){
        return dp[n][w];
    }

    //Choice Diagram
    // Take or do not Take
    if(wt[n-1] <= w){
        return dp[n][w] = max((val[n-1]+knapsack(val,wt,w-wt[n-1],n-1)),knapsack(val,wt,w,n-1));
    }
    else{
        return dp[n][w] = knapsack(val,wt,w,n-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,w;
    cin>>n >> w;

    int val[n];
    int wt[n];
    for(int i=0;i<n;i++) cin>>val[i]; 
    for(int i=0;i<n;i++) cin>>wt[i]; 

    memset(dp,-1,sizeof(dp));

    //the knapsack is returning the maximum value we can put inside the bag
    int ans = knapsack(val,wt,w,n);
    cout << ans <<endl;


    return 0;
}

--------------------- TOP DOWN APPROCE ---------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,w;
    cin>>n >> w;

    int val[n];
    int wt[n];
    for(int i=0;i<n;i++) cin>>val[i]; 
    for(int i=0;i<n;i++) cin>>wt[i]; 

    int dp[n+1][w+1];

    //initialization == Base Case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    //Itration == Recursion Call
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1] <= j){
                dp[i][j] = max((val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][w]<<endl;

    return 0;
}

