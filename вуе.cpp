#include <iostream>
#include <vector>

template<typename T>
std::vector<std::vector<T>> EraseCol(const std::vector<std::vector<T>>& Arg, size_t n, size_t k) {
	std::vector<std::vector<T>>& vec = Arg;
	for (size_t i = 0; i < n; i++)
	{
		vec.erase(vec[i].begin() + k);
	}
	return vec;
}
template<typename T>
void EraseRow(const std::vector<std::vector<T>>& Arg, size_t n, size_t k) {
	std::vector<std::vector<T>>& vec = Arg;
	for (size_t i = 0; i < n; i++)
	{
		vec.erase(vec[k].begin() + i);
	}
}


template<typename T, size_t N>
int det(const std::vector<std::vector<T>>& Arg, size_t n) {
	int size = n;
	int rez = 0;
	std::vector<std::vector<T>> matr = Arg;
	EraseRow(matr, n, 0);
	std::vector<std::vector<T>> tmp = matr;
	
	if (size == 1) return matr[0][0];
	else if (size == 2)
	{
		return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
	}
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			tmp = EraseCol(matr, n, i);
			rez+= matr[0][i] * det(tmp, n - 1);
			tmp = matr;
		}
	}
	return rez;
}

int main()
{
	std::vector<std::vector<int>> matr = { {0, 1, 2}, {1, 4, 5}, {1, 0, 1} };
	size_t n = 3;
	std::cout << det(matr, n) << std::endl;
}
