#include <iostream>
#include <vector>

using std::vector;
using std::pair;

 int explore(vector<vector<int> > &adj, int x, int* visited, int* cur_stack)
{
    
    int i;
    visited[x]=1;
    cur_stack[x]=1;
    //std::cout<<"\n"<<x;
    for(i=0;i<adj[x].size();i++)
    if(!visited[adj[x][i]])
    {
         if(explore(adj,adj[x][i],visited,cur_stack)==1)return 1;
         else continue;
    }
    else if(cur_stack[adj[x][i]]==1) return 1;
    cur_stack[x]=0;
    //std::cout<<"\nReturning 0";
    return 0;
}
    

int dfs(vector<vector<int> > &adj)
{
    int i;
for(i=0;i<adj.size();i++)
{
  //std::cout<<"\nFrom DFS calling: "<<i;
int *visited=new int[adj.size()];
int *cur_stack=new int[adj.size()];
for(int j=0;j<adj.size();j++)
{visited[j]=0;
cur_stack[i]=0;
}
if(explore(adj,i,visited,cur_stack))
return 1;
}
return 0;
}
int main() {
  size_t n, m;
  std::cin >> n >> m;
  //visited= new int[n];
  //for(int i=0;i<n;i++) visited[i]=0;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }

  std::cout<<dfs(adj);
}
