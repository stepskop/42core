#include <iostream>
#include <fstream>

std::string replace_line(std::string line, std::string target, std::string replace)
{
	if (!target.length())
		return line;
	size_t foundAt = line.find(target);
	while (foundAt != std::string::npos) {
		line = line.erase(foundAt, target.length());
		line = line.insert(foundAt, replace);
		foundAt = line.find(target, foundAt + replace.length());
	}
	return line;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid args" << std::endl;
		return 1;
	}
	std::ifstream in_file(argv[1]);
	if (!in_file.is_open())
	{
		std::cout << "Error while opening the input file" << std::endl;
		return 1;
	}
	std::ofstream out_file((std::string(argv[1]) + ".replace").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!out_file.is_open())
	{
		std::cout << "Error while opening/creating the output file" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(in_file, line))
	{
		if (out_file.bad() || in_file.bad())
		{
			std::cout << "I/O error" << std::endl;
			break;
		}
		line = replace_line(line, argv[2], argv[3]);
		out_file << line;
		if (!in_file.eof())
			out_file << std::endl;
	}
	in_file.close();
	out_file.close();
}
