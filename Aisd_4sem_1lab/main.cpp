#pragma once
#include "MyMap.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	MyMap<int, int> TestMap;
	TestMap.insert(33, 10);
	TestMap.insert(13, 20);
	TestMap.insert(53, 30);
	TestMap.insert(11, 40);
	TestMap.insert(21, 50);
	TestMap.insert(41, 60);
	TestMap.insert(61, 70);
	TestMap.print();
	TestMap.insert(15, 80);
	TestMap.insert(31, 90);
	TestMap.print();
	TestMap.remove(15);
	TestMap.print();
	cout << "Значение элемента с ключем 41: " << TestMap.findForValue(41) << endl;
	
	return 0;
}