#pragma once
#include <vector>
#include <list>

namespace A3 {

	template<typename Item_Type>
	class Queue
	{
	private:
		std::vector<Item_Type> data; //Implementing using circular vectors
		size_t num_items;
		size_t capacity;
		size_t f_index;
		size_t b_index;

	public:
		Queue<Item_Type>();
		~Queue<Item_Type>();
		void push(Item_Type item);
		void pop();
		Item_Type& front();
		const Item_Type& front() const;
		size_t size() const;
		bool empty() const;
		void move_to_rear();
		void reallocate();
	};

	template<typename Item_Type> int reverse_linear_search(std::vector<Item_Type>& items, Item_Type& target, size_t pos_first);
	void list_insertion_sort(std::list<int>& num);
}

/*----- Driver Functions -----*/
int main();

void q(); //Driver for Queue
void queue_example(); //Automatic runthrough of project requirements for queue.
void queue_play(); //
int function_select(); //Function selection for queue_play(). Returns int corresponding to a function. Just easier to read when separated.

void rls(); //Driver for reverse_linear_search demo
void lis(); //Driver for list_insertion_sort demo


void validate_input(); //Checks for user input failures, resets cin, throws exception