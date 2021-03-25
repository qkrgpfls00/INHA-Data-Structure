#include <iostream>
#include <string>
using namespace std;

class Node {
	int elem;
	Node* next = NULL;
	Node* prev = NULL;

	friend class D_LinkedList;
};

class D_LinkedList {
private:
	Node* header;
	Node* tailer;
public:
	D_LinkedList() { //생성자함수
		header = new Node;
		tailer = new Node;
		header = NULL;
		tailer = NULL;
	}
	int List_size() { //리스트의 크기 반환 함수
		int sz = 0;
		if (this->Empty() == true) {
			return sz;
		}
		else {
			Node* curNode = this->header;
			while (curNode->next != NULL) {
				sz++;
				curNode = curNode->next;
			}
			sz++;
			return sz;
		}

	}
	bool Empty() { //리스트가 비어있는지 확인 함수
		return(header == NULL && tailer == NULL);
	}
	void Print() { //리스트 전체 출력 함수
		//리스트가 비어있을 때 empty출력

		if (this->Empty() == true) {
			cout << "empty\n";
		}
		else {
			Node* curNode = this->header;
			while (curNode->next != NULL) {
				cout << curNode->elem << " ";
				curNode = curNode->next;
			}
			cout << curNode->elem << '\n';
		}
	}
	void Append(int elem) { //리스트에 node를 추가 함수
		//맨 뒤에 삽입 후 Print함수 수행
		Node* newNode = new Node;
		newNode->elem = elem;
		newNode->next = NULL; //tail이 될 Node이기 때문

		if (this->Empty() == true) {
			this->header = newNode;
			this->tailer = newNode;
			this->Print();
		}
		else {
			(this->tailer)->next = newNode;
			newNode->prev = tailer;
			this->tailer = newNode;
			this->Print();
		}
	}
	int Delete(int idx) { //해당 idx를 삭제 함수
		//삭제하면서 반환, 반환된 값 출력

		//리스트가 비어있거나 index값이 사이즈와 같거나 크면 -1을 반환, 출력
		int midIndex = List_size() / 2;
		int deleteNum = 0;

		if (this->Empty() == true || List_size() <= idx) {
			deleteNum = -1;
		}
		else if (idx == 0) { //head를 삭제하는 경우
			if (List_size() == 1) {
				deleteNum = header->elem;
				this->header = NULL;
				this->tailer = NULL;
			}
			else {
				deleteNum = header->elem;
				this->header = this->header->next;
			}

		}
		else if(idx <midIndex) { //헤더에서 접근
			Node* preNode = this->header;
			Node* curNode = this->header->next;
			int cnt = 0;
			while (cnt != idx) {
				preNode = preNode->next;
				curNode = curNode->next;
				cnt++;
			}
			deleteNum = curNode->elem;
			preNode->next = curNode->next;
			(curNode->next)->prev = preNode;

		}
		else if (idx >= midIndex) {
			Node* curNode = this->tailer;
			Node* preNode = this->tailer->prev;
			int cnt = List_size() - 1;
			while (cnt != idx) {
				preNode = preNode->prev;
				curNode = curNode->prev;
				cnt--;
			}
			deleteNum = curNode->elem;
			preNode->next = curNode->next;
			if (curNode == tailer) {
				tailer = preNode;
			}
			else {
				(curNode->next)->prev = curNode->prev;
			}
		}
		return deleteNum;
	}
	void Print_reverse() { //리스트 역으로 출력 함수
		//리스트가 비어있을 때 empty출력

		if (this->Empty() == true) {
			cout << "empty\n";
		}
		else {
			Node* curNode = this->tailer;
			while (curNode->prev != NULL) {
				cout << curNode->elem << " ";
				curNode = curNode->prev;
			}
			cout << curNode->elem << '\n';
		}
	}
	void Max() {
		if (Empty()) {
			cout << "empty" << '\n';
		}
		else {
			Node* curNode = header;
			int max = header->elem;

			while (curNode != NULL) {
				if (max <= curNode->elem) {
					max = curNode->elem;
				}
				curNode = curNode->next;
			}
			cout << max << '\n';
		}
		
	}
};
int main() {
	D_LinkedList DLL;
	string command = "";
	int value;
	int index;

	int c_count = 0;
	cin >> c_count;
	for (int i = 0; i < c_count; i++) {
		cin >> command;
		if (command == "Print") {
			DLL.Print();
		}
		else if (command == "Append") {
			cin >> value;
			DLL.Append(value);
		}
		else if (command == "Delete") {
			cin >> index;
			cout << DLL.Delete(index) << endl;
		}
		else if (command == "Print_reverse"){
			DLL.Print_reverse();
		}
		else if (command == "Max") {
			DLL.Max();
		}
		else {
			cout << "wrong command!\n";
		}
	}
}
