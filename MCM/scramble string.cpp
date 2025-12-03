// https://www.interviewbit.com/problems/scramble-string/
// Given two strings A and B of the same length, determine if B is a scrambled string of S.

#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;

bool solve(string s1, string s2)
{
    if (s1.compare(s2) == 0)
        return true;
    if (s1.size() <= 1)
        return false;

    string key = s1 + " " + s2;

    if (mp.find(key) != mp.end())
        return mp[key];

    bool flag = false;
    int n = s1.size();

    //substr(pos,len)

    for (int i = 1; i < n; i++)
    {
        //if (swap || no swap)
        if ((solve(s1.substr(0, i), s2.substr(n - i, i)) && solve(s1.substr(i, n - i), s2.substr(0, n - i))) || (solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n - i), s2.substr(i, n - i))))
        {
            flag = true;
            break;
        }
    }

    return mp[key] = flag;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() != s2.size())
    {
        cout << "0\n";
    }
    else if (s1.empty() || s2.empty())
    {
        cout << "0\n";
    }
    else
    {
        mp.clear();
        cout << solve(s1, s2);
    }

    return 0;
}
