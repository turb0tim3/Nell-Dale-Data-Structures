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


class Stack{
private:
	ItemType items[1000];
	int top;
public:
	Stack(){top = -1;}
	void Push(ItemType item){
		top ++;
		items[top] = item;
	}
	ItemType Top(){
		return items[top];
	}
	void Pop(){
		top--;
	}
	int Count(){
		int count = top +1;
		return count;
	}

};


int main(){
	Stack stack1;
	ItemType i1,i2,i3;
	i1.set_value(1);
	i2.set_value(2);
	i3.set_value(3);
	stack1.Push(i1);
	cout << stack1.Top().get_value() << endl << stack1.Count() << endl;
	stack1.Pop();
	cout << stack1.Count() << endl;
	stack1.Push(i1);
	stack1.Push(i2);
	stack1.Push(i3);
	cout << stack1.Count();

}



