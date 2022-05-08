/**
 * \file  CircularLinkedList.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

class CircularLinkedList
{
	Node *head;
public:
	CircularLinkedList() : head(NULL)
	{}

	// get the head node
	Node* getHead();

	//create Node
	Node* createNode(int x);

	//Insert at the end
	void insertAtEnd();

};

Node* CircularLinkedList :: createNode(int x)
{
	Node* temp;
	temp = new(Node);

	if (temp == NULL)
	{
		cout << "Memory Unavailable" << endl;
		return NULL;
	}
	else
	{
		temp->data = x;
		temp->next = NULL;
		return temp;
	}
}

void CircularLinkedList :: insertAtEnd()
{

}

int main(int argc, char const *argv[])
{
	STD_UNUSED(argc);
	STD_UNUSED(argv);

	/* code */

	return 0;
}
