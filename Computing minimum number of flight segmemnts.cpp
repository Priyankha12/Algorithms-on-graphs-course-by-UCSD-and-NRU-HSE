#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
int n_o_t(int x)
{
  if(x==1) return 0;
  return 1;
}

/*int colored(int *arr, int n)
{
  for(int i=0;i<n;i++)
    if(arr[i]==-1) return 0;
  return 1;
}*/

int* color;
int bfs(vector<vector<int> > &adj, int s) {
  //write your code here
queue<int> q;

color[s]=1;
q.push(s);

while(!q.empty())
{
  int u=q.front();
  q.pop();
  
  for(int i=0;i<adj[u].size();i++)
    {
  
    if(color[u]==color[adj[u][i]]) return 0;
    else if(color[adj[u][i]]==-1)
    {
      q.push(adj[u][i]);
      color[adj[u][i]]=n_o_t(color[u]);
     }
  }
    
}

  return 1;
}

int bipartite(vector<vector<int> > &adj)
{
for(int i=0;i<adj.size();i++)
  color[i]=-1;
for(int i=0;i<adj.size();i++)
  if(color[i]==-1)
    if(bfs(adj,i)==0)return 0;
return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  color= new int[n];
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  
   std::cout<<bipartite(adj);
}
