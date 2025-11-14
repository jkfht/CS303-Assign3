#include "Header.h"
#include <string>
#include <iostream>

namespace A3 {
	/*----- Queue Implementation -----*/
	template<typename Item_Type> Queue<Item_Type>::Queue<Item_Type>() {
		data = std::vector<Item_Type>(10); //Starting with default capacity of 10.
		num_items = 0;
		capacity = 10;
		f_index = 0;
		b_index = 0;
	};
	template<typename Item_Type> Queue<Item_Type>::~Queue<Item_Type>() {
	};

	//Retrieval functions
	template<typename Item_Type> Item_Type& Queue<Item_Type>::front() {
		if (empty()) {  //Throw error for empty queue.
			throw std::invalid_argument("Queue is empty.");
		}
		return data[f_index];
	};
	template<typename Item_Type> const Item_Type& Queue<Item_Type>::front() const {
		if (empty()) { //Throw error for empty queue.
			throw std::invalid_argument("Queue is empty.");
		}
		return data[f_index];
	};
	template<typename Item_Type> size_t Queue<Item_Type>::size() const {
		return num_items;
	};
	template<typename Item_Type> bool Queue<Item_Type>::empty() const {
		return num_items == 0;
	};
	
	//Queue manipulation functions
	template<typename Item_Type> void Queue<Item_Type>::push(Item_Type item) {
		if (num_items == capacity) {  //Reallocate if at capacity
			reallocate();
		}
		data[b_index] = item;
		b_index = (b_index + 1) % capacity;
		++num_items;
	};
	template<typename Item_Type> void Queue<Item_Type>::pop() {
		if (empty()) {  //Throw error for empty queue.
			throw std::invalid_argument("Cannot remove item; queue is empty.");
		}
		f_index = (f_index + 1) % capacity;
		--num_items;
	};
	template<typename Item_Type> void Queue<Item_Type>::move_to_rear() {
		if (empty()) {  //Throw error for empty queue.
			throw std::invalid_argument("Cannot move item; queue is empty.");
		}
		if (num_items == 1) { //If there is only one item in the queue, the function changes nothing.
			return;
		}
		push(front());
		pop();
	};
	template<typename Item_Type> void Queue<Item_Type>::reallocate() { //Expand the queue when out of room by copying the data into a larger vector.
		if (num_items == 0) { //There shouldn't be a capacity 0 queue, but throw an error if there is. 
			throw std::invalid_argument("Queue has 0 capacity.");
		}
		std::vector<Item_Type> temp_data = std::vector<Item_Type>(capacity * 2);
		for (size_t i = 0; i < num_items; i++) {
			temp_data[i] = data[f_index];
			f_index = (f_index + 1) % capacity;
		}

		f_index = 0;
		b_index = capacity;
		capacity = capacity * 2;

		std::swap(data, temp_data);
	};
	
	/*----- Reversed Linear Search Function -----*/
	template<typename Item_Type> size_t reverse_linear_search(std::vector<Item_Type>& items, Item_Type& target, size_t pos_last) {
		//Accepts the last position of the sub-vector instead of the first position.
		if (target == items[pos_last]) { //If the character in the last position is the target, return that position
			return pos_last;
		}
		if (pos_last == 0) { //If the last position is the beginning of the vector and doesn't match, return the fail -1
			return -1;
		}
		else {
			return reverse_linear_search(items, target, pos_last - 1); //Otherwise, recur while reducing the last position of the sub-vector.
		}
	};

	/*----- List Insertion Sort Function -----*/
	void list_insertion_sort(std::list<int>& num) {
		std::list<int>::iterator i, j, k; //Using iterators instead of integer indexes
		bool insertionNeeded = false;

		j = ++num.begin(); // j starts at the node after the beginning, equivalent to index 1
		while (j != num.end()) {
			/*
			//Shows each step of the sorting process prior to the final sorted list.
			std::cout << "\n";
			k = num.begin();
			while (k != num.end()) {
				std::cout << *k;
				std::cout << "  ";
				++k;
			}
			*/

			insertionNeeded = false;

			i = j; //Starting i at j because i is decremented at the beginning of the loop.
			do {
				i--;
				if (*j < *i) { //Compare the values
					insertionNeeded = true;
				}
				else {
					i++; //On finding a smaller value, increment i so that the insertion occurs after that value
					break;
				}
			} while (i != num.begin()); //Terminate upon reaching the beginning of the list.

			if (insertionNeeded) {
				num.insert(i, *j); //Insert the value of j before the i iterator
				j = num.erase(j); //Erase the j node from the list
			}
			else {
				++j; // The j iterator only needs to be incremented if j wasn't set to the result of the erase
			}
		}
	};
}


