# include <iostream>
# include <string>
using namespace std;

//1. ��� X�� ��� Y�� ������ �̵� - A(X,Y)
//2. ��� X�� ��� Y�� �ڷ� �̵� - B(X,Y)
//3. ó�� ���·� ���� - A(Y,X)

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
	D_LinkedList(int sz) { //������ �Լ�
		this->size = sz;
		head = new Node;
		tail = new Node;
		head = NULL;
		tail = NULL;
		for (int count = 0; count < sz; count++) { //�ʱ�ȭ
			Node* newNode = new Node;
			newNode->elem = count+1;

			if (count == 0) { 
				head = newNode;
				tail = newNode;
			}
			else {
				newNode->prev = tail; //backó��
				tail->next = newNode; //nextó��
				tail = tail->next; //tail ������Ʈ
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
	Node* findX(int num) { //Xã��
		Node* X = new Node;

		Node* curNode = head;
		for (int count = 0; count < size; count++) {
			if (curNode->elem == num) {
				X = curNode;// Node X�� �Ҵ�
				break;
			}
			curNode = curNode->next;
		}
		return X;
	}

	Node* findY(int num) { //Yã��

		Node* Y = new Node;
		Node* curNode = head;

		for (int count = 0; count < size; count++) {
			if (curNode->elem == num) {
				Y = curNode;// Node Y�� �Ҵ�
				break;
			}
			curNode = curNode->next;
		}
		return Y;
	}
	void A(int xNum, int yNum) { //��� x�� ��� y�� ������ �̵�
		Node* X = findX(xNum);
		Node* Y = findY(yNum);

		if (X->next != Y) {
			Node* tempNode = new Node;
			tempNode = Y->prev; // Y�� ���� ��� temp�� ����

			if (X == head) { // �̵��� x�� head�� ��
				head = head->next;

				tempNode->next = X; // temp�� ���� ���� X
				X->prev = tempNode; // X�� ���� ���� temp

				X->next = Y; // X�� ���� ���� Y
				Y->prev = X; // Y�� ���� ���� X

			}
			else if (Y == head) {
				X->prev->next = X->next;
				X->next->prev = X->prev;

				head = X;

				X->next = Y; // X�� ���� ���� Y
				head->prev = X; // Y�� ���� ���� X
			}
			else {
	
				X->prev->next = X->next;
				X->next->prev = X->prev;

				tempNode->next = X; // temp�� ���� ���� X
				X->prev = tempNode; // X�� ���� ���� temp

				X->next = Y; // X�� ���� ���� Y
				Y->prev = X; // Y�� ���� ���� X
			}

		}
	}

	void B(int xNum, int yNum) { //��� x�� ��� y�� �ڷ� �̵�
		Node* X = findX(xNum);
		Node* Y = findY(yNum);
		if (Y->next != X) {
			//X �и�
			if (X == head) { // �̵��� x�� head�� ��
				head = head->next;
			}
			else {
				X->prev->next = X->next;
				X->next->prev = X->prev;
			}

			//�̵� -> X�� Y �ڿ�
			Node* tempNode = new Node;
			tempNode = Y->next; // Y�� ���� ��� temp�� ����

			tempNode->prev = X; // temp�� ���� ���� X
			X->next = tempNode; // X�� ���� ���� temp

			X->prev = Y; // X�� ���� ���� Y
			Y->next = X; // Y�� ���� ���� X
		}
	}
	void restore() { //�����·� ����(�� ������)

	}
};
int main() {
	//ù° �ٿ� ����� �� N�� ������ �� M�� �־�����. (2 �� N �� 500,000, 0 �� M �� 100,000)
	//���� M�� �ٿ��� ����̰� �Է��� ������ ���� ���� ���� �������� �־�����
	int size = 0;
	int count = 0;
	string command = "";

	cin >> size >> count;
	D_LinkedList D_LL(size);

	D_LL.print();
	D_LL.A(2,1);
	D_LL.print();

}