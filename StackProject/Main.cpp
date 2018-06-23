#include <iostream>
#include <string>

using namespace std;

//Stack: container of items (FSLO)

struct Node {
	Node * next;	//main node has a pointer to another node
	string data;

};

class Stack {

	public:
		Stack();	//constructor
		void push(string);	//add to the stack :push	
		string pop();	//pop top node off of stack
		string toString();	//display stack content as string. top -> bottom
		bool isEmpty();	// helper function to check fast if there stack is empty or not
		~Stack();	//destructor

	private:
		Node *head;	//any item pointing to the top of the stack
};


Stack::Stack() {	//init stack to be empty
	head == NULL;	//stack is empty when head is pointing nowhere. 
}

void Stack::push(string d) {
	//we need to create a new node to push it
	
	//this will allocate  dynamic variable, (memory in the heap)
	//pointer variable tmp
	Node *tmp = new Node;	//new node tmp
	tmp->data = d;
	tmp->next = head;	// point new node next to the head top of stack
	head = tmp;	//point head to the new top of the stack

}

//function to know if the head is empty
bool Stack::isEmpty() {
	return (head == NULL);	//reutnr if head is empty 
}

//display list into string
string Stack::toString() {
	string result = "(top) -> ";
	//check if is empty first
	if (isEmpty()) {
		result = result + " (empty) ";	//show empty elements
		return result;
	}
	else {
		Node *current = head;
		while (current != NULL) {	//while is not empty or null keep going 
			result = result + current->data + " -> ";
			current = current->next;	//keep going  unltill NULL
		}
		result = result + "(end)";
		return result;
	}
}

//Pop function
string Stack::pop() {
	if (!isEmpty()) {
		string value = head->data;	//if we delete, we need to delete that node and change the pointer
		Node *oldHead = head;	//keeps track of our old head was
		head = oldHead->next;
		delete(oldHead);
		return value;
	}
	else {
		//cant pop when is empty
		cout << "Stack is emtpy" << endl;
		exit(EXIT_SUCCESS);
	}
	
}

//Destructor
Stack::~Stack() {
	while (!isEmpty()) {
		pop();
	}

}

//MAIN
int main() {

	Stack *s = new Stack();		//create stack
	cout << "Output when empty: " << endl
		 << s->toString() << endl;

	//push some elements
	s->push("Sushi");
	s->push("Pizza");
	s->push("Completo");
	
	cout << "Output when not empty: " << endl
		<< s->toString() << endl;

	delete s;
	system("pause");
	return 0;
}





