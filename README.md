# CS303-Assignment 3 
# Setup:
Import the files into a VisualStudio C++ project. Run the program through VS.
# Usage:
## Menus:
The program includes driver functions to demonstrate functionalities of the Queue class as well as the reverse_linear_search and list_insertion_sort functions. Upon opening, the program will prompt the user to select which functionality to demonstrate by entering the corresponding number.
<br/>
![Initial menu screen](/imgs/menu1.png)
<br/>
Selecting the Queue class will prompt additional input to see an automated demonstration of the class functions, manually test the function, or return to the previous menu.
<br/>
![Initial menu screen](/imgs/menu2.png)
<br/>
Selecting the automated demonstration will display the standard Queue class features, requiring only that the user press Enter between sections.
If choosing to manually test, a sample queue will be generated and a manu of the available functions will display.
<br/>
Upon selecting a function, any appropriate information will be printed, the list contents displayed, and the user returned to the function select step.
<br/>
![Initial menu screen](/imgs/menu3.png)
<br/>
If the reversed linear stack function is selected in the initial menu, a sample vector will be generated, and the user will be prompted to choose to either add values to the vector, use the search function, or return to the previous menu.
<br/>
![Initial menu screen](/imgs/menu4.png)
<br/>
When adding values to the vector, multiple integers can be added, separated by spaces. Non-integer values will be ignored.
<br/>
![Initial menu screen](/imgs/menu5.png)
<br/>
If the list insertion sort function is selected in the initial menu, a list of random integers will be generated, and the user will be prompted to choose to either generate a new random list, manually create a list, use the sort function, or return to the previous menu.
<br/>
![Initial menu screen](/imgs/menu6.png)
<br/>
When manually generating a list, multiple integers can be added, separated by spaces. Non-integer values will be ignored.
<br/>
![Initial menu screen](/imgs/menu7.png)
<br/>
Note: All user inputs are validated after entry. Invalid inputs will return the user to the most recent select menu.

## Queue Functions:
### Item_Type$ front()
### const Item_Type$ front() const:
front accepts no arguments. The function returns the value of the front of the queue. Has mutable and constant versions.
<br/>
![Initial menu screen](/imgs/q1.png)
<br/>
### size_t size():
push_back accepts no arguments. The function returns the number of items currently in the queue.
<br/>
![Initial menu screen](/imgs/q2.png)
<br/>
### bool empty():
empty accepts no arguments. The function returns true if there are no items in the queue, otherwise returns false.
<br/>
![Initial menu screen](/imgs/q3.png)
<br/>
<br/>
![Initial menu screen](/imgs/q4.png)
<br/>
### void push(Item_Type item):
push_back accepts one arguments. The function adds the provided item to the end of the queue.
<br/>
![Initial menu screen](/imgs/q5.png)
<br/>
### void pop():
pop accepts no arguments. The function removes the item at the front of the queue.
<br/>
![Initial menu screen](/imgs/q6.png)
<br/>
### void move_to_rear():
move_to_rear accepts no arguments. The function removes the item at the front of the queue and places it at the end of the queue.
<br/>
![Initial menu screen](/imgs/q7.png)
<br/>
<br/>
## Individual Functions:
### size_t reverse_linear_search(std::vector<Item_Type>& items, Item_Type& target, size_t pos_first);
push accepts three arguments: the vector to be searched, the target to be found, and the index of the last position of the vector to be searched. The function returns the last instance of the target item in the vector. If the target is not found, returns -1.
<br/>
![Initial menu screen](/imgs/rls1.png)
<br/>
<br/>
![Initial menu screen](/imgs/rls2.png)
<br/>
<br/>
![Initial menu screen](/imgs/rls3.png)
<br/>
### list_insertion_sort(std::list<int>& num):
list_insertion_sort accepts one argument. The function sorts the provided linked list in ascending order using the insertion sort algorithm.
<br/>
![Initial menu screen](/imgs/lis1.png)
<br/>
