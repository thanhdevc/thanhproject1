#include "iostream"
#include "cmath"
using namespace std;
int main(){
	int n,count=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%2==0) count++;
	}
	cout<<n-count<<" "<<count;
}
