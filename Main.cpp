#include "pch.h"
#include <iostream>

int main()
{
	winmd::reader::database db("C:\\Users\\Koblizkac\\Documents\\Dev\\CXX\\EmptyWinUI3\\x64\\Debug\\Microsoft.UI.Xaml.winmd");
	for (size_t i = 0; i < db.TypeDef.size(); i++)
	{
		auto row = db.TypeDef[i];
		std::cout << row.TypeName() << std::endl;
	}
	return EXIT_SUCCESS;
}