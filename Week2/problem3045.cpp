# include <iostream>
# include <string>
using namespace std;

//1. 노드 X를 노드 Y의 앞으로 이동 - A(X,Y)
//2. 노드 X를 노드 Y의 뒤로 이동 - B(X,Y)
//3. 처음 상태로 복구 - A(Y,X)

class Node { 
	int elem;
	Node* next = NULL;
	Node* prev = NULL;

	friend class D_LinkedList;
};

class D_LinkedList {
private:
	Node* head = NULL;
	Node* tail = NULL;
	int size = 0;
public:
	D_LinkedList(int sz) { //생성자 함수
		this->size = sz;
		head = new Node;
		tail = new Node;
		head = NULL;
		tail = NULL;
		for (int count = 0; count < sz; count++) { //초기화
			Node* newNode = new Node;
			newNode->elem = count+1;

			if (count == 0) { 
				head = newNode;
				tail = newNode;
			}
			else {
				newNode->prev = tail; //back처리
				tail->next = newNode; //next처리
				tail = tail->next; //tail 업데이트
			}
		}
	}
	void print() {
		Node* curNode = head;
		while(curNode!=NULL){
			cout << curNode->elem << ' ';
			curNode = curNode->next;
		}
		cout << "\n";
	}
	Node* findX(int num) { //X찾기
		Node* X = new Node;

		Node* curNode = head;
		for (int count = 0; count < size; count++) {
			if (curNode->elem == num) {
				X = curNode;// Node X에 할당
				break;
			}
			curNode = curNode->next;
		}
		return X;
	}

	Node* findY(int num) { //Y찾기

		Node* Y = new Node;
		Node* curNode = head;

		for (int count = 0; count < size; count++) {
			if (curNode->elem == num) {
				Y = curNode;// Node Y에 할당
				break;
			}
			curNode = curNode->next;
		}
		return Y;
	}
	void A(int xNum, int yNum) { //노드 x를 노드 y의 앞으로 이동
		Node* X = findX(xNum);
		Node* Y = findY(yNum);

		if (X->next != Y) {
			Node* tempNode = new Node;
			tempNode = Y->prev; // Y의 이전 노드 temp에 저장

			if (X == head) { // 이동할 x가 head일 때
				head = head->next;

				tempNode->next = X; // temp의 다음 노드는 X
				X->prev = tempNode; // X의 이전 노드는 temp

				X->next = Y; // X의 다음 노드는 Y
				Y->prev = X; // Y의 이전 노드는 X

			}
			else if (Y == head) {
				X->prev->next = X->next;
				X->next->prev = X->prev;

				head = X;

				X->next = Y; // X의 다음 노드는 Y
				head->prev = X; // Y의 이전 노드는 X
			}
			else {
	
				X->prev->next = X->next;
				X->next->prev = X->prev;

				tempNode->next = X; // temp의 다음 노드는 X
				X->prev = tempNode; // X의 이전 노드는 temp

				X->next = Y; // X의 다음 노드는 Y
				Y->prev = X; // Y의 이전 노드는 X
			}

		}
	}

	void B(int xNum, int yNum) { //노드 x를 노드 y의 뒤로 이동
		Node* X = findX(xNum);
		Node* Y = findY(yNum);
		if (Y->next != X) {
			//X 분리
			if (X == head) { // 이동할 x가 head일 때
				head = head->next;
			}
			else {
				X->prev->next = X->next;
				X->next->prev = X->prev;
			}

			//이동 -> X가 Y 뒤에
			Node* tempNode = new Node;
			tempNode = Y->next; // Y의 다음 노드 temp에 저장

			tempNode->prev = X; // temp의 이전 노드는 X
			X->next = tempNode; // X의 다음 노드는 temp

			X->prev = Y; // X의 이전 노드는 Y
			Y->next = X; // Y의 다음 노드는 X
		}
	}
	void restore() { //원상태로 복구(맨 마지막)

	}
};
int main() {
	//첫째 줄에 노드의 수 N과 연산의 수 M이 주어진다. (2 ≤ N ≤ 500,000, 0 ≤ M ≤ 100,000)
	//다음 M개 줄에는 상근이가 입력한 연산이 문제 설명에 나온 형식으로 주어진다
	int size = 0;
	int count = 0;
	string command = "";

	cin >> size >> count;
	D_LinkedList D_LL(size);

	D_LL.print();
	D_LL.A(2,1);
	D_LL.print();

}