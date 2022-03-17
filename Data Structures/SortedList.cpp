#include <iostream>
#include <string>
using namespace std;


enum RelationType {
	LESS,
	EQUAL,
	GREATER
};


class ItemType{
private:
	int value;
public:

	int get_value(){
		return value;
	}

	void set_value(int x){
		value = x; 
	}

	RelationType ComparedTo(ItemType ditem){
		if (value < ditem.get_value()){
			return LESS;
		}
		if (value == ditem.get_value()){
			return EQUAL;
		}
		if (value > ditem.get_value()){
			return GREATER;
		}
		return EQUAL;
	}

};



const int MAX_ITEMS = 1000;

class SortedType{

private:
	int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
public:
	SortedType(){
		length = 0;
	}
	void InsertItem(ItemType item){
		bool moreToSearch;
		int location = 0;

		moreToSearch = (location < length);

		while(moreToSearch){

			switch(item.ComparedTo(info[location])){
				case LESS: moreToSearch = false; break;
				case GREATER: location++;moreToSearch=(location<length);break;
			}
		}
		for (int i= length;i>location;i--){
			info[i] = info[i-1];
		}
		info[location]=item;
		length++;
	}
	void DeleteItem(ItemType item){
		int location = 0;
		while (item.ComparedTo(info[location]) != EQUAL){
			location++;
		}

		for (int i = length; i>location;i--){
			info[i-1] = info[i];
		}
		length--;
	}

	int length1(){
		return length;
	}

};



int main(){
	SortedType s1;
	ItemType i1,i2,i3,i4;
	i1.set_value(1);
	i2.set_value(0);
	i3.set_value(5);
	i4.set_value(4);
	s1.InsertItem(i1);
	cout << s1.length1();
}