/*----- Driver Functions -----*/

int main() {
	int select = 0;
	while (select != 3) {
		std::cout << "\n\nDo you want to see the queue demonstration (0), the reversed linear search function (1), the list insertion sort function (2), or quit (3)?\n";
		std::cin >> select;
		try { validate_input(); }
		catch (...) {
			select = 4;
		}
		switch (select)
		{
		case 0:
			q();
			break;
		case 1:
			rls();
			break;
		case 2:
			lis();
		case 3:
			break;
		default:
			std::cout << "Invalid input";
			break;
		}
	}
}

//Queue drivers
void q() {
	int select = -1;
	while (select != 2) {
		std::cout << "\n\nDo you want to see the example demonstration (0), manually test functions on an integer queue (1), or return (2)?\n";
		std::cin >> select;
		try{ validate_input(); }
		catch (...) {
			select = -1;
		}
		switch (select)
		{
		case 0:
			queue_example();
			break;
		case 1:
			queue_play();
		case 2:
			break;
		default:
			std::cout << "Invalid input";
			break;
		}
	}
}
void queue_example() {
	A3::Queue<int> example;
	std::cout << "\nInteger queue instantiated.\n\nFilling queue.";
	//Fill the example queue. Filling with the Fibonacci sequence.
	//Print the pushed value and the size of the queue after the push.
	int i = 0;
	int j = 1;
	for (int k = 0; k < 10; k++) {
		std::cout << "\nPushing ";
		std::cout << j;
		std::cout << " to the queue.";
		example.push(j);
		std::cout << " The size of the queue is now : ";
		std::cout << example.size();
		j = j + i;
		i = j - i;
	}
	std::cout << "\nPress enter to continue.";
	std::cin.get(); //Doubled to prevent skipping caused by menu selections.
	std::cin.get();

	//Display the elements of the queue by popping the front. Stops when the queue is empty.
	std::cout << "\nRunning through queue.";
	while (!example.empty()) {
		std::cout << "\nThe front of the queue is : ";
		std::cout << example.front();
		std::cout << "\nPopping the front of the queue.";
		example.pop();
		if (example.empty()) {
			std::cout << "\nThe queue is now empty.";
		}
	}
	std::cout << "\nPress enter to continue.";
	std::cin.get();

	//Refill the queue for the move_to_rear demonstration.
	std::cout << "\nRefilling queue";
	i = 0;
	j = 1;
	for (int k = 0; k < 4; k++) {
		std::cout << "\nPushing ";
		std::cout << j;
		std::cout << " to the queue.";

		example.push(j);
		j = j + i;
		i = j - i;
	}
	std::cout << "\nPress enter to continue.";
	std::cin.get();

	//Demonstrate move_to_rear by cycling through the queue once.
	std::cout << "\nThe front of the queue is : ";
	std::cout << example.front();
	for (int k = 0; k < example.size(); k++) {
		std::cout << "\nMoving ";
		std::cout << example.front();
		example.move_to_rear();
		std::cout << " to the rear. The new front is : ";
		std::cout << example.front();
	}
	std::cout << "\nPress enter to continue.";
	std::cin.get();
}
void queue_play() {
	A3::Queue<int> example;
	std::cout << "\nInteger queue instantiated.\n\nFilling queue.";
	//Fill the example queue. Filling with the Fibonacci sequence, starting at second term.
	//Print the pushed value and the size of the queue after the push.
	int i = 1;
	int j = 1;
	for (int k = 0; k < 5; k++) {
		std::cout << "\nPushing ";
		std::cout << j;
		std::cout << " to the queue.";
		example.push(j);
		j = j + i;
		i = j - i;
	}
	int select = -1;
	int input;
	
	while (select != 6) {
		select = function_select();
		switch (select) {
		case 0:
			std::cout << "\nThe front of the queue is : ";
			std::cout << example.front();
			break;
		case 1:
			std::cout << "\nThe size of the queue is : ";
			std::cout << example.size();
			break;
		case 2:
			std::cout << "\nThe queue is";
			if (!example.empty()) {
				std::cout << " not";
			}
			std::cout << " empty.";
			break;
		case 3:
			std::cout << "\n\nInput an integer value to push to the queue: ";
			std::cin >> input;
			if (!std::cin) {
				std::cout << "Invalid input.";
				break;
			}
			example.push(input);
			std::cout << "\nPushing ";
			std::cout << input;
			std::cout << " to the queue.";
			break;
		case 4:
			std::cout << "\nPopping ";
			std::cout << example.front();
			example.pop();
			std::cout << " from the front of the queue.";
			if (example.empty()) {
				std::cout << " The queue is now empty.";
			}
			else {
				std::cout<< "The front is now : ";
				std::cout << example.front();
			}
				
			break;
		case 5:
			std::cout << "\nMoving front value of ";
			std::cout << example.front();
			example.move_to_rear();
			std::cout << " to the rear of the queue. The front is now : ";
			std::cout << example.front();
			break;
		case 6:
			break;
		default:
			std::cout << "\nInvalid input.";
			break;
		}
	}
}
int function_select() {//Give the user options, return and int from user input.
	int select;
	std::cout << "\n\nSelect a function: \nfront (0)    |     size (1)\nempty (2)";
	std::cout << "\npush (3)         |     pop (4)\nmove_to_rear (5)         |     Return to menu (6)\nFunction: ";
	std::cin >> select;
	if (!std::cin) { //If input not integer, return -1 as invalid value to caller.
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}
	return select;
}

