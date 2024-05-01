#pragma once
#include <iostream>



namespace Qsys {

	template<typename Qtype> class Queue {
		Qtype*** Qptr = &queue;
		Qtype** queue;
		int maxSize;
		bool circular;
	public:
		Qtype* operator[](int index) {
			_ASSERT((index >= 0) && (index < maxSize));
			return *(queue + index);
		}


		Queue(int maxSize, bool circular = false) {
			queue = new Qtype * [maxSize];
			_ASSERT(queue != nullptr);
			
			this->maxSize = maxSize;
			this->circular = circular;

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
			Qtype* temp = *queue;
			if (!circular) {
				delete* queue;
			}
			*queue = nullptr;
			MoveToFront();
			if (circular) {
				queue[maxSize - 1] = temp;
			}
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
			for (int timer = 0; timer < maxSize; timer++) {
				if (queue[timer] != nullptr)
					delete queue[timer];
			}
			delete[] queue;
		}
	};



}