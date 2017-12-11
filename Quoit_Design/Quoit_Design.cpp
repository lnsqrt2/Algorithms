#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#define MAX 20
using namespace std;

struct point
{
	double x,y;
};

bool cmpx(point a,point b)
{
	return a.x < b.x;
}

bool cmpy(point a,point b)  
{  
    return a.y < b.y;  
}

double distance(point a,point b)//求两点距离
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


double min(point p[],point min_p[],int low,int high)
{
	double d,d1,d2,d3;
	if(high-low==1)//两个点
	{
		min_p[0].x=p[low].x;min_p[0].y=p[low].y;
        min_p[1].x=p[high].x;min_p[1].y=p[high].y;
		return distance(p[low],p[high]);
	}
	else if(high-low==2)//三个点
	{
		d1=distance(p[low],p[low+1]);
        d2=distance(p[low+1],p[high]);
        d3=distance(p[low],p[high]);
        if((d1<d2)&&(d1<d3)){
            min_p[0].x=p[low].x;min_p[0].y=p[low].y;
            min_p[1].x=p[low+1].x;min_p[1].y=p[low+1].y;
            return d1;
        }
        else if(d2<d3){
            min_p[0].x=p[low+1].x;min_p[0].y=p[low+1].y;
            min_p[1].x=p[high].x;min_p[1].y=p[high].y;
            return d2;
        }
        else {
            min_p[0].x=p[low].x;min_p[0].y=p[low].y;
            min_p[1].x=p[high].x;min_p[1].y=p[high].y;
            return d3;
        }
	}
	
	//递归调用
	int mid = (low+high)/2;
	d1=min(p,min_p,low,mid);
	d2=min(p,min_p,mid+1,high);
	d = d1 < d2 ? d1 : d2;//d为较小值
	
	int i,k=0;
	point temp[MAX];
	for(i = low; i <= high; i++)//L-d到L+d之间的点放入temp中
    {  
        if(fabs(p[mid].x-p[i].x) <= d)  
            temp[k++] = p[i];  
    }  
	sort(temp,temp+k,cmpy);//按照y升序排列

	for(i=0;i<k;i++)
	{
		for(int j = i+1; j < k && temp[j].y-temp[i].y<d; j++)  
        {  
            d3 = distance(temp[i],temp[j]);
            if(d > d3)
            {
  				min_p[0].x=temp[i].x;min_p[0].y=temp[i].y;
           		min_p[1].x=temp[j].x;min_p[1].y=temp[j].y;
                d = d3;  
            }
        }
	}
	return d;
}

int main(void)
{
	int i=0;
	int n=0;//点的个数
	double min_dis;//最小距离
	struct point p[MAX];
	struct point min_p[2];
	ifstream  readFile("D:\\Quoit_Design_Test.txt");
	
	while(!readFile.eof())
	{
		readFile>>p[i].x>>p[i].y;
		i++;
		n++;
	}

	sort(p,p+n,cmpx);//先把所有点按照横坐标从小到大排序
	min_dis=min(p,min_p,0,n-1);

	cout<<"("<< min_p[0].x <<","<<min_p[0].y<<")"<<endl;
	cout<<"("<< min_p[1].x <<","<<min_p[1].y<<")"<<endl;
	cout<<"最小距离为"<< min_dis<<endl;

	for(i=0;i<n;i++)
	cout<<"("<< p[i].x <<","<<p[i].y<<")"<<endl;
	//cout << n << endl;

	cout << "over" << endl;
	return 0;
}
