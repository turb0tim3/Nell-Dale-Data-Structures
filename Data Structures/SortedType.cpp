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
class SortedType{
	private:
		NodeType<ItemType> *listData;
		int length = 0;
		NodeType<ItemType> *currentPos;
	public:
		SortedType(){
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
			NodeType<ItemType> *newNode;
			NodeType<ItemType> *predLoc;
			NodeType<ItemType> *location;
			bool moretosearch;

			location = listData;
			predLoc = NULL;
			moretosearch = (location != NULL );

			while(moretosearch){
				if(location->info.get_value() < item.get_value()){
					predLoc = location;
					location = location->next;
					moretosearch = (location != NULL );
				}else{
					moretosearch = false;
				}
			}
			newNode = new NodeType<ItemType>;
			newNode->info = item;
			if (predLoc == NULL){
				newNode->next =listData;
				listData = newNode;
			}
			else{
				newNode->next = location;
				predLoc->next =newNode;
			}
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
	SortedType<ItemType> s1;
	ItemType i1,i2,i3;
	i1.set_value(12);i2.set_value(11);i3.set_value(16);
	s1.InsertItem(i1);
	s1.InsertItem(i2);
	s1.InsertItem(i3);
	cout << s1.LD().get_value() << endl;
	s1.DeleteItem(i2);
	cout << s1.LD().get_value() << endl;
	s1.DeleteItem(i1);
	cout << s1.LD().get_value() << endl;
}