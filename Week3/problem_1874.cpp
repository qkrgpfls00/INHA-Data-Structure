//1874��: ���ü���
#include <iostream>
#include <string>
using namespace std;

class arrStack {
public:
	int* arr;
	int capacity = 1000; //������ ũ��
	int t; //top

	arrStack() { // �������Լ�
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
			return -1;
		}
		else {
			return this->arr[t];
		}
	}

	void push(int e) {
		if (size() == capacity) cout << "FULL\n";
		else this->arr[++t] = e; //������ top�� ���������� �� e�� ���ÿ� ����
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			return this->arr[t--]; //������ top����
		}
	}
};

int main() {
	string s = ""; //������ ����
	bool success = true;
	int stkMax = 0; //������ �ִ�
	int maxNum = 0; //�Է°��� �ִ�
	int num = 0; //�Է°�
	arrStack arrStk; //���� ����
	cin >> stkMax;
	int *numArr = new int[stkMax]; //���� ����

	for (int i = 0; i < stkMax; i++) { //�Է��� ���� arr�� ����
		cin >> num;
		numArr[i] = num;
	}

	for (int j = 0; j < stkMax; j++) {

		if (j == 0 || numArr[j] > maxNum) { //s�� +�߰�
			for (int k = maxNum+1; k <= numArr[j]; k++) {
				arrStk.push(k);
				s += "+";
			}
			maxNum = numArr[j];
		}

		if (numArr[j] == arrStk.top()) { //-�߰�
			arrStk.pop();
			s += "-";
		}
		else {
			success = false;
			break;
		}
	}
	if (success == true) {
		for (int c = 0; c < s.size(); c++) {
			cout << s[c] << "\n";
		}
	}
	else { cout << "NO"; }
	delete[] numArr;
}