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
    toposort[s--]=(x+1);
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
int main() {
  size_t n, m;
  std::cin >> n >> m;
  visited=new int[n];
  toposort=new int[n];
  s=n-1;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
dfs(adj);
for(int i=0;i<n;i++)
std::cout<<toposort[i]<<" ";
}
