#pragma once

#include <iostream>
#include <stdint.h>

struct Data {
	uint32_t		len;
	std::string	type;
};

class Serializer {
private:
	Serializer();
	Serializer(const Serializer &src);
	~Serializer();
	Serializer &operator = (const Serializer &src);
public:
	static uintptr_t	serialize(Data *ptr);
	static Data				*deserialize(uintptr_t raw);
};
