#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
int  max_cost=0;

void bellman(vector<vector<int> > &adj, vector<vector<int> > &cost, int s) {

//long long *dist=new [adj.size()];
  vector<long long> distance(adj.size(), std::numeric_limits<long long>::max());
queue<int> A;
int* neg_cycle= new int[adj.size()];
for(int i=0;i<adj.size();i++)
  neg_cycle[i]=0;
//for(int i=0;i<adj.size();i++)
//dist[i]=max_cost*adj.size();

distance[s]=0;

for(int i=0;i<adj.size();i++)
{
for(int j=0;j<adj.size();j++){
if(distance[j]==std::numeric_limits<long long>::max()) continue;
for(int k=0;k<adj[j].size();k++)
  if( distance[adj[j][k]]>(distance[j]+(long long)cost[j][k]) ) 
    {distance[adj[j][k]]=distance[j]+(long long)cost[j][k];
      if(i==(adj.size()-1))
      {
        A.push(adj[j][k]);
        neg_cycle[adj[j][k]]=1;
      }
    }
}

}
while(A.size()>0)
{
int v=A.front();
A.pop();
distance[v]=(long long)-1;
for(int j=0;j<adj[v].size();j++)
  if(!neg_cycle[adj[v][j]])
    {A.push(adj[v][j]);
      neg_cycle[adj[v][j]]=1;
    }
}

for(int i=0;i<adj.size();i++)
  if(distance[i]==std::numeric_limits<long long>::max())
    std::cout<<"\n*";
  else if(distance[i]==(long long)-1)
    std::cout<<"\n-";
  else std::cout<<"\n"<<distance[i];
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
  int s;
  std::cin>>s;
 
  bellman(adj, cost,s-1);
}
