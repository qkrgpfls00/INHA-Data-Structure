#include <iostream>
#include <string>
using namespace std;

class arrStack {
public:
	int* arr;
	int capacity; //������ ũ��
	int t; //top

	arrStack(int capacity) { // �������Լ�
		this->capacity = capacity;
		this->arr = new int[capacity]; //�����Ҵ�����
		this->t = -1;
	}

	int size() { //������ ������
		return t + 1;
	}

	bool empty() { //������ ����ִ��� Ȯ��
		if (t == -1) { 
			return 1;
		}// t�� -1�� �� 1��ȯ
		else {
			return 0;
		}
	}

	int top() { // ������ top�� ����� ���� ��ȯ
		if (empty()) { //������ ��������� -1 ��ȯ
			cout << -1<<"\n";
			return -1; 
		}
		else {
			cout << arr[t]<<"\n";
			return arr[t];
		}
	}

	void push(int e) {
		if (size() == capacity) cout << "FULL\n";
		else arr[++t] = e; //������ top�� ���������� �� e�� ���ÿ� ����
	}

	int pop() {
		if (empty()) {
			cout << "-1\n";
			return -1;
		}
		else {
			top(); //top�� ����� ���� ��� ��
			return arr[t--]; //������ top����
		}
	}
};
int main() {
	int t=0; // ������ ���� ������ ũ�� ��
	int N=0; // ��ɾ� ��
	int X = 0; //push�� �� ������ ����
	string command = "";
	
	cin >> t >> N;
	arrStack arrStk(t);

	for (int count = 0; count < N; count++) {
		cin >> command;
		if (command == "empty") { cout << arrStk.empty()<<"\n"; }
		else if (command == "top") { arrStk.top(); }
		else if (command == "push") {
			cin >> X;
			arrStk.push(X);
		}
		else if (command == "pop") { arrStk.pop(); }
	}
}