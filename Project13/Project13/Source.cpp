#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* prev;
};
class DoubleCircular
{
	node* Startpoint;
	node* Endpoint;

	void insert_at_start(int x);
	void insert_at_end(int x);
	void add_at_pos(int pos,int val);
	void deletion(int pos);
	void Triverse();

public:
	DoubleCircular();
	void Display();
};
DoubleCircular::DoubleCircular()
{
	Startpoint = NULL;
	Endpoint = NULL;
}

void DoubleCircular::insert_at_start(int x)//Adds new node as first node in list
{
	node* temp = new node;
	temp->data = x;

	if (Startpoint == NULL)
	{
		Startpoint = temp;
		Endpoint = temp;
		temp->next = Startpoint;
		temp->prev = Startpoint;

	}

	else
	{
		Startpoint = Endpoint->next;
		Startpoint->prev = temp;
		temp->next = Startpoint;
		temp->prev = Endpoint;
		Endpoint->next = temp;
		Startpoint = temp;

	}
}

void DoubleCircular::insert_at_end(int x)
{
	node* temp = new node;
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;

	if (Startpoint == NULL)
	{
		Startpoint = temp;
		Endpoint = temp;
		temp->next = Startpoint;
		temp->prev = Startpoint;
	}

	else
	{
		Endpoint->next = temp;
		temp->prev = Endpoint;
		Endpoint = temp;
		Endpoint->next = Startpoint;
		Startpoint->prev = Endpoint;
	}
}

void DoubleCircular::add_at_pos(int x, int y)
{
	int count=0;
	node* temp = new node;
	temp = Startpoint;
	while (temp->next != Startpoint)
	{
		temp = temp->next;
		count++;
	}

	if (x > count)
	{
		cout << "The double ring only has " << count << " nodes \n";
	}

	else
	{
		node* current = Endpoint->next;
		node* temp1 = new node;
		temp1->data = y;

		while (x > 1)
		{
			current = current->next;
			x--;
		}

		temp1->prev = current;
		temp1->next = current->next;
		current->next->prev = temp1;
		current->next = temp1;
		if (current = Endpoint)
		{
			Endpoint = Endpoint->next;
		}
	}
}

void DoubleCircular::deletion(int x)
{
	node* temp = new node;
	temp = Endpoint->next;
	while (x > 1)
	{
		temp = temp->next;
		x--;
	}

	node* temp0 = new node;
	temp0 = temp->prev;
	temp0->next = temp->next;
	temp->next->prev = temp0;
	delete(temp);

	if (temp == Startpoint)
	{
		Endpoint->next = temp->next;
		temp->next->prev = Endpoint;
		delete(temp);
		Startpoint = temp;
	}

	if (temp == Endpoint)
	{
		temp = Endpoint->prev;
		temp->next = Endpoint->next;
		Endpoint->next->prev = temp;
		delete(temp);
		Endpoint = temp;
	}

}
void DoubleCircular::Triverse()
{
	/*node* temp = new node;
	temp = Startpoint;

	while (temp->next != Startpoint)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data;*/

	//for reverse triverse 
	
	node *temp=new node;
	temp=Endpoint;
	while(temp->prev!=Endpoint)
	{
	cout<<temp->data<<" ";
	temp=temp->prev;
	}
	cout<<temp->data;
	
}

void DoubleCircular::Display()
{
	DoubleCircular DC;
	DC.insert_at_end(10);
	DC.insert_at_end(20);
	DC.insert_at_end(30);
	DC.insert_at_end(40);
	DC.insert_at_end(50);
	DC.add_at_pos(4, 100);
	DC.Triverse();
	cout << endl;
	cout << endl;
	DC.deletion(5);
	DC.Triverse();
}
int main()
{
	DoubleCircular dcobj;
	dcobj.Display();
	return 0;
}