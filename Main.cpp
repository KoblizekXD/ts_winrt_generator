#include "pch.h"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <winmd file> [output]" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		winmd::reader::database db(argv[1]);
		FILE* stream = (argc == 3 ? fopen(argv[2], "w+") : stdout);

		printf("Output will be pumped into %s\n\n", (argc == 3 ? argv[2] : "stdout"));

		printf("=================================================\n");
		printf("Windows Metadata Typescript definition generator.\n");
		printf("Revision 0v1.0. Licensed under MIT.\n");
		printf("=================================================\n\n");
		
		for (size_t i = 0; i < db.TypeDef.size(); i++)
		{
			auto row = db.TypeDef[i];
			fprintf(stream, "%s\n", row.TypeName().data());
		}

		fclose(stream);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}