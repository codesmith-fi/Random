/**
Pseudo Random Number generation tools
Author: Erno Pakarinen 

About

Contains several high performance pseudo random number generators 

Acknowledgements:
https://en.wikipedia.org/wiki/Lehmer_random_number_generator
https://en.wikipedia.org/wiki/Xorshift
https://en.wikipedia.org/wiki/Permuted_congruential_generator

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

#ifndef __RANDOM_H_DEFINED__
#define __RANDOM_H_DEFINED__

namespace codesmith {
	class Random {
	public: // Constructors
		Random() : m_state(1u) {};
		Random(uint32_t _seed) : m_state(_seed) {};
		virtual ~Random() = default;

	public: // Generators and seeders
		void seed(uint32_t _seed) { m_state = _seed; };

		// Lehmer random number generators
		uint32_t lcg_parkmiller()
		{
			uint64_t product = (uint64_t)m_state * 48271;
			uint32_t x = (product & 0x7fffffff) + (product >> 31);

			x = (x & 0x7fffffff) + (x >> 31);
			return m_state = x;
		};
		
		uint32_t lcg_rand()
		{
			uint64_t product = (uint64_t)m_state * 279470273u;
			uint32_t x;
			product = (product & 0xffffffff) + 5 * (uint32_t)(product >> 32);
			product += 4;
			x = (uint32_t)product + 5 * (uint32_t)(product >> 32);
			return m_state = x - 4;
		}
	private:
		uint32_t m_state;
	};
}

#endif // __RANDOM_H_DEFINED__
