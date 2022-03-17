#include <iostream>
#include <string>
using namespace std;

int MAX_ITEMS = 1000;

class ItemType{
private:
	int value;
public:
	void set_value(int number){
		value = number;
	}
	int get_value(){
		return value;
	}
};


struct NodeType;

class StackType{
public:
	void Push(ItemType newItem);
	void Pop();
	ItemType Top();
	int Count();
private:
	NodeType *topPtr;
};

struct NodeType{
	ItemType info;
	NodeType *next;
};

void StackType::Push(ItemType newItem){
	NodeType *location;
	location = new NodeType;
	location->info = newItem;
	location->next = topPtr;
	topPtr = location;
}

void StackType::Pop(){
	NodeType *tempPtr;
	tempPtr = topPtr;
	topPtr = topPtr->next;
	delete tempPtr;
}

ItemType StackType::Top(){
	return topPtr->info;
}

int StackType::Count(){
	int count = 0;
	while(topPtr != NULL){
		count++;
		NodeType *tempPtr;
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}

	return count;
}


int main(){
	StackType s1;
	ItemType i1,i2;
	i1.set_value(1);
	i2.set_value(2);
	s1.Push(i1);
	s1.Push(i2);
	//cout << s1.Count() << endl;
	cout << s1.Top().get_value() << endl;
	s1.Pop();
	cout << s1.Top().get_value();

}