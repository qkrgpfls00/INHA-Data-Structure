#include <iostream>
#include <string>
using namespace std;

class arrStack {
public:
	int* arr;
	int capacity; //수용할 크기
	int t; //top

	arrStack(int capacity) { // 생성자함수
		this->capacity = capacity;
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
		else arr[++t] = e; //스택의 top을 증가시켜준 후 e를 스택에 삽입
	}

	int pop() {
		if (empty()) {
			cout << "-1\n";
			return -1;
		}
		else {
			top(); //top에 저장된 원소 출력 후
			return arr[t--]; //스택의 top감소
		}
	}
};
int main() {
	int t=0; // 스택의 수용 가능한 크기 수
	int N=0; // 명령어 수
	int X = 0; //push할 때 삽입할 정수
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