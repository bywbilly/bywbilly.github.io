#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iostream>

class Matrix {
    float *data;
public:
    size_t n, m;
    Matrix(size_t r, size_t c): data(new float[r*c]), n(r), m(c) {}
    ~Matrix() { delete[] data; }
    float& operator() (size_t x, size_t y) { return data[x*m+y]; }
    float operator() (size_t x, size_t y) const { return data[x*m+y]; }
};

float sum2d(const Matrix &a) {
	float ret = 0;
	for (size_t i = 0; i < a.n; ++i) 
		for (size_t j = 0; j < a.m; ++j) {
			ret += a(i, j);
		}
	return ret;
}

void fill(Matrix &a) {
	int cnt = -1;
    for (size_t i = 0; i < a.n; ++i)
        for (size_t j = 0; j < a.m; ++j) {
			a(i, j) = ++cnt;
		}
}

int main() {
    srand((unsigned)time(NULL));
    const int n = 1000, m = 100000, T = 10;
    Matrix x(n, m);
    fill(x);
    auto st = std::chrono::system_clock::now();
    float s = 0;
    for (int i = 0; i < T; ++i) {
		s += sum2d(x);
    }
    auto ed = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = ed-st;
    std::cerr << s << std::endl;
    std::cout << T << " loops. average " << diff.count() * 1e3 / T << "ms" << std::endl;
}
