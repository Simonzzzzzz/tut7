//Student name:
//Studnet ID  :

// Submission is not required

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

//----------------------------------- linked list node structure and functions prepared for you

struct node 
{
    int info;
    node *link;
};

node* createNode(int info) 
{
	node *p = new node;   
	p->info = info;
	p->link = NULL;
	return p;
}

node* genList(int n)
{
	node *list = NULL;	

	if (n > 0)
	{
		int k = 2 * n;
		list = createNode(1 + rand() % k);
		node *p = list;
		for (int i = 1; i < n; i++)
		{		
			p->link = createNode(1 + rand() % k);
			p = p->link;
		}
	}
	return list;
}

void printList(node *list) 
{
    node *p = list;

    while (p != NULL) 
	{
        cout << p->info << " -> ";
        p = p->link;
    }
    cout << "NULL\n";
}

//--------------------------------------- function to be implemented by you

void removeMax(node*& list)
{
	// Remove the node with the largest value.
	// If multiple nodes have the same max value, remove the first copy.

	// You need to consider the case when the input list is empty.
	// You need to de-allocate the memory occupied by the removed node to the OS.

	// Your codes

	node* cur=list;
	node *max=cur;
	node* prev=NULL;
	node* maxprev=NULL;
	while(cur!=NULL){
		if(cur->info>max->info){
			maxprev=prev;
			max=cur;
		}
		prev=cur;
		cur=cur->link;
	}	
	if(max!=NULL){
		if(maxprev!=NULL){
			maxprev->link=max->link;
		}
		else{
			list=max->link;
		}
	}
	delete max;
}

void removeOdd(node*& list)
{
	// Remove all nodes with odd value.

	// Your codes
	node* prev=NULL;
	node* cur=list;
	while(cur!=NULL){
		if(cur->info%2==0){
			prev=cur;
			cur=cur->link;
		}
		else{
			if(prev==NULL){
				list=cur->link;
				delete cur;
				cur=list;
			}
			else{
				prev->link=cur->link;
				delete cur;
				cur=prev->link;
			}
			
		}

	}
}

int main() 
{
	srand((unsigned)time(NULL));
	int n = 6;
	node *listA = genList(n);

	cout << "Part-1:\n\n";
	cout << "List A: ";
	printList(listA);
	cout << endl;

	for (int i = 0; i <= n; i++)
	{
		
		cout << "Call removeMax(listA)\n";
		removeMax(listA);
		cout << "List A: ";
		printList(listA);
		cout << endl;
	}

	cout << "-----------------------------------------------\n\n";
	cout << "Part-2:\n\n";
	node *listB = genList(10);
	cout << "List B: ";
	printList(listB);
	cout << endl;

	cout << "Call removeOdd(listB)\n";
	removeOdd(listB);
	cout << "List B: ";
	printList(listB);
	cout << endl;

	system("pause");
	return 0;
}

