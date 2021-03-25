#include <iostream>
#include <string>
using namespace std;

class arrStack {
public:
	int* arr;
	int t;
	int capacity = 20; //수용할 크기
	int result = 0; //계산결과

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
			return arr[t];
		}
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			return arr[t--]; //스택의 top감소
		}
	}
	void push(int e) {
		if (size() == capacity) cout << "FULL\n";
		else {
			arr[++t] = e; //스택의 top을 증가시켜준 후 e를 스택에 삽입

		}
	}
};

int calculate(string s) {

	int size = s.size(); // 수식 길이
	char e;
	arrStack arrStk;
	int result; //결과의 일의 자리수만 담기

	for (int i = 0; i < size; i++) {

		e = s[i]; // 입력받은 수식을 하나씩 e에 대입

		if (isdigit(e)) {
			arrStk.push(e - '0');
		} //e가 숫자면 스택에 삽입

		else {
			int op2 = arrStk.pop();
			int op1 = arrStk.pop();
			//e가 연산자이면 op2,op1에 스택에 저장된 원소 대입 

			switch (e) { //계산 후 push
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
	// 입력받은 string s의 길이는 s.size()로
	// 입력받은 string s의 특정위치 문자는 s.at()또는 s[]로
	// char형 문자는 char'0'을 빼줌으로 int로 바꿀 수 있다.

	int count = 0; //수식의 수
	string s = ""; // 후위표기법 수식
	int size = 0; //수식 길이

	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> s;
		cout << calculate(s) << "\n";

	}
}