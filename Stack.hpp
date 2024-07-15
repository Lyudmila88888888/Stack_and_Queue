#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>
#include <exception>


template <typename ANY>
class Stack {
private:
	ANY* first;
	ANY* last;
	size_t size; // максимальный размкер
	size_t elements; //проверка количества элементов на данный момент
public:
	Stack(size_t size); //параметрический
	~Stack();
	void put(ANY value); //put метод позволяет добасить элемент
	ANY get();
	ANY look();// метод
	void clear();// метод удаляет все элементы из очереди
	bool isFull(); //метод проверить не пустой ли стек
	bool isEmpty(); //метод логического значения пишется так is...
	void upgrade(); //метоод увеличение стэка если нужно
};

template <typename ANY>  // описание методов
Stack<ANY>::Stack(size_t size) {
	if (size == 0)
		throw std::exception("null size error"); //вызов ошибки
	first = new ANY[size] {};
	last = nullptr; //последний элемент, на данном этапе не понятно какой по счету
	this->size = size; 
	elements = 0;
}

template <typename ANY>
Stack<ANY>::~Stack() { 
	delete[] first;
}

template <typename ANY>
void Stack<ANY>::put(ANY value) { //метод для добавления элементов в стэк
	if(isFull())
		throw std::exception("stack overflow"); // перед добавлением элемента, если стэк полный то вызываем ошибку
	
	last = &(first[elements++] = value);//вариант сложнее
	
	//first[elements++] = value;
	//last = &first[elements - 1] // направление на последний элемент простой вариант	
}

template <typename ANY>
ANY Stack<ANY>::get() { //дает значение последнего элемента в стеке и удаляет
	if (isEmpty())
		throw std::exception("stack isEmpty");

	--elements;
	return *(last--);
}

template <typename ANY>
ANY Stack<ANY>::look() { //дает значение последнего элемента в стеке
	if (isEmpty())
		throw std::exception("stack isEmpty");
	return *last;
}

template <typename ANY>
bool Stack<ANY>::isEmpty() {
	return elements == 0;
}

template <typename ANY>
bool Stack<ANY>::isFull() {
	return elements == size;
}

template <typename ANY>
void Stack<ANY>::clear() { // очещение элементов в стеке
	elements = 0;
}

#endif //_STACK_HPP_