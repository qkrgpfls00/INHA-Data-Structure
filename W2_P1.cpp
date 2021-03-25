#include <iostream>
#include <string>
using namespace std;

class Node { //Node class
	int elem=0; // ������ ���� ����
	Node* next = NULL; // ���� ��� �ּ� ���� ������ 

	friend class S_LinkedList;
};

class S_LinkedList {
private:
	Node* head=NULL;
	Node* tail=NULL;
public:
	S_LinkedList() { //������ �Լ�
		head = new Node;
		tail = new Node;

		head = NULL;
		tail = NULL;
	}
	int List_size() { //����Ʈ�� ũ�� ��ȯ �Լ�
		
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
	bool Empty() { //����Ʈ�� ����ִ��� Ȯ�� �Լ�
		return(head == NULL && tail == NULL);
	}
	void Print() { //����Ʈ ��ü ��� �Լ�
		//����Ʈ�� ������� �� empty���

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
	void Append(int elem) { //����Ʈ�� node�� �߰� �Լ�
		//�� �ڿ� ���� �� Print�Լ� ����
		Node* newNode = new Node;
		newNode->elem = elem;
		newNode->next = NULL; //tail�� �� Node�̱� ����

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
	int Delete(int idx) { //�ش� idx�� ���� �Լ�
		//�����ϸ鼭 ��ȯ, ��ȯ�� �� ���
		//����Ʈ�� ����ְų� index���� ������� ���ų� ũ�� -1�� ��ȯ, ���
		
		int deleteNum = 0;

		if (this->Empty() == true || List_size() <= idx) {
			deleteNum = -1;
		}
		else if (idx == 0) { //head�� �����ϴ� ���
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
	void Insert(int idx, int elem) { //����Ʈ index�� elem�� ���� ��� �߰� �Լ�
		//���� �� Print�Լ� ����
		//index�� ����Ʈ ������� ũ�� Index Error ���

		Node* newNode = new Node;
		newNode->elem = elem;
	
		
		if (idx <0 || idx >List_size()) {
			cout << "Index Error"<<endl;
		}
		else if (idx == 0) { //head�� �����ϴ� ���
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
	void Sum() { //����Ʈ ��ü ����� elem���� �� ��� �Լ�
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