/*
Given N integers, count the total pairs of integers that have a difference of K.

Input Format 
1st line contains N & K (integers).
2nd line contains N numbers of the set. All the N numbers are assured to be distinct.

Output Format
One integer saying the number of pairs of numbers that have a diff K.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int pairs(vector < int > a,int k) {
    int ans=0;
    int i=0;
    int j=0;
    int size = a.size();
    int dupArray[size];
    for(i=0;i<size;i++)
    {
        dupArray[i]=a[i];
    }

    qsort(dupArray, size, sizeof(int), compare);

    for(i=0;i<size;i++)
    {
        int *found = NULL;
        int key=a[i]-k;
        found = (int*) bsearch (&key, dupArray, size, sizeof (int), compare);
        if( found != NULL )
        {
            ans++;
        }
        key = a[i]+k;
        found = (int*) bsearch (&key, dupArray, size, sizeof (int), compare);

        if( found != NULL )
        {
            ans++;
        }
    }

    return ans/2;
}


int main() {
    int res;

    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }

    res = pairs(_a,_k);
    cout << res;

    return 0;
}
