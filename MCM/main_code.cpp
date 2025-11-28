// 1.MCM
// 2.Printing MCM
// 3.Evaluate Expression to True Boolean Parenthesization Recursive
// 4.Min/Max value of an Expression
// 5.Palindrome Partitioning
// 6.Scramble String
// 7.Egg Dropping Problem

#include <bits/stdc++.h>
using namespace std;

//MCM template
int solve(int arr[],int i, int j){

    //this condition will change based on Problem statement
    if(i>j) return 0;

    //this k loop will be change based on Problem Statement
    for(int k = i;k<j;k++){
        //this "+" will be anything based on Problem Statement
        int tempAns = solve(arr,i,k) + solve(k+1,j);

        //this Function Can be anything to find the ans
        ans = anyFunction(tempAns);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}

