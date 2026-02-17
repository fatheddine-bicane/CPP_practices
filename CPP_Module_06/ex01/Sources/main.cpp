#include "../Includes/Serializer.hpp"
#include <iostream>
#include <ostream>

int main() {
	Data data = {"data", 10};
	std::cout << "The 'data' memory adress value: " << &data << '\n';

	uintptr_t intPtr = Serializer::serialize(&data);
	std::cout << "The 'data' memory adress value: " << intPtr << '\n';


	Data* ptr = Serializer::deserialize(intPtr);
	std::cout << "The 'intPtr' value treated as Data pointer: " << ptr << '\n';

	
	std::cout << "===================================================" << '\n'
			 << "TEST: trying to read the content of 'data' from ptr" << '\n'
			 << "===================================================" << '\n'
			 << "'data' type: " << ptr->type << '\n'
			 << "'data' size: " << ptr->size << '\n';
}
