#include "Qsys.h"

using namespace Qsys;

int main() {
	
	Queue<int> queue(15);
	queue.fillQueue();
	queue.put(new int);
	queue.MoveToFront();
	queue.put(new int);
	queue.MoveToFront();
	queue.set(1, 93);
	queue.set(0, 23); 
	queue.push();
	std::cout << *queue[0];
	std::cin.get();
}

