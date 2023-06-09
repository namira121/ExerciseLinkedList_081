#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { //write your answer here
	/*memasukkan node di awal*/
	int no;
	cout << "\nMasukkan nomor: ";
	cin >> no;//Assign value to the data field of the new node.
	Node* newnode = new Node();
	newnode->rollNumber = no;//Allocate memory for the new node

	if (LAST == NULL || no <= LAST->rollNumber) {
		newnode->next = LAST->next; //Make the next field of the new node point to the successor of LAST.
		LAST->next = newnode;//Make the next field of LAST point to the new node
	}

	/*memasukkan node di tengah list*/
	Node* namira = LAST->next;//Make current point to the first node.
	Node* pramadhani = NULL;//Make previous point to NULL.
	while (LAST != pramadhani || newnode > namira) { //Repeat steps 4 and 5 until current.info > newnode.info or previous = LAST.
		pramadhani = namira;//Make previous point to current.
		namira = namira->next;//Make current point to the next node in sequence.
	}

	/*memasukkan node di akhir*/
	if (LAST != NULL || no >= LAST->rollNumber) {
		newnode->next = LAST->next;//Make the next field of the new node point to the successor of LAST
		LAST->next = newnode;//Make the next field of LAST point to the new node
		LAST = newnode;//Mark LAST point to the new node
	}
}
bool CircularLinkedList::search(int rollno, Node** namira, Node** pramadhani) {
	*namira = LAST->next;
	*pramadhani = LAST->next;
	while (*pramadhani != LAST) {
		if (rollno == (*pramadhani)->rollNumber) {
			return true;
		}
		*namira = *pramadhani;
		*pramadhani = (*pramadhani)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //write your answer here
	/*menghapus node di bagian awal list*/
	Node* pramadhani, * namira;
	if (LAST = namira) {//If the node to be deleted is the only node in the list:// If LAST points toitself
		LAST == NULL;//Mark LAST as NULL
		return false;
	}
	else {
		LAST->next = namira;//Make current point to the successor of LAST.
		LAST->next = namira->next;//Make the next field of LAST point to the successor of current.
	}
	/*menghapus node di akhir list*/
	pramadhani = LAST->next; //Make previous point to the successor of LAST.
	namira = LAST->next;//Make current point to the successor of LAST.
	while (LAST != pramadhani) { //Repeat steps 4 and 5 until either the node is found, or previous = LAST
		pramadhani = namira;//Make previous point to current.
		namira = namira->next;//Make current point to the next node in sequence.
	}
	/*menghapus node di tengah list*/
	namira = LAST;//Make current point to LAST.
	pramadhani = LAST->next;//a) Make previous point to the successor of LAST
	while (LAST != pramadhani->next) {//Repeat step c until the successor of previous becomes LAST
		pramadhani = pramadhani->next;//Make the previous point to the next node in its sequence.
	}
	pramadhani->next = LAST->next;//Make the next field of previous point to the successor of LAST.
	pramadhani = LAST;//Mark previous as LAST.
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}