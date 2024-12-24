#include "iostream"
#include "sstream"
#include "string"
using namespace std;
struct TreeNode{
	int data;
	TreeNode* firstChild;
	TreeNode* nextSibling;
	
	TreeNode(int key): data(key), firstChild(nullptr), nextSibling(nullptr){};
};
TreeNode* root = nullptr;

TreeNode* makeroot(int data){
    return new TreeNode(data);
}
TreeNode* find(TreeNode* root, int val){
	if(root==nullptr) return nullptr;
	if(root->data==val) return root;

	TreeNode* foundNode = find(root->firstChild,val);

	if(foundNode!=nullptr) return foundNode;
	else return find(root->nextSibling,val);
}
void insert(TreeNode* root, int val){
	if (find(root, val) != nullptr || root == nullptr) return;
	TreeNode* child = new TreeNode(val);
	if(root->firstChild==nullptr) root->firstChild=child;
	else{
		TreeNode* sibling = root->firstChild;
		while(sibling->nextSibling!=nullptr){
			sibling = sibling->nextSibling;
		}
		sibling->nextSibling = child;
	}
}
void preOrder(TreeNode* root){// học vẹt
	if(root==nullptr) return;
	cout<<root->data<<" ";
	preOrder(root->firstChild);
	preOrder(root->nextSibling);
}
void inOrder(TreeNode* root) {// hoc vet
    if (root == nullptr) return;
    TreeNode* child = root->firstChild;
    int count = 0;

    while (child != nullptr) {
        count++;
        child = child->nextSibling;
    }
    
    child = root->firstChild;
    for (int i = 0; i < count / 2; ++i) {
        inOrder(child);
        child = child->nextSibling;
    }
    cout << root->data << " ";
    for (int i = count / 2; i < count; ++i) {
        inOrder(child);
        child = child->nextSibling;
    }
}
void postOrder(TreeNode* root){//hoc vet
	if(root==nullptr) return;
	postOrder(root->firstChild);
	cout<<root->data<<" ";
	postOrder(root->nextSibling);
}

int main(){
	string s;
	while(true){
		getline(cin,s);
		istringstream iss(s);
		string t;
		iss>>t;
		if(t=="MakeRoot"){
			int x;
			iss>>x;
			root = makeroot(x);
		}
		else if(t=="Insert"){
			int u,v;
			iss>>u>>v;
			insert(find(root,v),u);
		}
		else if(t=="PreOrder"){
			preOrder(root);
			cout << endl;  
		}
		else if(t=="InOrder"){
			inOrder(root);
			cout << endl;  
		}
		else if(t=="PostOrder"){
			postOrder(root);
			cout << endl;  
		}
		else break;
	}
}
