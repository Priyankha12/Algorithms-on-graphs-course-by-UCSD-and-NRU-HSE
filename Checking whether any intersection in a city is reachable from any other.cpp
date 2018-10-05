#include <iostream>
#include <vector>

using std::vector;
using std::pair;
int* visited, *toposort;int s;

void explore(vector<vector<int> > &adj, int x) 
{
  //std::cout<<"\nVisiting: "<<x;
  visited[x]=1;
  int i;
  for(i=0;i<adj[x].size();i++)
    if(!visited[adj[x][i]])
      explore(adj,adj[x][i]);
    //std::cout<<"\n"<<x<<" Over!!";
    toposort[s--]=x;
}

void dfs(vector<vector<int> > &adj)
{
  int i;
  for(i=0;i<adj.size();i++)
    { //std::cout<<"\nInside dfs: "<<i<<" visited:"<<visited[i];
      if(!visited[i])
      {//std::cout<<"\nCalling Explore: "<<i;
    explore(adj,i);
      }
    }
}

//Vertex with highest postorder in the reverse graph belongs to the sink component in the original graph. If you start exploring from a sink vertex then you will get all 
//the vertices in teh sink component.

void strongly_connected_components(vector<vector<int> >&adj, int x)
{
visited[x]=1;
int i;
for(i=0;i<adj[x].size();i++)
  {if(!visited[adj[x][i]])
    {strongly_connected_components(adj,adj[x][i]);}
  }
}
int main() {
  size_t n, m;
  std::cin >> n >> m;
  visited=new int[n];
  toposort=new int[n];
  s=n-1;
  vector<vector<int> > adj(n, vector<int>()), adjr(n,vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adjr[y-1].push_back(x-1);
  }
dfs(adjr);
int comp=0;
for(int i=0;i<n;i++)
visited[i]=0;
for(int i=0;i<n;i++)
  if(!visited[toposort[i]])
{
  comp++;
strongly_connected_components(adj,toposort[i]);
}
std::cout<<comp;
}
