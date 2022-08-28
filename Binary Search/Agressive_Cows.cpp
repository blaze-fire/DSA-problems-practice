/*
 Input:

1
5 3
1
2
8
4
9

Output: 3
 */

#include<iostream>
#include<algorithm>

using namespace std;

bool check(int stalls[], int n, int c, int min_sep){
    int count = 1;
    int last = stalls[0];
    for(int i=1; i<n; i++){
        if(stalls[i] - last >= min_sep){
            count++;

            if(count == c){
                return true;
            }

            last = stalls[i];
        }
    }

    return false;

}


int main(){

    int tc;
    cin>>tc;

    while(tc--){
        int n,c;
        cin>>n>>c;

        int stalls[n];
        for(int i=0; i<n; i++){
            cin>>stalls[i];
        }

        sort(stalls, stalls+n);

        int s=0, e=stalls[n-1] - stalls[0], ans = -1;

        while(s <= e){
            int mid = (s+e)/2;
            bool canPlace = check(stalls, n, c, mid);
            if(canPlace){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        cout<<ans<<endl;

    }

    cout<<endl;
    return 0;
}
