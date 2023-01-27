#pragma once
#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
	char data;
	Node *next;
	Node(char data = 0, Node *next = NULL)
	{
		this->data = data;
		this->next = next;
	}
};

class stack
{
public:
	Node * head;
	stack() { head = NULL; }

	bool isempty()
	{
		if (head == NULL) return true;
		else return false;
	}

	void push(char data)
	{
		if (isempty()) head = new Node(data, NULL);
		else head = new Node(data, head);
	}

	void pop()
	{
		if (isempty()) cout << "Stack Underflow";
		else
		{
			Node* temp = head;
			head = temp->next;
			delete temp;
		}
	}
	char GetHeadData()
	{
		return this->head->data;
	}
};