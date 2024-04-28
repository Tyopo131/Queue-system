#include <iostream>



namespace Qsys {
	
	template<typename Qtype> class Queue {
		Qtype*** Qptr = &queue;
		Qtype** queue = nullptr;
		int maxSize;

	public:
		Qtype* operator[](int index){
			_ASSERT((index >= 0) && (index < maxSize));
			return *(queue + index);
		}
		
	
		Queue(int maxSize) {
			queue = new Qtype* [maxSize];
			_ASSERT(queue != nullptr);
			
			this->maxSize = maxSize;

		}
		int set(int index, Qtype val) {
			if (*(queue + index) != nullptr) {
				**(queue + index) = val;
				return 0;
			}
			return 1;
		}
		void MoveToFront() {
			for (int timer = 0; timer < maxSize; timer++) {
				if ((*(queue + timer) != nullptr)) {
					if (*(queue + (timer - 1)) == nullptr) {
						for (int timer2 = timer; (*(queue + (timer2 - 1)) == nullptr) && !(queue + (timer2 - 1) < queue); timer2--) {
							*(queue + (timer2 - 1)) = *(queue + timer2);
							*(queue + timer2) = nullptr;
						}
					}
				}
			}
		}
		void push() {
			delete *queue;
			*queue = nullptr;
			MoveToFront();
			
		}

		
		enum PUT_RESULT {
			SUCCESS = 0, SLOT_FULL = 2, FAIL = 1
		};


		PUT_RESULT put(Qtype* heapAllocPtr) {
			if (*(queue + (maxSize - 1)) != nullptr) return SLOT_FULL;
			*(queue + (maxSize - 1)) = heapAllocPtr;
			
			return SUCCESS;
		}
		void fillQueue() {
			for (int timer = 0; timer < maxSize; timer++) {
				*(queue + timer) = nullptr;
			}

		}

		
		~Queue() {
			for (int timer = 0; timer < maxSize; timer++) delete *(queue + timer);
			delete[] queue;
		}
	};
	

	
	

}






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
}

