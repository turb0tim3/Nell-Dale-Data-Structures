#include <iostream>
#include <string>
using namespace std;

class ItemType{
private:
	char value;
public:
	char get_value(){
		return value;
	}
	void set_value(char x){
		value = x;
	}
};


struct TreeNode{
	ItemType object;
	TreeNode *left;
	TreeNode *right;
};



class BST{
private:
	TreeNode *topnode;
public:
	BST(){
		topnode = NULL;
	}
	void Insert(TreeNode *&tnode,ItemType item){
		if (tnode == NULL){
			tnode = new TreeNode;
			tnode->right = NULL;
			tnode->left = NULL;
			tnode->object =item;
		}
		if(item.get_value() < tnode->object.get_value()){
			Insert(tnode->left,item);
		}
		if(item.get_value() > tnode->object.get_value()){
			Insert(tnode->right,item);
		}
	}
	void InsertItem(ItemType item){
		Insert(topnode,item);
	}


	void GP(TreeNode *tnode,ItemType &dt){
		while(tnode->right != NULL){
			tnode = tnode->right;
		}
		dt = tnode->object;
	}

	void DN(TreeNode *&tnode){
		ItemType dt;
		TreeNode *tmPtr;
		tmPtr = tnode;
		if (tnode->left == NULL){
			tnode = tnode->right;
			delete tmPtr;
		}else if (tnode->right == NULL){
			tnode = tnode->left;
			delete tmPtr;
		}else{
			GP(tnode->left,dt);
			tnode->object =dt;
			Del(tnode->left,dt);
		}
	}

	void Del(TreeNode *&tnode,ItemType item){
		if (item.get_value() < tnode->object.get_value()){
			Del(tnode->left,item);
		} else if (item.get_value() > tnode->object.get_value()){
			Del(tnode->right,item);
		}else{
			DN(tnode);
		}
	}

	void DeleteItem(ItemType item){
		Del(topnode,item);
	}


	void PrintTree(TreeNode *tnode){
		if (tnode != NULL){
			PrintTree(tnode->left);  
			PrintTree(tnode->right);
			cout << tnode->object.get_value(); 
			// We are using POST_ORDER in this case.
		}
	}

	void Print() {
		PrintTree(topnode);
	}

};


int main(){
	BST bst1;
	ItemType i1,i2,i3,i4,i5,i6,i7,i8;
	i1.set_value('A');
	i2.set_value('B');
	i3.set_value('C');
	i4.set_value('D');
	i5.set_value('E');
	i6.set_value('F');
	i7.set_value('J');
	i8.set_value('K');
	bst1.InsertItem(i1);
	bst1.InsertItem(i2);
	bst1.InsertItem(i3);
	bst1.InsertItem(i4);
	bst1.InsertItem(i5);
	bst1.InsertItem(i6);
	bst1.InsertItem(i7);
	bst1.InsertItem(i8);

	bst1.Print();

	bst1.DeleteItem(i2);
	bst1.DeleteItem(i4);
	bst1.DeleteItem(i6);

	cout << endl;
	bst1.Print();



	return 0;
	
}



/* In this program, first we created ItemType class to design our items, then we created TreeNode that will help us to build Binary Search Tree fundamentally. After defining TreeNode, we start to define BST with a private TreeNode value topnode.
 Topnode has 3 values in it: Object, left and right pointers. So that we are going to have values in left(smaller ones) and right(bigger ones) branches. But to delete something, we need to be able to insert something first. Therefore we are going to implement InsertItem.
 InsertItem function has one component which is called Insert. Insert function checks whether the treenode pointer is null or not, and if the treenode is not null, it compares the value of object in treenode and then decides the direction. After inserting elements, we create DeleteItem member function.
 There are 3 different components in this function called GP,DN, and Del. These components compare the value of object to given object's value,find the object and delete it. To understand whether we successfully deleted or not, we implement print function that is built for POST_ORDER. Finally we prove that our DeleteItem function works. */