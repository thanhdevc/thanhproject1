#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   int n,k,count=0,sum=0;
   cin>>n>>k;
   int a[n];
   for(int i=0;i<n;i++){
   	cin>>a[i];
   	sum+=a[i];
   	 if(i>=k-1){
   	 	if(sum%2==0) count++;
   	 	sum-=a[i-k+1];
		}
   }
    cout<<count;
    return 0;
}
