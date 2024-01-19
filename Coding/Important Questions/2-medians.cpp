#include <bits/stdc++.h>
using namespace std;

int med_main(priority_queue< int, vector <int>, greater <int> >& p, priority_queue< int, vector <int> >& q, int ele) {
    if(ele <= q.top())
        q.push(ele);
    else
        p.push(ele);

    if(p.size() - q.size() ==2) {
        q.push(p.top());
        p.pop();
        return q.top();
    } else if(q.size() - p.size() ==2) {
        p.push(q.top());
        q.pop();
        return q.top();
    }

    if(p.size() > q.size())
        return p.top();
    else
        return q.top();
}

int main() {
    int i,j,k,n;
    int med=0;
    cin>>n;
    int arr[10004];

    for(i=1;i<=n;i++){
        cin>>arr[i];
    }

    priority_queue< int, vector <int>, greater <int> > pqmin;
    priority_queue<int, vector <int> > pqmax;

    med = arr[1] + min(arr[1],arr[2]);
    pqmax.push(min(arr[1],arr[2]));
    pqmin.push(max(arr[1],arr[2]));

    for(i=3; i<=n; i++) {
        med = med + med_main(pqmin,pqmax, arr[i]);
    }

    med = med%n;
    cout<<med;
    
    return 0;
}