//Reverse linear search driver
void rls() {
	std::vector<int> num = {1, 1, 2, 3, 5, 8};
	std::cout << "\n\nGenerating initial integer vector.";
	int input, result, select = -1;
	while (select != 2) {
		std::cout << "\n\nThe vector's current contents are:\n{";
		for (int i = 0; i < num.size(); i++) {
			std::cout << num[i];
			if (i < num.size() - 1) {
				std::cout << ", ";
			}
		}
		std::cout << "}";

		std::cout << "\n\nDo you want to add values (0), use the reverse linear search function (1), or go back (2)? ";
		std::cin >> select;
		try {
			validate_input();
		}
		catch (...) {
			select = -1;
		}
		switch (select) {
		case 0:
			std::cout << "\nEnter integer values to add, separated by spaces.\n";

			std::cin.get();
			while (std::cin.peek() != '\n') {
				std::cin >> input;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
				}
				else {
					num.push_back(input);
				}
			}
			break;
		case 1:
			std::cout << "\nEnter a value to be found: ";
			std::cin >> input;
			try {
				validate_input();
			}
			catch (...) {
				std::cout << "\nInvalid input.";
				break;
			}
			result = A3::reverse_linear_search(num, input, num.size()-1);
			if (result == -1) {
				std::cout << "\n";
				std::cout << input;
				std::cout << " was not found found in the vector. The function returned -1.";
			}
			else {
				std::cout << "\nThe input value was found at index ";
				std::cout << result;
				std::cout << " of the vector.";
			}
			break;
		case 2:
			break;
		default:
			std::cout << "\nInvalid input.";
			break;
		}
	}
}

//List insertion sort driver
void lis() {
	int input, select = -1;
	std::cout << "\n\nBuilding initial list.";
	srand(time(0));
	std::list<int> example = {rand(), rand(), rand(), rand(), rand(), rand(), rand()};
	while (select != 3) {
		std::cout << "\nThe list is:\n{";
		std::cout << *example.begin();
		std::list<int>::iterator i = ++example.begin();
		while (i != example.end()) {
			std::cout << ", ";
			std::cout << *i;
			++i;
		}
		std::cout << "}";
		
		std::cout << "\n\nDo you want to generate a new random list (0), manually enter a list (1), run the sort function (2), or go back (3)?";
		std::cin >> select;
		try {
			validate_input();
		}
		catch (...) {
			select = -1;
		}
		switch (select)
		{
		case 0:
			example = { rand(), rand(), rand(), rand(), rand(), rand(), rand() };
			break;
		case 1:
			std::cout << "\nEnter integer values to add, separated by spaces.\n";
			example = {};
			std::cin.get();
			while (std::cin.peek() != '\n') {
				std::cin >> input;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();

				}
				else {
					example.push_back(input);
				}
			}
			break;
		case 2:
			A3::list_insertion_sort(example);
			break;
		case 3:
			break;
		default:
			std::cout << "Invalid input.";
			break;
		}
	}
}

void validate_input() {
	if (!std::cin or std::cin.peek() != '\n') { //Check cin. If fail flag or more characters in buffer, clear the buffer and return false
		std::cin.clear(); //Clears the fail flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clears cin buffer
		throw std::invalid_argument("Invalid input.");
	}
}