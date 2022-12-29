#include<bits/stdc++.h>
using namespace std ;

struct subset
{
    int parent;
    int rank;
};


// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{

    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}


void Union(struct subset subsets[], int xroot, int yroot)
{

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;


    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main(){
    int n ;
    cin>>n;
    vector<int> range(n,0);
    int m;
    cin>>m;
    vector<int> p[m];
    vector<int> d[m];
    vector<int> visited(n,1);

    for(int i=0;i<n;i++){
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        d[i]--;
        visited[d[i]] = 0 ;
    }

    struct subset subsets[n] ;
    for(int i=0;i<n;i++){
        subset[i].parent = i ;
        subset[i].rank = 0;

    }

    for(int i=0;i<m;i++){
        int x = p[i];
        int y = d[i];
        
        int x_find = find(subsets[], x);
        int y_find = find(subsets[], y);
        Union(subsets,x_find,y_find)
    }
}