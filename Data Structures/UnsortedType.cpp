#include <iostream>
#include <string>
using namespace std;


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

template <class ItemType>
class UnsortedType{
	private:
		NodeType<ItemType> *listData;
		int length;
		NodeType<ItemType> *currentPos;
	public:
		UnsortedType(){
			length = 0;
			listData = NULL;
		}
		bool IsFull(){
			NodeType<ItemType> *location;
			try{
				location = new NodeType<ItemType>;
				delete location;
				return false;
			}
			catch(std::bad_alloc exception){
				return true;
			}
		}
		void InsertItem(ItemType item){
			NodeType<ItemType> *location;
			location = new NodeType<ItemType>;
			location->info = item;
			location->next = listData;
			listData = location;
			length++;
		}
		void DeleteItem(ItemType item){
			NodeType<ItemType> *location = listData;
			NodeType<ItemType> *tempLocation;
			if( item.get_value() == listData->info.get_value()){
				tempLocation = location;
				listData = listData->next;
			}else{
				while(!(item.get_value() == (location->next)->info.get_value())){
					location = location->next;
				}
				tempLocation = location->next;
				location->next =(location->next)->next;
			}
			delete tempLocation;
			length--;
		}
		ItemType LD(){
			return listData->info;
		}

};


int main(){
	UnsortedType<ItemType> u1;
	ItemType i1,i2,i3;
	i1.set_value(1);i2.set_value(2);i3.set_value(5);
	u1.InsertItem(i1);
	u1.InsertItem(i2);
	u1.InsertItem(i3);
	cout << u1.LD().get_value() << endl;
	u1.DeleteItem(i3);
	cout << u1.LD().get_value() << endl;
}
