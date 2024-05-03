#include "Qsys.h"




int main() {
	Qsys::Queue<std::string> fruit(15, "bhkfapr'pgnbvaelrng", true);
	fruit.fillQueue();
	fruit.put(new std::string("apple"));
	fruit.put(new std::string("strawberries"));
	fruit.put(new std::string("blueberries"));
	fruit.put(new std::string("satsumas"));
	fruit.put(new std::string("watermelon"));
	fruit.put(new std::string("bananas"));
	fruit.push(4);
	
	
	std::cout << fruit;
}

