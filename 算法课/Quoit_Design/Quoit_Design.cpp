#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <math.h>
#define MAX 20
using namespace std;

struct MyPoint
{
	double x,y;
}p[MAX];

class MyPair//save the closest MyP(may have more than one MyP)
{
public:
	MyPoint p1[MAX];
	MyPoint p2[MAX];
	int num;
	double dis;
public:
	MyPair()
	{
		num = 0;
		dis = 99999999;
	};
	~MyPair(){};
	void NewDis(MyPoint a,MyPoint b,double d)//reload the new pair and delete the old
	{
		num=0;
		dis=d;
		p1[num].x=a.x;
		p1[num].y=a.y;
		p2[num].x=b.x;
		p2[num].y=b.y;
		num++;
		return;
	};
	void MorePoint(MyPoint a,MyPoint b)//new pair with the same distance
	{
		p1[num].x=a.x;
		p1[num].y=a.y;
		p2[num].x=b.x;
		p2[num].y=b.y;
		num++;
		return;
	};
}MyP;

bool cmpx(MyPoint a,MyPoint b)//sort according to x
{
	return a.x < b.x;
}

bool cmpy(MyPoint a,MyPoint b)//sort according to y
{  
    return a.y < b.y;  
}

double MyDistance(MyPoint a,MyPoint b)//caculate the diatance of two MyPoint
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void compare_p(MyPoint a,MyPoint b,double d)
{
	for(int i=0;i<MyP.num;i++)
		if((MyP.p1[i].x==a.x)&&(MyP.p1[i].y==a.y)&&(MyP.p2[i].x==b.x)&&(MyP.p2[i].x==b.x))
			return;
	if(d<MyP.dis)
		MyP.NewDis(a,b,d);
	else if(d==MyP.dis)
		MyP.MorePoint(a,b);
	return;
}

double solve(int low,int high)//core
{
	double d;
	if(high-low==0)//only one point
	{
		return 0;
	}
	if(high-low==1)//two points
	{
		d = MyDistance(p[low],p[high]);
		compare_p(p[low],p[high],d);
		return d;
	}
	if(high-low==2)//three points
	{
		double d1,d2,d3;
		d1=MyDistance(p[low],p[low+1]);
        d2=MyDistance(p[low+1],p[high]);
        d3=MyDistance(p[low],p[high]);
        if((d1<d2)&&(d1<d3))//d1 is the smallest
        {
        	d=d1;
        	compare_p(p[low],p[low+1],d);
        }
        if((d2<d1)&&(d2<d3))//d2 is the smallest
        {
        	d=d2;
        	compare_p(p[low+1],p[high],d);
        }
        if((d3<d1)&&(d3<d2))//d3 is the smallest
        {
        	d=d3;
        	compare_p(p[low],p[high],d);
        }
        if((d1==d2)&&(d1<d3))//d1 and d2 is smaller than d3
        {
        	d=d1;
        	if(d<MyP.dis)
        	{
				MyP.NewDis(p[low],p[low+1],d);
				MyP.MorePoint(p[low+1],p[high]);
        	}
			else if(d==MyP.dis)
			{
				MyP.MorePoint(p[low],p[low+1]);
				MyP.MorePoint(p[low+1],p[high]);
			}
        }
        if((d1==d3)&&(d1<d2))//d1 and d3 is smaller than d2
        {
        	d=d1;
        	if(d<MyP.dis)
        	{
				MyP.NewDis(p[low],p[low+1],d);
				MyP.MorePoint(p[low],p[high]);
        	}
			else if(d==MyP.dis)
			{
				MyP.MorePoint(p[low],p[low+1]);
				MyP.MorePoint(p[low],p[high]);
			}
        }
        if((d2==d3)&&(d2<d1))//d2 and d3 is smaller than d1
        {
        	d=d2;
        	if(d<MyP.dis)
        	{
				MyP.NewDis(p[low+1],p[high],d);
				MyP.MorePoint(p[low],p[high]);
        	}
			else if(d==MyP.dis)
			{
				MyP.MorePoint(p[low+1],p[high]);
				MyP.MorePoint(p[low],p[high]);
			}
        }
		return d;
	}
	else//more than three points
	{
		int mid = (low+high)/2;
		double d1 = solve(low,mid);
		double d2 = solve(mid+1,high);
		double d3 = 99999999;
		d = d1 < d2 ? d1 : d2;
		int i,k=0;
		MyPoint temp[MAX];
		for(i = low; i <= high; i++)
		{
		    if(fabs(p[mid].x-p[i].x) <= d)
		        temp[k++] = p[i];
		}  
		sort(temp,temp+k,cmpy);
		for(i=0;i<k;i++)
		{
			for(int j = i+1; j < k && temp[j].y-temp[i].y<=d; j++)
	        {
	            d3 = MyDistance(temp[i],temp[j]);
	            if(d3<=d)
	            {
	            	d = d3;
	            	compare_p(temp[i],temp[j],d);
	            }
	        }
		}
		return d;
	}
}

int main(void)
{
	int i=0;
	int n=0;
	ifstream  readFile("D:\\Quoit_Design_Test.txt");
	while(!readFile.eof())//read file
	{
		readFile>>p[i].x>>p[i].y;
		i++;
		n++;
	}
	sort(p,p+n,cmpx);//sort according to x
	solve(0,n-1);
	for(i=0;i<MyP.num;i++)
	{
		cout<<"("<< MyP.p1[i].x <<","<<MyP.p1[i].y<<")";
		cout<<"("<< MyP.p2[i].x <<","<<MyP.p2[i].y<<")"<<endl;
	}
	cout<<"the smallest distance is: "<< MyP.dis<<endl;
	// for(i=0;i<n;i++)
	// cout<<"("<< p[i].x <<","<<p[i].y<<")"<<endl;
	// cout << n << endl;
	//cout << "over" << endl;
	return 0;
}
