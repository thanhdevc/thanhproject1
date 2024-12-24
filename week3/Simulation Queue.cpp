#include "iostream"
#include "queue"
#include "string"
#include <sstream> 
using namespace std;
int main(){
	string s;
	queue<int> t;
	while(true){
		getline(cin,s);
		istringstream iss(s); 
		string temp;
		iss>>temp;
		int x;
	  if(temp=="PUSH"){
		iss>>x;
		t.push(x);
	}
	  else if(temp=="POP"){
	  	if(!t.empty()){
		  cout<<t.front()<<endl;
		  t.pop();
	}
        else{
        	cout<<"NULL"<<endl;
		}    
	}
		else break;
}
}

