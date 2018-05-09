/*
* =========================================================================================
* Name        : listLib.h
* Author      : Duc Dung Nguyen
* Email       : nddung@hcmut.edu.vn
* Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
* Description : library for Assignment 1 - Data structures and Algorithms - Spring 2018
* =========================================================================================
*/

#ifndef A01_LISTLIB_H
#define A01_LISTLIB_H

#include <string>
using namespace std;

class DSAException
{
	int _error;
	string _text;

public:
	DSAException() : _error(0), _text("Success") {}
	DSAException(int err) : _error(err), _text("Unknown Error") {}
	DSAException(int err, const char *text) : _error(err), _text(text) {}

	int getError() { return _error; }
	string &getErrorText() { return _text; }
};

template <class T>
struct L1Item
{
	T data;
	L1Item<T> *pNext;
	L1Item() : pNext(NULL) {}
	L1Item(L1Item<T> *p) : pNext(p) {}
	L1Item(T &a) : data(a), pNext(NULL) {}
	L1Item(T &&a) : data(std::move(a)), pNext(NULL) {}
};

template <class T>
class L1List
{
	L1Item<T> *_pHead; // The head pointer of linked list
	size_t _size;      // number of elements in this list
public:
	L1List() : _pHead(NULL), _size(0) {}
	/*~L1List() {
		_size = 0;
		L1Item<T> * temp = _pHead;
		while (temp != NULL) {
			delete _pHead;
			_pHead = temp->pNext;
		}
	};*/
	
	void clean();
	bool isEmpty()
	{
		return _pHead == NULL;
	}
	size_t getSize()
	{
		return _size;
	}

	T &at(int i) {
		L1Item<T> * temp = _pHead;
		for (int j = 0; j < i; j++) {
			temp = temp->pNext;
		}
		return temp->data;
	};

	T &operator[](int i) {
		L1Item<T> * temp = _pHead;
		for (int j = 0; j < i; j++) {
			temp = temp->pNext;
		}
		return temp->data;
	};

	bool find(T &a, int &idx);
	int insert(int i, T &a);
	int remove(int i);

	int push_back(T &a);
	int insertHead(T &a);
	int insertHead()
	{
		_pHead = new L1Item<T>(_pHead);
		_size++;
		return 0;
	}

	int removeHead();
	int removeLast();

	void reverse();

	void traverse(void(*op)(T &))
	{
		L1Item<T> *p = _pHead;
		while (p)
		{
			op(p->data);
			p = p->pNext;
		}
	}
	void traverse(void(*op)(T &, void *), void *pParam)
	{
		L1Item<T> *p = _pHead;
		while (p)
		{
			op(p->data, pParam);
			p = p->pNext;
		}
	}
};

/// Insert item to the end of the list
/// Return 0 if success
template <class T>
int L1List<T>::push_back(T &a)
{
	if (_pHead == NULL)
	{
		_pHead = new L1Item<T>(a);
	}
	else
	{
		L1Item<T> *p = _pHead;
		while (p->pNext)
			p = p->pNext;
		p->pNext = new L1Item<T>(a);
	}

	_size++;
	return 0;
}

/// Insert item to the front of the list
/// Return 0 if success
template <class T>
int L1List<T>::insertHead(T &a)
{
	L1Item<T> *p = new L1Item<T>(a);
	p->pNext = _pHead;
	_pHead = p;
	_size++;
	return 0;
}

/// Remove the first item of the list
/// Return 0 if success
template <class T>
int L1List<T>::removeHead()
{
	if (_pHead)
	{
		L1Item<T> *p = _pHead;
		_pHead = p->pNext;
		delete p;
		_size--;
		return 0;
	}
	return -1;
}

/// Remove the last item of the list
/// Return 0 if success
template <class T>
int L1List<T>::removeLast()
{
	if (_pHead)
	{
		if (_pHead->pNext)
		{
			L1Item<T> *prev = _pHead;
			L1Item<T> *pcur = prev->pNext;
			while (pcur->pNext)
			{
				prev = pcur;
				pcur = pcur->pNext;
			}
			delete pcur;
			prev->pNext = NULL;
		}
		else
		{
			delete _pHead;
			_pHead = NULL;
		}
		_size--;
		return 0;
	}
	return -1;
}
/// insert
template <class T>
int L1List<T>::insert(int i, T &a)
{
	if (_pHead)
	{
		L1Item<T> *pcur = _pHead;
		for (int j = 0; j < i; j++)
		{
			pcur = pcur->pNext;
		}
		L1Item<T> *p = new L1Item<T>(a);
		p->pNext = pcur->pNext;
		pcur->pNext = p;
		_size++;
		return 0;
	}
	return -1;
}

template<class T>
int L1List<T>::remove(int i) {
	if (_pHead) {
		L1Item<T> *pcur = _pHead;
		L1Item<T> *prev = _pHead;
		for (int j = 0; j < i; j++)
		{
			prev = pcur;
			pcur = pcur->pNext;
		}
		prev->pNext = pcur->pNext;
		delete pcur;
		return 0;
	}
	return -1;
}

template<class T>
bool L1List<T>::find(T &a, int &idx) {
	L1Item<T>* temp = _pHead;
	for (int i = 0; i < _size; i++) {
		if (idx == i) {
			if (temp->data == a) {
				return 0;
			}
			else return -1;
		}
		else if(i<_size){
			temp = temp->pNext;
		}
		else return -1;
	}
}
/////
template<class T>
void L1List<T>::reverse() {
	L1Item<T> *prev = NULL;
	L1Item<T> *cur = _pHead;
	L1Item<T> *next = NULL;
	while (cur != NULL) {
		next = cur->pNext;
		cur->pNext = prev;
		prev = cur;
		cur = next;
	}
	_pHead = prev;
}
#endif //A01_LISTLIB_H

