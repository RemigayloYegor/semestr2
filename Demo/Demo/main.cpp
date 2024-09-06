#include <iostream>
#include "..\Solver\Queue.h"

int main()
{
	Queue::Queue list = { 1, 2, 3, 4, 5};
	std::cout << list << std::endl;
	list.enqueue(6);
	std::cout << list << std::endl;
	list.dequeue();
	std::cout << list << std::endl;
	std::cout << list.peek() << std::endl;
	Queue::Queue list1 = { 1, 2, 3, 4, 5 };
	Queue::Queue list2 = { 1, 2, 3, 4, 5 };
	Queue::Queue queue1(std::move(list1));
	Queue::Queue queue2 = std::move(list2);
	std::cout << queue1 << std::endl << queue2 << std::endl;
	std::cout << list1 << std::endl << list2 << std::endl;
	return 0;
}
