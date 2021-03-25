//1874번: 스택수열
#include <iostream>
#include <string>
using namespace std;

class arrStack {
public:
	int* arr;
	int capacity = 1000; //수용할 크기
	int t; //top

	arrStack() { // 생성자함수
		this->arr = new int[capacity]; //동적할당으로
		this->t = -1;
	}

	int size() { //스택의 사이즈
		return t + 1;
	}

	bool empty() { //스택이 비어있는지 확인
		if (t == -1) {
			return 1;
		}// t가 -1일 때 1반환
		else {
			return 0;
		}
	}

	int top() { // 스택의 top에 저장된 원소 반환
		if (empty()) { //스택이 비어있으면 -1 반환
			return -1;
		}
		else {
			return this->arr[t];
		}
	}

	void push(int e) {
		if (size() == capacity) cout << "FULL\n";
		else this->arr[++t] = e; //스택의 top을 증가시켜준 후 e를 스택에 삽입
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			return this->arr[t--]; //스택의 top감소
		}
	}
};

int main() {
	string s = ""; //연산자 저장
	bool success = true;
	int stkMax = 0; //스택의 최댓값
	int maxNum = 0; //입력값의 최댓값
	int num = 0; //입력값
	arrStack arrStk; //스택 저장
	cin >> stkMax;
	int *numArr = new int[stkMax]; //수열 저장

	for (int i = 0; i < stkMax; i++) { //입력한 수열 arr에 저장
		cin >> num;
		numArr[i] = num;
	}

	for (int j = 0; j < stkMax; j++) {

		if (j == 0 || numArr[j] > maxNum) { //s에 +추가
			for (int k = maxNum+1; k <= numArr[j]; k++) {
				arrStk.push(k);
				s += "+";
			}
			maxNum = numArr[j];
		}

		if (numArr[j] == arrStk.top()) { //-추가
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