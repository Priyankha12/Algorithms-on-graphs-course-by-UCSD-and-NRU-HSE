#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
using std::vector;
using std::pair;

double dist(int x1,int y1, int x2, int y2)
{
double d=(double)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
return d;
}

double clustering(vector<int> x, vector<int> y, int k) {
int n=x.size();
vector<double> medx(k), medy(k);
for(int i=0;i<k;i++)
{
	medx[i]=x[i];
	medy[i]=y[i];
}
vector<int> group(n);
for(int i=0;i<n;i++) group[i]=-1;
int count;
do{
	count=0;
	for(int i=0;i<n;i++)
	{
		double min=dist(x[i],y[i],medx[0],medy[0]);int pos=0;
		for(int j=0;j<k;j++)
			if(min>dist(x[i],y[i],medx[j],medy[j]))
			{
				min=dist(x[i],y[i],medx[j],medy[j]); pos=j;
			}
		if(group[i]!=pos)count++;
		group[i]=pos;
	}

if(count)
{
	for(int j=0;j<k;j++)
		{double sumx=0,sumy=0; int num=0;
			for(int i=0;i<n;i++)
			if(group[i]==j)
			{
				sumx+=x[i];sumy+=y[i];num++;
			}
			medx[j]=sumx/num;
			medy[j]=sumy/num;
		}
}

}while(count>0);

int i,j;double min;
for( i=0;i<n;i++)
for(j=0;j<n;j++)
	if(group[i]!=group[j])
		{min=dist(x[i],y[i],x[j],y[j]);break;}
for( i=0;i<n;i++)
for(j=0;j<n;j++)
	if(group[i]!=group[j]&&min>dist(x[i],y[i],x[j],y[j]))
		{min=dist(x[i],y[i],x[j],y[j]);}

	
return min;
}
//return -1.;



int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}