#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(QueueTest)
	{
	public:
		
		TEST_METHOD(Enqueue_ValidData_Success)
		{
			Queue::Queue queue;
			queue.enqueue(5);
			Assert::AreEqual(queue.peek(), 5);
		}

		TEST_METHOD(Enqueue_ValidData_Fail)
		{
			Queue::Queue queue;
			queue.enqueue(5);
			Assert::AreNotEqual(queue.peek(), 3);
		}

		TEST_METHOD(Dequeue_ValidData_Success)
		{
			Queue::Queue queue{1,2,3,4,5};
			queue.dequeue();
			Assert::AreEqual(queue.peek(), 2);
		}

		TEST_METHOD(Dequeue_ValidData_Fail)
		{
			Queue::Queue queue{ 1,2,3,4,5 };
			queue.dequeue();
			Assert::AreNotEqual(queue.peek(), 3);
		}

		TEST_METHOD(СopyСonstructor_ValidData_Success)
		{
			Queue::Queue queue1{ 1,2,3 }, queue2(queue1);
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
		}

		TEST_METHOD(MoveConstructor_ValidData_Success)
		{
			Queue::Queue queue1{ 1,2,3 }, queue2 = queue1, queue3(std::move(queue2));
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
		}

		TEST_METHOD(OperatorEqualCoping_ValidData_Success)
		{
			Queue::Queue queue1{ 1,2,3 }, queue2=queue1;
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
		}

		TEST_METHOD(OperatorEqualMoving_ValidData_Success)
		{
			Queue::Queue queue1{ 1,2,3 }, queue2=queue1, queue3=std::move(queue2);
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
		}
		
	};
}
