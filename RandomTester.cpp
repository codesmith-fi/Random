/**
Random

Codesmith License V1.0

Copyright(c) 1999 - 2021 Erno Pakarinen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

The original author shall be credited of the work related to this Software and
in all software using this Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <iostream>

#include "Random.h"

int main()
{
	codesmith::Random gen(314159u);

	std::cout << "Ints between 0 - 100\n";
	for(int i = 0; i < 20; ++i) {
		uint32_t r = gen.randomInt(0, 100);
		std::cout << "Rand: " << r << "\n";
	}

	std::cout << "\nInts between 10 - 50\n";
	for(int i = 0; i < 20; ++i) {
		uint32_t r = gen.randomInt(10, 50);
		std::cout << "Rand: " << r << "\n";
	}

	std::cout << "\nDoubles between 100.0 - 200.0\n";
	for(int i = 0; i < 20; ++i) {
		double r = gen.randomDouble(100.0f, 200.0f);
		std::cout << "Rand: " << r << "\n";
	}
	return 0;
}
