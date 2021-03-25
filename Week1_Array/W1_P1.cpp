#include <iostream>
#include <string>
using namespace std;

class Array {
private:
	int *arr;
	int arrSize;
public:
	Array(int size) {
		this->arrSize = size;
		this->arr = new int[arrSize];
		for (int i = 0; i < arrSize; i++) {
			arr[i] = 0;
		}
	}
	int at(int index) {
		cout << arr[index] << endl;
		return arr[index];
	}
	void add(int index, int value) {
		for (int i = arrSize - 2; i >= index; i--) {
			arr[i + 1] = arr[i];
		}
		arr[index] = value;
	}
	void remove(int index) {
		for (int i = index + 1; i < arrSize; i++) {
			arr[i - 1] = arr[i];
		}
		arr[arrSize - 1] = 0;
	}
	void set(int index, int value) {
		arr[index] = value;
		cout << value << endl;
	}
	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int find_max() {
		int max = 0;
		for (int i = 0; i < arrSize; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		cout << max << endl;
		return max;
	}
	void command(string funcName) {

		int index = 0;
		int value = 0;

		if (funcName == "at") {
			cin >> index;
			this->at(index);
		}
		else if (funcName == "add") {
			cin >> index;
			cin >> value;
			this->add(index, value);
		}
		else if (funcName == "remove") {
			cin >> index;
			this->remove(index);
		}
		else if (funcName == "set") {
			cin >> index;
			cin >> value;
			this->set(index, value);
		}
		else if (funcName == "print") {
			this->print();
		}
		else if (funcName == "find_max") {
			this->find_max();
		}
		else
			cout << "not exist" << std::endl;
	}
};

int main() {
	int arrSize = 0;
	int testCount = 0;
	string funcName = "";

	cin >> arrSize >> testCount;
	Array arr(arrSize);

	for (int i = 0; i < testCount; i++) {
		cin >> funcName;
		arr.command(funcName);
	}
}
