#include "iostream"
using namespace std;
void generatebinary(int n, string s){
	if(s.length()==n){
	     cout<<s<<endl;
	     return;
}
	else{
		generatebinary(n, s+"0");
		generatebinary(n, s+"1");
	}
}
int main(){
	int n;
	cin>>n;
	generatebinary(n,"");
}
