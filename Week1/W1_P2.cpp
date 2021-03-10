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
	void add(int index, int value) {
		for (int i = arrSize - 2; i >= index; i--) {
			arr[i + 1] = arr[i];
		}
		arr[index] = value;
	}
	void shift(int n) {
		for (int j = n; j > 0; j--) {
			int lastNum = arr[arrSize - 1]; //마지막 number
			for (int i = arrSize - 1; i >= 0; i--) {
				arr[i] = arr[i - 1];
			}
			arr[0] = lastNum;
		}
	}
	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	int count = 0; //test 수
	int a = 0; //입력받을 원소
	cin >> count;

	for (int i = 0; i < count; i++) {

		int size = 0;
		int shiftCount = 0;
		cin >> size >> shiftCount;
		for (int k = 0; k < size; k++) {

		}

		Array arr(size);
		for (int j = 0; j < size; j++) {
			cin >> a;
			arr.add(j, a);
		} //배열에 원소 대입

		arr.shift(shiftCount); //배열 이동
		arr.print();
	}
}
