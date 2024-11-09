#ifndef MTRXOPSH
#define MTRXOPSH

#include <vector>
#include <string>

class MatrixOperations
{
public:
	MatrixOperations(const std::vector<std::vector<int>>& matrix);
	
	int sumUpperLeftTriangle();
	int sumUpperRightTriangle();
	int minElementInUpperLeftTriangle();
	int maxElementInUpperLeftTriangle();
	int minElementInUpperRightTriangle();
	int maxElementInUpperRightTriangle();
	
private:
	std::vector<std::vector<int>> matrix;
};

#endif // MTRXOPSH
