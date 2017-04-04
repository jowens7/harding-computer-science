#include <iostream>
#include <time.h>

using namespace std;

#define MAXIMUM 1000000
int Factors[MAXIMUM];

extern "C" int properFactors(int, int[], int&);

int properFactorsCpp(int n, int factors[], int& NumFactors) {
	int k = 2;
	int sum = 1;
	factors[0] = 1;
	int i = 1;

	while (k * k <= n) {
		if (n % k == 0) {
			sum += k;
			factors[i] = k;
			i++;

			int factor2 = n / k;

			if (factor2 != k) {
				sum += factor2;
				factors[i] = factor2;
				i++;
			}
		}
		k++;
	}

	NumFactors = i;
	return sum;
}

void runTimings() {
	int q;
	int numFactors;
	int PairCount = 0;
	clock_t StartClock = clock();
	for (int p = 1; p <= MAXIMUM; p++) {
		q = properFactors(p, Factors, numFactors);
		if (q > p) {
			if (properFactors(q, Factors, numFactors) == p) {
				cout << "Amicable Pair : " << p << ", " << q;
				cout << "(" << q << " has " << numFactors << " factors : ";
				cout << Factors[0];
				for (int i = 1; i < numFactors; i++) {
					cout << ", " << Factors[i];
				}
				cout << ")" << endl;
				PairCount++;
			}
		}
	}
	double TotalTime = (double)(clock() - StartClock) / CLOCKS_PER_SEC;
	cout << "Number of amicable pairs found = " << PairCount << endl;
	cout << "Time = " << TotalTime << " chrono::seconds" << endl;
}

int main() {
	runTimings();
	system("pause");
}
