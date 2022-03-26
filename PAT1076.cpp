#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAXV = 1010;
struct Node
{
    int id;
    int layer;
    /* data */
};
vector<Node> Adj[MAXV];
bool inq[MAXV] = {false};
int BFS(int s, int L)
{
    int numforward = 0;
    queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while (!q.empty())
    {
        Node topnode = q.front();
        q.pop(); //取出队首元素
        int u = topnode.id;
        for (int i = 0; i < int(Adj[u].size()); i++)
        {
            Node next = Adj[u][i];
            next.layer = topnode.layer + 1;
            if (inq[next.id] == false && next.layer <= L)
            {
                q.push(next);
                inq[next.id] = true;
                numforward++;
            }
        }
    }
    return numforward;
}
int main()
{
    Node user;
    int n, L, numfollow, idfollow;
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; i++)
    {
        user.id = i;
        scanf("%d", &numfollow);
        for (int j = 0; j < numfollow; j++)
        {
            scanf("%d", &idfollow);
            Adj[idfollow].push_back(user);
        }
    }
    int numquery, s;
    scanf("%d", &numquery);
    for (int i = 0; i < numquery; i++)
    {
        memset(inq, false, sizeof(inq));
        scanf("%d", &s);
        int numforward = BFS(s, L);
        printf("%d\n", numforward);
    }
    return 0;
}