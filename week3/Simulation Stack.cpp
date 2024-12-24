#include "iostream"
#include "stack"
#include "string"
#include <sstream> 
#include "queue"
using namespace std;
int main(){
	string s;
	stack<int> t;
	queue<int> a;
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
		int topValue = t.top(); 
		t.pop(); 
        a.push(topValue);
    }
        else{
        	a.push(-100);
		}    
	}
		else break;
}
        while (!a.empty()) {
        	if(a.front()!=-100){
            cout << a.front() << endl; // Access front element
            a.pop(); // Remove the front element
        }
        else {
		  cout<<"NULL"<<endl;
		  a.pop();
	}
        
}
}
