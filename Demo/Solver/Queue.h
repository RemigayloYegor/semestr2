#pragma once
#include <iostream>
#include <initializer_list>
#include "Node.h"


namespace Queue
{

	class Queue
	{
	private:
		/**
		* @brief - Узел головы очереди.
		*/
		Node* head;
		/**
		* @brief - Узел хвоста очереди.
		*/
		Node* tail;
		/**
		* @brief - Размер очереди.
		*/
		size_t size;

	public:
		/**
	    * @brief - Конструктор класса очередь.
	    */
		Queue();
		/**
		* @brief - Деструктор класса очередь.
		*/
		~Queue();
		/**
		* @brief - Конструктор со списком инициализации.
		* @param list - Список
		*/
		Queue(std::initializer_list<int> list);
		/**
		* @brief - Функция,добавляющая элемент в конце очереди.
		* @param value - Значение нового элемента.
		*/
		void enqueue(const int value);
		/**
		* @brief - Функция,извлекающая элемент из начала очереди.
		*/
		void dequeue();
		/**
		* @brief - Функция,читающая головной элемент.
		* @return - Возвращает значение первого узла.
		*/
		int peek();
		/**
		* @brief - Оператор сдвига влево.
		*/
		friend std::ostream& operator << (std::ostream& output, const Queue& queue);
		/**
		* @brief - Конструктор копирования.
		* @param other - Другая очередь.
		*/
		Queue(const Queue& other);
		/**
		* @brief - Конструктор перемещения.
		* @param other - Другая очередь.
		*/
		Queue(Queue&& other) noexcept;
		/**
		* @brief - Оператор присваивания с помощью копирования.
		* @param other - Другая очередь.
		* @return - Возвращает очередь с другими параметрами.
		*/
		Queue& operator = (const Queue& other);
		/**
		* @brief - Оператор присваивания с помощью перемещения.
		* @param other - Другая очередь.
		* @return - Возвращает очередь с другими параметрами.
		*/
		Queue& operator = (Queue&& other) noexcept;
	};
}