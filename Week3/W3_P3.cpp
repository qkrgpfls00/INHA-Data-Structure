# include <iostream>
#include <string>
using namespace std;

class Node { //node class
public:
	int data; //Node에 저장할 데이터
	Node* next; // 다음 노드를 가르키는 포인터 변수

	Node(int e) { //생성자 함수
		this->data = e;
		this->next = NULL;
	}
};

class linkedStack {
public:
	Node* head;
	Node* tail;
	int n; // stack의 사이즈

	linkedStack() { //생성자함수
		this->head = NULL;
		this->tail = NULL;
		this->n = 0;
	}
	int size() { return n; } //스택의 사이즈를 반환

	bool empty() { // 스택이 비어있으면 1, 비어있지 않으면 0 출력
		if (n == 0) { // 스택의 사이즈가 0이면
			return 1;
		}
		else {
			return 0;
		}
	}

	int top() { // 스택의 top에 저장된 정수 출력, 비어있으면 -1 출력
		if (empty()) {
			return -1;
		}
		else {
			return head->data;
		}
	}
	void push(int e) { //정수 e를 스택에 삽입
		Node* newNode = new Node(e); //e를 저장하고 있는 Node생성

		if (empty()) { //스택이 비어있는 경우 head, tail에 newNode저장
			head = newNode;
			tail = newNode;
			n++; //사이즈 1 증가
		}
		else {
			newNode->next = head; 
			head = newNode; //newNode를 head(top)으로
			n++; //사이즈 1 증가
		}
	}
	int pop() { //스택의 top에 저장된 정수 출력 후 삭제, 스택이 비어있으면 -1 출력
		if (empty()) {
			return -1;
		}
		else {
			Node* stkTop = head;
			head = head->next; //head(top) 업데이트
			n--; //사이즈 1 감소
			return stkTop->data;
		}
	}

};
int main() {
	int N = 0; // 명령어 수
	int X = 0; //push할 때 삽입할 정수
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
