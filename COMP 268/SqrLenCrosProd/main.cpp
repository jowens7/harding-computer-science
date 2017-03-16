#include <iostream>

/*
 * Jerred Shepherd
 * SqrLenCrossProd
 * 3/16/2017
 */

const bool debug = true;

int SqrLenCrosProdCpp(int x1, int y1, int z1, int x2, int y2, int z2) {

	int x3, y3, z3;
	int answer;

	x3 = y1 * z2 - y2 * z1;
	y3 = x2 * z1 - x1 * z2;
	z3 = x1 * y2 - x2 * y1;

	std::cout << "Expected x3: " << x3 << std::endl;
	std::cout << "Expected y3: " << y3 << std::endl;
	std::cout << "Expected z3: " << z3 << std::endl;

	answer = (x3 * x3 + y3 * y3 + z3 * z3);

	return answer;
}

int SqrLenCrosProd(int x1, int y1, int z1, int x2, int y2, int z2) {

	int x3, y3, z3;
	int answer;

	/*
	x3 = y1 * z2 - y2 * z1;
	y3 = x2 * z1 - x1 * z2;
	z3 = x1 * y2 - x2 * y1;

	answer = (x3 * x3 + y3 * y3 + z3 * z3);
	*/

	// x3 = ((y1 * z2) - (y2 * z1))
	__asm {
		// y1 * z2
		mov eax, y1
		imul eax, z2

		// y2 * z1
		mov ebx, y2
		imul ebx, z1

		// subtract the two
		sub eax, ebx
		mov x3, eax
	}

	// y3 = ((x2 * z1) - (x1 * z2))
	__asm {
		// x2 * z1
		mov eax, x2
		imul eax, z1

		// x1 * z2
		mov ebx, x1
		imul ebx, z2

		// subtract the two
		sub eax, ebx
		mov y3, eax
	}

	// z3 = ((x1 * y2) - (x2 * y1))
	__asm {
		// x1 * y2
		mov eax, x1
		imul eax, y2

		// x2 * y1
		mov ebx, x2
		imul ebx, y1

		// subtract the two
		sub eax, ebx
		mov z3, eax
	}

	// answer = ((x3 * x3) + (y3 * y3) + (z3 * z3))
	__asm {
		// x3 * x3
		mov eax, x3
		imul eax, eax

		// y3 * y3
		mov ebx, y3
		imul ebx, ebx

		// z3 * z3
		mov ecx, z3
		imul ecx, ecx

		// add the three results together
		add eax, ebx
		add eax, ecx
		mov answer, eax
	}

	if (debug) {
		std::cout << "Actual x3: " << x3 << std::endl;
		std::cout << "Actual y3: " << y3 << std::endl;
		std::cout << "Actual z3: " << z3 << std::endl;
	}

	return answer;

}

void test() {
	const int NUM_OF_TESTS = 3;

	bool pass = true;

	int inputs[NUM_OF_TESTS][7] = {
		{1, 2, 3, 1, 1, 1, 6},
		{1, 0, 0, 0, 1, 0, 1},
		{10, 10, 10, -10, 50, -15, 785000}
	};

	for (int set = 0; set < NUM_OF_TESTS; set++) {
		int x1 = inputs[set][0];
		int y1 = inputs[set][1];
		int z1 = inputs[set][2];
		int x2 = inputs[set][3];
		int y2 = inputs[set][4];
		int z2 = inputs[set][5];
		int expectedResult = inputs[set][6];

		int actualResult = SqrLenCrosProd(x1, y1, z1, x2, y2, z2);

		if (debug) {
			SqrLenCrosProdCpp(x1, y1, z1, x2, y2, z2);
		}

		if (expectedResult != actualResult) {
			pass = false;
		}

		std::cout << "Test #" << set + 1 << std::endl;
		std::cout << "Expected: " << expectedResult << std::endl;
		std::cout << "Actual: " << actualResult << std::endl;
		std::cout << std::endl;
	}

	if (!pass) {
		std::cout << "Tests failed" << std::endl;
	}
	else {
		std::cout << "Tests passed" << std::endl;
	}
}

int main() {
	test();
	system("pause");
}
