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
		if(s[i]==':'){
	      count1++;
	      temp=pos;
	      pos=i;
	  }
	}
	for(int i=1;i<3;i++){
		t>>b>>a[i];
	}
	if(a[0]>23||a[0]<0||a[1]>59||a[1]<0||a[2]<0||a[2]>59||count1!=2||s.length()-1-pos!=2||pos-temp-1!=2) cout<<"INCORRECT";
	else{
		cout<<a[0]*3600+a[1]*60+a[2];
	}
	
	
}
