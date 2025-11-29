#include <iostream>
#include <vector>
#include <array>

using Vector = std::vector<int>;
using Array = std::array<int, 10>;
using namespace std;
/*
// Пункт 1
void null() {
	cout << "Finish" << endl;
}
void first(const Vector& vec) {
	cout << "[ ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << " ]" << endl;
}

void second(Vector& vec) {
	int x;
	cout << "Добавьте элемент в начало" << endl;
	cin >> x;
	vec.reserve(vec.size() + 1)
	vec.insert(vec.begin(), x);
}

void third(Vector& vec) {
	int x;
	cout << "Добавьте элемент в конец" << endl;
	cin >> x;
	vec.reserve(vec.size() + 1)
	vec.push_back(x);
}
void fourth(Vector& vec) {
	vec.clear();
}
void fifth(Vector& vec) {
	int x;
	cout << "Введите индекс элемента массива: ";
	cin >> x;
	if ( x >= 0 && x < vec.size()) {
		cout << "[ " << vec[x] << " ]" << endl;
	}
	else {
		cout << "Такого элемента не существует" << endl;
	}
}
void sixth(Vector& vec) {
	first(vec);
	Vector temp;
	for (int i = vec.size() - 1; i >= 0; i--) {

		if (vec[i] == 777 || vec[i] % 7 != 0 ) {
			temp.push_back(vec[i]);
		}
	}
	if (temp.empty())  {
		temp.push_back(0);
		temp.push_back(0);
		temp.push_back(0);
	}
	vec = temp;
	first(vec);
}
*/
// Пункт 2

// По значению: cоздается копия массивв, оригинал не изменяется 
void sort1(Array arr) {
	int n = 10;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j]) {
				std::swap(arr[i], arr[j]);
			}
}
// По ссылке: работает  оригиналом, изменения сохраняются
void sort2(Array& arr) {
	int n = 10;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
}
// По указателю: работает через адрес, изменения сохраняются
void sort3(Array* arr) {
	int n = 10;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if ((*arr)[i] > (*arr)[j]) {
				swap((*arr)[i], (*arr)[j]);
			}
}
int main() {
	setlocale(LC_ALL, "rus");
	/*
	int num;
	Vector vec;

	do {
		cout << "Меню" << endl;
		cout << "0 - Выход" << endl;
		cout << "1 - Просмотр вектора" << endl;
		cout << "2 - Добавление элемента в начало" << endl;
		cout << "3 - Добавление элемента в конец" << endl;
		cout << "4 - Очистка всего массива" << endl;
		cout << "5 - Поиск элемента в массиве" << endl;
		cout << "6 - Массив в обратном порядке" << endl;
		cout << "Число: " << endl;
		cin >> num;

		switch (num) {
		case 0: break;
		case 1: first(vec);break;
		case 2: second(vec); break;
		case 3: third(vec); break;
		case 4: fourth(vec); break;
		case 5: fifth(vec); break;
		case 6: sixth(vec); break;
		}

	} while (num != 0);

	null();
	*/
	Array arr;
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = rand() % 21 - 10;
	}
	cout << "Массив: " << "[ ";
	for (int i = 0; i < 10; i++) {
		cout  << arr[i] << " ";
	}
	cout <<" ]" << endl;

	sort1(arr);
	cout << "По значению: [ ";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout <<"]" << endl;

	sort2(arr);
	cout << "ССылке: [ ";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;

	sort3(&arr);
	cout << "Указателю: [ ";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
/* Пункт 3
1)В первом пунктке изпользовала std::vector потому что это динамический массив и он может увеличиваться или уменьшаться, 
std::array это статичесикий массив, поэтому использовать его нельзя
2)std::vector и std::array выполняют одинаковую роль, когда массив статичен и не будет меняться
*/
	return 0;
}
