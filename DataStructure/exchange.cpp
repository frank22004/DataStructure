#include "stdafx.h"
#include "iostream"

using namespace std;

//change the value of A and B
void exchange(int &A, int &B) {
	int temp;

	temp = A;
	A = B;
	B = temp;
}