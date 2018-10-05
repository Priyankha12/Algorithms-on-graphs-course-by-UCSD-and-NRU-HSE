#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;

double dist(int x1,int y1, int x2, int y2)
{
double d=(double)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
return d;
}


int best_value(double* value, int* visited, int n)
{
int pos=-1; 
double min;
int i;
  for(i=0;i<n;i++)
    if(!visited[i]&&value[i]!=-1.)
    {
      min=value[i];pos=i; break;
    }
    for(;i<n;i++)
      if(!visited[i]&&value[i]!=-1&&value[i]<min)
      {
        min=value[i]; pos=i;
      }
      return pos;
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  double* value= new double[x.size()];
  int* visited=new int[x.size()];
  for(int i=0;i<x.size();i++){ value[i]=-1.; visited[i]=0;}
  int s=0;
  value[s]=0.;
  int n=x.size();
  
 for(int i=0;i<n;i++)
  {
    int v=best_value(value,visited,n);

    result+=value[v];
    //std::cout<<"\nVisited: "<<v<<" Value: "<<value[v];
    visited[v]=1;
    for(int j=0;j<n;j++)
      if(j!=v&&!visited[j])
        if(value[j]==-1.||value[j]>(double)(dist(x[j],y[j],x[v],y[v])))
          value[j]=(double)dist(x[j],y[j],x[v],y[v]);

  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10)<< minimum_distance(x, y) << std::endl;
}
