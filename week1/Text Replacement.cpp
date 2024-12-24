#include <iostream>
#include <string>
using namespace std;
int main() {
	string s1,s2,s3,res;
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);
    int pos;
	
	do{
	pos=s3.find(s1);
	s3=s3.erase(pos,s1.length());
	s3=s3.insert(pos,s2);
	} while(s3.find(s1)!=string::npos);
	
	
	cout<<s3;
    
	return 0;
}
