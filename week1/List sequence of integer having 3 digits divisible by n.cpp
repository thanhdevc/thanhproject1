#include "iostream"
using namespace std;
int main(){
	int n,temp;
	cin>>n;
	int i=1;
	while(temp<1000){
		temp=n;
		temp*=i;
		if(temp>=1000) break;
		if(temp>=100) cout<<temp<<" ";
		i++;
	}
}
