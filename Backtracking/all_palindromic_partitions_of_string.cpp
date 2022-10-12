
#include <bits/stdc++.h>
using namespace std;
 
bool checkPalin(string s)
{
    int len = s.length();
    len--;
    for (int i=0; i<len; i++)
    {
        if (s[i] != s[len])
            return false;
        len--;
    }
    return true;
}
 
void print(vector<vector<string> > p)
{
    for (int i = 0; i < p.size(); ++i)
    {
        for(int j = 0; j < p[i].size(); ++j)
            cout << p[i][j] << " ";
        cout << endl;
    }
    return;
}

void addStrings(vector<vector<string> > &v, string &s,
                vector<string> &temp, int index)
{
    int len = s.length();
    string str;
    vector<string> current = temp;
    if (index == 0)
        temp.clear();
    for (int i = index; i < len; ++i)
    {
        str = str + s[i];
        if (checkPalin(str))
        {
            temp.push_back(str);
            if (i+1 < len)
                addStrings(v,s,temp,i+1);
            else
                v.push_back(temp);
            temp = current;
        }
    }
    return;
}
 
void parti(string s, vector<vector<string> >&v)
{
    vector<string> temp;
    addStrings(v, s, temp, 0);
    print(v);
    return;
}
 
// Driver code
int main()
{
    string s;
    cin>>s;
    vector<vector<string> > partitions;
    parti(s, partitions);
    return 0;
}