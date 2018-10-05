#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
int *visited, max_cost=0;

int smallest(int* dist, int n)
{
int min=max_cost*n,pos=-1;
for(int i=0;i<n;i++)
if(!visited[i]&&dist[i]!=-1&&dist[i]<min)
{
  min=dist[i];
  pos=i;
}
return pos;
}

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
int *dist=new int[adj.size()];
visited=new int[adj.size()]; 

for(int i=0;i<adj.size();i++)
dist[i]=-1;

for(int i=0;i<adj.size();i++)
visited[i]=0;

dist[s]=0;
int v;

while( ( v=smallest( dist, adj.size() ) ) !=-1 )
{
if(v==t) return dist[v];
visited[v]=1;
for(int i=0;i<adj[v].size();i++)
  if( !visited[adj[v][i]] && ( dist[adj[v][i]]==-1 || ( dist[adj[v][i]]>(dist[v]+cost[v][i]) ) ) )
    {dist[adj[v][i]]=dist[v]+cost[v][i];}

}

  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
    if(w>max_cost)
      max_cost=w;
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
