#include <iostream>
#include "Queue.h"

Queue::Queue::Queue() :head{ nullptr }, tail{ nullptr }, size{ 0 } {}

Queue::Queue::~Queue()
{
	while (head != nullptr)
	{
		Node* temporary = head;
		head = head->next;
		delete temporary;
	}
}

Queue::Queue::Queue(std::initializer_list<int> list)
{
	for (int value : list)
	{
		enqueue(value);
	}
}

void Queue::Queue::enqueue(const int value)
{
	Node* lastNode = new Node(value);
	if (size == 0)
	{
		head = tail = lastNode;
	}
	else
	{
		tail->next = lastNode;
		lastNode->previous = tail;
		tail = lastNode;
	}
	++size;
}

void Queue::Queue::dequeue()
{
	if (size == 0)
	{
		throw std::out_of_range("");
	}
	if (tail == head)
	{
		tail = head = nullptr;
	}
	else
	{
		head = head->next;
		head->previous = nullptr;
	}
	--size;
}

int Queue::Queue::peek()
{
	
	if (size == 0)
	{
		throw std::out_of_range("");
	}
	return head->data;
}

std::ostream& Queue::operator<<(std::ostream& output, const Queue& queue)
{
	Queue temporary = queue;
	while (!(temporary.size == 0))
	{
		output << temporary.peek() << " ";
		temporary.dequeue();
	}
	return output;
}

Queue::Queue::Queue(const Queue& other)
{
	Node* temporary = other.head;
	while (temporary != nullptr)
	{
		enqueue(temporary->data);
		temporary = temporary->next;
	}
}

Queue::Queue::Queue(Queue&& other) noexcept
{
	head = other.head;
	tail = other.tail;
	size = other.size;
	other.head = other.tail = nullptr;
	other.size = 0;
}

Queue::Queue& Queue::Queue::operator=(const Queue& other)
{
	Queue temporary(other);
	std::swap(this->head, temporary.head);
	std::swap(this->tail, temporary.tail);
	std::swap(this->size, temporary.size);
	return *this;
}

Queue::Queue& Queue::Queue::operator=(Queue&& other) noexcept
{
	if (this != &other)
		{
			std::swap(other.head, this->head);
			std::swap(other.tail, this->tail);
			std::exchange(other.size, this->size);
	    } 
	return *this;
}