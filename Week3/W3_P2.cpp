#include <iostream>
#include <string>
using namespace std;

class arrStack {
public:
	int* arr;
	int t;
	int capacity = 20; //������ ũ��
	int result = 0; //�����

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
			return arr[t];
		}
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			return arr[t--]; //������ top����
		}
	}
	void push(int e) {
		if (size() == capacity) cout << "FULL\n";
		else {
			arr[++t] = e; //������ top�� ���������� �� e�� ���ÿ� ����

		}
	}
};

int calculate(string s) {

	int size = s.size(); // ���� ����
	char e;
	arrStack arrStk;
	int result; //����� ���� �ڸ����� ���

	for (int i = 0; i < size; i++) {

		e = s[i]; // �Է¹��� ������ �ϳ��� e�� ����

		if (isdigit(e)) {
			arrStk.push(e - '0');
		} //e�� ���ڸ� ���ÿ� ����

		else {
			int op2 = arrStk.pop();
			int op1 = arrStk.pop();
			//e�� �������̸� op2,op1�� ���ÿ� ����� ���� ���� 

			switch (e) { //��� �� push
			case'*':
				arrStk.push(op1 * op2);
				break;
			case'+':
				arrStk.push(op1 + op2);
				break;
			case'-':
				arrStk.push(op1 - op2);
				break;
			}
		}
	}
	result= arrStk.top();
	result = result % 10;
	return result;

}
int main() {
	// �Է¹��� string s�� ���̴� s.size()��
	// �Է¹��� string s�� Ư����ġ ���ڴ� s.at()�Ǵ� s[]��
	// char�� ���ڴ� char'0'�� �������� int�� �ٲ� �� �ִ�.

	int count = 0; //������ ��
	string s = ""; // ����ǥ��� ����
	int size = 0; //���� ����

	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> s;
		cout << calculate(s) << "\n";

	}
}