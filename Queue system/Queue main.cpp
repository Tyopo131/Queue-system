#include <iostream>

#ifdef __cplusplus
namespace Qsys {
	extern "C" {
#endif // __cplusplus

		typedef double Qtype;
		int maxSize; // ALWAYS INITIALISE BEFORE CALLING createQueue OTHERWISE YOU MAY END UP TRYING TO MAKE AN ARRAY THAT IS 7177728 ELEMENTS LONG.
		Qtype** queue = nullptr; // ALWAYS CALL createQueue BEFORE CALLING ANY FUNCTIONS, OTHERWISE YOU MAY DEREFERENCE A NULL POINTER.
		void createQueue() {
			queue = new Qtype * [maxSize];
			_ASSERT(queue != nullptr);

		}
		void push() {
			for (int timer = 0; timer < maxSize; timer++) {
				
			}
		}

		Qtype*** Qptr = &queue;
		
		void fillQueue();
		enum PUT_RESULT {
			SUCCESS = 0, SLOT_FULL = 2, FAIL = 1
		};


		PUT_RESULT put(Qtype* heapAllocPtr) {
			for (int timer = 0; timer < maxSize; timer++) {
				if ((timer + 1) < maxSize) {

				}
			}
			return SUCCESS;
		}
		void fillQueue() {
			for (int timer = 0; timer < maxSize; timer++) {
				*(queue + timer) = nullptr;
			}

		}


#ifdef __cplusplus
	}
#endif // __cplusplus
#ifdef __cplusplus
}
#endif // __cplusplus




#ifdef __cplusplus
using namespace Qsys;
#endif
int main() {
	maxSize = 10;
	createQueue();
	fillQueue();

	put(new Qtype);


}
