#include<bits/stdc++.h>
using namespace std;


class Point 
{
	int x;
	int y;

public:

	Point(int x,int y) : x(x),y(y){}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}


};

int countTriangles(vector<Point> &points)
{

		int count=0;

		unordered_map<int,int> xpoints;
		unordered_map<int,int> ypoints;

		for(auto pt:points)
		{
			// point which have same x coordinate
			xpoints[pt.getX()]++;
			// point which have same y coordinate
			ypoints[pt.getY()]++;
		}

		// now for every point x,y taking as the foot check how many triangles can be made 
		for(auto pt:points)
		{
			int Xcount = xpoints[pt.getX()];
			int Ycount = ypoints[pt.getY()];
			count += (Xcount-1)*(Ycount-1);
		}

		return count % 10000;
}


int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	


	//  take input elements
		int N;
		cin>>N;

	
	//  array of points 
		vector<Point> pt;

	// insert input points 
		for(int i=0;i<N;i++)
		{
			int x,y;
			cin>>x>>y;
			pt.emplace_back(x,y);
		}

	// call the function 
	 	cout<<countTriangles(pt);
 
	return 0;

}