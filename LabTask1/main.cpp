#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "mtrxops.h"
using namespace std;

void showHelp()
{
	cout << "Использование:\n"
		<< "--help 	Вывести на экран это сообщение\n"
		<< "--input <файл> Входной файл с матрицей\n"
		<< "--part <часть> Часть матрциы (upper_left или upper_right)\n"
		<< "--operation <операция> Операция (sum, min, max)\n";
}

int main(int argc, char* argv[])
{
	if (argc < 1)
	{
		showHelp();
		return 1;
	}
	
	string inputFile, part, operation;
	
	for (int i = 1; i < argc; i += 2)
	{
		string arg = argv[i];
		if (arg == "--help")
		{
			showHelp();
			return 0;
		} else if (arg == "--input")
		{
			inputFile = argv[i + 1];
		} else if (arg == "--part")
		{
			part = argv[i + 1];
		} else if (arg == "--operation")
		{
			operation = argv[i + 1];
		}
	}
	
	vector<vector<int>> matrix(4, vector<int>(4));
	ifstream file(inputFile);
	if (!file.is_open())
	{
		cerr << "Ошибка открытия файла\n";
		return 1;
	}
	
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			file >> matrix[i][j];
		}
	}
	file.close();
	
	MatrixOperations matrixOps(matrix);
	
	int result = 0;
	
	if (part == "upper_left")
	{
		if (operation == "sum")
		{
			result = matrixOps.sumUpperLeftTriangle();
		}else if (operation == "min")
		{
			result = matrixOps.minElementInUpperLeftTriangle();
		} else if (operation == "max")
		{
			result = matrixOps.maxElementInUpperLeftTriangle();
		}
	} else if (part == "upper_right")
	{
		if (operation == "sum")
		{
			result = matrixOps.sumUpperRightTriangle();
		}else if (operation == "min")
		{
			result = matrixOps.minElementInUpperRightTriangle();
		} else if (operation == "max")
		{
			result = matrixOps.maxElementInUpperRightTriangle();
		}
	} else 
	{
		cout << "Что?" << endl;
		return 1;
	}
	cout << "Результат: " << result << endl;
	return 0;
}
