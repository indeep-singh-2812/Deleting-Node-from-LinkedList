// This programm illustrates the source code to delete the node at nth position provided by user.

#include <iostream>
#include <string>

using namespace std;

//creating node structure of linked list.
struct Node{
	int data;
	Node* next;
};

class linkedList{
	Node* head;
	public:
		linkedList(){
			head = NULL;
		}
		void Insert(int); // Insert node at the beginning.
		void DeleteAtNthPosition(int); // Delete node at position passed as argument. 
		void Print(); // 
		
};

void linkedList::Insert(int value){
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

void linkedList::Print(){
	Node* counter = head;
	cout<<"List is :";
	while(counter !=NULL){
		cout<<" "<<counter->data;
		counter = counter->next;
	}
	cout<<"\n";
}

void linkedList::DeleteAtNthPosition(int position){ //method to delete the node at the position passed by user.
	Node* counterNode = head;
	
	if(head == NULL){
		cout<<"\n List is empty. Please insert values and provide relevant position to delete.";
		return;
	} else {
		if(position == 1){ // node to be deleted is present in the 1st position.
			head = counterNode->next;
			delete(counterNode);
		} else{
			for(int i =0;i<position-2;i++){ // position passed by user is invalid as the number fo nodes present in list is less than the position.
				if(counterNode == NULL || counterNode->next == NULL){
				cout<<"\n Invalid Position";
				return;
				}
				counterNode = counterNode->next;
			}
			
			// changing the pointers of the node.
			Node* nodeToDelete = counterNode->next;
			counterNode->next = nodeToDelete->next;
			delete(nodeToDelete); // freeing up the memory of deleted node.
		}
	}	
}

int main()
{
	linkedList l1;
	
	// Inserting nodes in a list.
	l1.Insert(1);
	l1.Insert(2);
	l1.Insert(3);
	l1.Insert(5);
	l1.Insert(6);
	l1.Print();
	
	
	l1.DeleteAtNthPosition(1); // deleting the node at 1st position
	cout<<"\n After deleting the 1st node.";
	l1.Print();
	l1.DeleteAtNthPosition(3); // deleting the node at 3rd position
	cout<<"\n After deleting the node at 3rd position.";
	l1.Print();
	l1.DeleteAtNthPosition(50); // deleting the node at invalid position.
}
