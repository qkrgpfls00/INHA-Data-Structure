#include <iostream>
#include <string>
using namespace std;

class Node { //Node class
	int elem=0; // 데이터 저장 변수
	Node* next = NULL; // 다음 노드 주소 저장 포인터 

	friend class S_LinkedList;
};

class S_LinkedList {
private:
	Node* head=NULL;
	Node* tail=NULL;
public:
	S_LinkedList() { //생성자 함수
		head = new Node;
		tail = new Node;

		head = NULL;
		tail = NULL;
	}
	int List_size() { //리스트의 크기 반환 함수
		
		int sz = 0;
		if (this->Empty() == true) {
			return sz;
		}
		else {
			Node* curNode = this->head;
			while (curNode->next != NULL) {
				sz++;
				curNode = curNode->next;
			}
			sz++;
			return sz;
		}
	
	}
	bool Empty() { //리스트가 비어있는지 확인 함수
		return(head == NULL && tail == NULL);
	}
	void Print() { //리스트 전체 출력 함수
		//리스트가 비어있을 때 empty출력

		if (this->Empty() == true) {
			cout << "empty\n";
		}
		else {
			Node* curNode = this->head;
			while(curNode->next != NULL) {
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
			this->head = newNode;
			this->tail = newNode;
			this->Print();
		}
		else {
			(this->tail)->next= newNode;
			this->tail = newNode;
			this->Print();
		}
	}
	int Delete(int idx) { //해당 idx를 삭제 함수
		//삭제하면서 반환, 반환된 값 출력
		//리스트가 비어있거나 index값이 사이즈와 같거나 크면 -1을 반환, 출력
		
		int deleteNum = 0;

		if (this->Empty() == true || List_size() <= idx) {
			deleteNum = -1;
		}
		else if (idx == 0) { //head를 삭제하는 경우
			if (List_size() == 1) {
				deleteNum = head->elem;
				this->head = NULL;
				this->tail = NULL;
			}
			else {
				deleteNum = head->elem;
				this->head = this->head->next;
			}

		}
		else {
			Node* preNode = this->head;
			Node* curNode = this->head->next;
			int cnt = 0;
			while (cnt != idx) {
				preNode = preNode->next;
				curNode = curNode->next;
				cnt++;
			}
			deleteNum = curNode->elem;
			preNode->next = curNode->next;

			if (curNode == tail) {
				tail = preNode;
			}
		}
		return deleteNum;
		
	}
	void Insert(int idx, int elem) { //리스트 index에 elem을 갖는 노드 추가 함수
		//삽입 후 Print함수 수핼
		//index가 리스트 사이즈보다 크면 Index Error 출력

		Node* newNode = new Node;
		newNode->elem = elem;
	
		
		if (idx <0 || idx >List_size()) {
			cout << "Index Error"<<endl;
		}
		else if (idx == 0) { //head에 삽입하는 경우
			if (Empty() == true) {
				this->head = newNode;
				this->tail = newNode;
				this->Print();

			}
			else{
				newNode->next = head;
				head = newNode;
				this->Print();
			}
		}
		else if (idx == List_size()) {
			Append(elem);
		}
		else {
			Node* preNode = this->head;
			Node* curNode = this->head;
			int pre_idx = 0;

			while(pre_idx!=idx) {
				preNode = curNode;
				curNode = curNode->next;
				pre_idx++;
			}
			preNode->next = newNode;
			newNode->next = curNode;
			this->Print();
		}
	}
	void Sum() { //리스트 전체 노드의 elem값의 합 출력 함수
		int sum = 0;
		Node* curNode = this->head;
		if (this->Empty() == true) {
			cout << "0\n";
		}
		else {
			while (curNode->next != NULL) {
				sum += curNode->elem;
				curNode = curNode->next;
			}
			sum += curNode->elem;
			cout << sum<<'\n';
		}

	}
};
int main() {
	S_LinkedList SLL;
	string command = "";
	int value;
	int index;

	int c_count = 0;
	cin >> c_count;
	for (int i = 0; i < c_count; i++) {
		cin >> command;
		if (command == "Print") {
			SLL.Print();
		}
		else if (command == "Append") {
			cin >> value;
			SLL.Append(value);
		}
		else if (command == "Delete") {
			cin >> index;
			cout << SLL.Delete(index) << endl;
		}
		else if (command == "Insert") {
			cin >> index >> value;
			SLL.Insert(index, value);
		}
		else if (command == "Sum") {
			SLL.Sum();
		}
		else {
			cout << "wrong command!\n";
		}
	}
}