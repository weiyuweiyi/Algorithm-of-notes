#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010;
const int INF = 1000000;
map<int, string> inttostring;
map<string, int> stringtoint;
map<string, int> Gang;
int G[maxn][maxn] = {0};
int weight[maxn] = {0};
bool vis[maxn] = {false};
int n, k, numperson = 0;

void DFS(int nowvisit, int &head, int &nummember, int &totalvalue)
{
    nummember++;
    vis[nowvisit] = true;
    if (weight[nowvisit] > weight[head])
    {
        head = nowvisit;
    }
    for (int i = 0; i < numperson; i++)
    {
        if (G[nowvisit][i] > 0)
        {
            totalvalue += G[nowvisit][i];
            G[nowvisit][i] = G[i][nowvisit] = 0;
            if (vis[i] == false)
            {
                DFS(i, head, nummember, totalvalue);
            }
        }
    }
}

void DFSTrave()
{
    for (int i = 0; i < numperson; i++)
    {
        if (vis[i] == false)
        {
            int head = i, nummember = 0, totalvalue = 0;
            DFS(i, head, nummember, totalvalue);
            if (nummember > 2 && totalvalue > k)
            {
                Gang[inttostring[head]] = nummember;
            }
        }
    }
}
int change(string str)
{
    if (stringtoint.find(str) != stringtoint.end())
    {
        return stringtoint[str];
    }
    else
    {
        stringtoint[str] = numperson;
        inttostring[numperson] = str;
        return numperson++;
    }
}
int main()
{
    int w;
    string str1, str2;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTrave();
    cout << Gang.size() << endl;
    map<string, int>::iterator it;
    for (it = Gang.begin(); it != Gang.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}