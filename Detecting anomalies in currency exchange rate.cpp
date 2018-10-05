#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
int  max_cost=0;

int bellman(vector<vector<int> > &adj, vector<vector<int> > &cost, int s) {

int *dist=new int[adj.size()];


for(int i=0;i<adj.size();i++)
dist[i]=max_cost*adj.size();

dist[s]=0;
int cnt;
for(int i=0;i<adj.size();i++)
{
  cnt=0;
for(int j=0;j<adj.size();j++)
for(int k=0;k<adj[j].size();k++)
  if( dist[adj[j][k]]>(dist[j]+cost[j][k]) ) 
    {cnt++;dist[adj[j][k]]=dist[j]+cost[j][k];}

}
if(!cnt) return 0;
return 1;

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
 
  std::cout << bellman(adj, cost,0);
}
