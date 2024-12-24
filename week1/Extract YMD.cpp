#include "iostream"
#include "sstream"
using namespace std;
int main(){
	string s;
	getline(cin,s);
	istringstream t(s);
	int a[3],count1=0,pos,temp;
	char b;
	t>>a[0];
	for(int i=0;i<s.length();i++){
		if(s[i]=='-'){
	      count1++;
	      temp=pos;
	      pos=i;
	  }
	}
	for(int i=1;i<3;i++){
		t>>b>>a[i];
	}
	if(a[1]>12||a[1]<1||a[2]<1||a[2]>31||count1!=2||s.length()-1-pos!=2||pos-temp-1!=2) cout<<"INCORRECT";
	else{
		for(int i=0;i<3;i++){
			cout<<a[i]<<" ";
		}
	}
	
	
}
