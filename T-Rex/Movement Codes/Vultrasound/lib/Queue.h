#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

struct Node
{
	int val;
	Node *next;
};

class Queue
{
	public:
		Queue();
		~Queue();
		void enqueue(float value);
		void dequeue();
		int& front();
		bool isEmpty();
		void clear()
		void Qprint();
	
	private:
		Node *first;
		Node *last;
};


#endif // QUEUE_H
