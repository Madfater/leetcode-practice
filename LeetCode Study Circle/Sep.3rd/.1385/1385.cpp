#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<math.h>
using namespace std;

vector<int> constructRectangle(int area) 
{ 
        vector<int>ans;

        for(int i=1;i<=sqrt(area);i++)
            if(area%i==0)
                if(i<=(area/i))
                    ans={area/i,i};

        return ans;
}