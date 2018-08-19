#pragma once
/*
	Name¡G	Interchange A and B
	Author: Sizeblesnail
	Created Date: Aug 2018
	Note: Template should be implemented on the header file according to
		  https://blog.csdn.net/jtop0/article/details/5779782
*/

template<typename T>
class interchangeAandB
{
public:
	//construction of object
	interchangeAandB();

	//deconstruction of object
	~interchangeAandB();

protected:
	//change the value of A and B
	void exchangevalue(T* A, T* B);

private:
	//storage the value temporarily
	T temp;
};

template<typename T>
inline interchangeAandB<T>::interchangeAandB()
{
}

template<typename T>
inline interchangeAandB<T>::~interchangeAandB()
{
}

template<typename T>
inline void interchangeAandB<T>::exchangevalue(T* A, T* B)
{
	temp = *A;
	*A = *B;
	*B = temp;
}