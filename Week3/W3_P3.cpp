# include <iostream>
#include <string>
using namespace std;

class Node { //node class
public:
	int data; //Node�� ������ ������
	Node* next; // ���� ��带 ����Ű�� ������ ����

	Node(int e) { //������ �Լ�
		this->data = e;
		this->next = NULL;
	}
};

class linkedStack {
public:
	Node* head;
	Node* tail;
	int n; // stack�� ������

	linkedStack() { //�������Լ�
		this->head = NULL;
		this->tail = NULL;
		this->n = 0;
	}
	int size() { return n; } //������ ����� ��ȯ

	bool empty() { // ������ ��������� 1, ������� ������ 0 ���
		if (n == 0) { // ������ ����� 0�̸�
			return 1;
		}
		else {
			return 0;
		}
	}

	int top() { // ������ top�� ����� ���� ���, ��������� -1 ���
		if (empty()) {
			return -1;
		}
		else {
			return head->data;
		}
	}
	void push(int e) { //���� e�� ���ÿ� ����
		Node* newNode = new Node(e); //e�� �����ϰ� �ִ� Node����

		if (empty()) { //������ ����ִ� ��� head, tail�� newNode����
			head = newNode;
			tail = newNode;
			n++; //������ 1 ����
		}
		else {
			newNode->next = head; 
			head = newNode; //newNode�� head(top)����
			n++; //������ 1 ����
		}
	}
	int pop() { //������ top�� ����� ���� ��� �� ����, ������ ��������� -1 ���
		if (empty()) {
			return -1;
		}
		else {
			Node* stkTop = head;
			head = head->next; //head(top) ������Ʈ
			n--; //������ 1 ����
			return stkTop->data;
		}
	}

};
int main() {
	int N = 0; // ��ɾ� ��
	int X = 0; //push�� �� ������ ����
	string command = "";

	cin >>  N;
	linkedStack lkdStk;

	for (int count = 0; count < N; count++) {
		cin >> command;
		if (command == "empty") { cout << lkdStk.empty()<<"\n"; }
		else if (command == "top") { cout << lkdStk.top()<<"\n"; }
		else if (command == "push") {
			cin >> X;
			lkdStk.push(X);
		}
		else if (command == "pop") { cout << lkdStk.pop()<<"\n"; }
	}
}
