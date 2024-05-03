#pragma once
#include <iostream>



namespace Qsys {
	
	template<typename Qtype> class Queue {

		Qtype*** Qptr = &queue;
		Qtype ERROR_VAL;
		Qtype** queue;
		int maxSize;
		bool circular;
		
	public:
		bool isValid(int index) {
			if (index >= maxSize) throw std::invalid_argument("Index out of range");
			return queue[index] != nullptr;
		}
		template<typename T>
		friend std::ostream& operator<<(std::ostream& stream, Queue<T>& obj);
		Qtype operator[](int index) {
			if (!((index >= 0) && (index < maxSize))) throw std::invalid_argument("Index out of range");
			if (queue[index] == nullptr) throw std::runtime_error("Pointer at index is nullptr");
			else return **(queue + index);
		}


		Queue(int maxSize, Qtype RESERVED, bool circular = false) {
			queue = new Qtype * [maxSize];
			_ASSERT(queue != nullptr);
			
			this->maxSize = maxSize;
			this->circular = circular;
			this->ERROR_VAL = RESERVED;
			

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
		void push(int numOfTimes) {
			for (int timer = 0; timer < numOfTimes; timer++) push();
		}


		enum PUT_RESULT {
			SUCCESS = 0, SLOT_FULL = 2, FAIL = 1
		};


		PUT_RESULT put(Qtype* heapAllocPtr) {
			if (*(queue + (maxSize - 1)) != nullptr) return SLOT_FULL;
			*(queue + (maxSize - 1)) = heapAllocPtr;
			MoveToFront();
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
	
	template<typename T>
	std::ostream& operator<<(std::ostream& stream, Qsys::Queue<T>& obj) {
		for (int timer = 0; timer < obj.maxSize; timer++) {
			if (obj.isValid(timer))
				stream << obj[timer] << '\n';
		}
		return stream;
	}
	


}
