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

template <class ItemType>
struct NodeType{
	ItemType info;
	NodeType *next;
};

class QueType{
private:
	NodeType<ItemType> *front;
	NodeType<ItemType> *rear;
public:
	QueType(){
		front = NULL;
		rear = NULL;
	};
	void Enqueue(ItemType newItem){
		NodeType<ItemType> *newNode;
		newNode = new NodeType<ItemType>;
		newNode->info = newItem;
		newNode->next = NULL;
		if (rear == NULL){
			front = newNode;
		}else{
			rear->next = newNode;
		}
		rear = newNode;
	}
	void Dequeue(ItemType &item){
		NodeType<ItemType> *tempPtr;

		tempPtr = front;
		item = front->info;
		front = front->next;
		if(front == NULL){
			rear = NULL;
		}
		delete tempPtr;

	}

	ItemType Front(){
		return front->info;
	}


};




int main(){

	QueType q1;
	ItemType i1,i2,i3;
	i1.set_value(1);
	i2.set_value(2);
	i3.set_value(3);
	q1.Enqueue(i1);
	q1.Enqueue(i2);
	q1.Enqueue(i3);
	cout << q1.Front().get_value() << endl;
	q1.Dequeue(i1);
	cout << q1.Front().get_value() << endl;
	q1.Dequeue(i2);
	cout << q1.Front().get_value() << endl;
}

