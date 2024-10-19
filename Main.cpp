#include "pch.h"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <winmd file>" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		winmd::reader::database db(argv[1]);

		printf("\n=================================================\n");
		printf("\nWindows Metadata Typescript definition generator.\n");
		printf("Revision 0v1.0. Licensed under MIT.\n");
		printf("\n=================================================\n");

		for (size_t i = 0; i < db.TypeDef.size(); i++)
		{
			auto row = db.TypeDef[i];
			std::cout << row.TypeName() << std::endl;
		}

	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}