#include "Serializer.hpp"

int main() {
	Data janek;

	janek.len = 34;
	janek.type = "borec";

	uintptr_t	serialized = Serializer::serialize(&janek);

	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "Original:" << std::endl
		<< "\t" << janek.type << std::endl
		<< "\t" << janek.len << std::endl;


	std::cout << "Seri and De-serialized:" << std::endl
		<< "\t" << deserialized->type << std::endl
		<< "\t" << deserialized->len << std::endl;
}
