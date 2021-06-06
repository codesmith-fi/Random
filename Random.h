/**
Pseudo Random Number generation tools
Author: Erno Pakarinen 

About

Contains several high performance pseudo random number generators 

Random number generator references:
https://en.wikipedia.org/wiki/Lehmer_random_number_generator
https://lemire.me/blog/2019/03/19/the-fastest-conventional-random-number-generator-that-can-pass-big-crush/
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
		uint32_t randomInt(uint32_t _low, uint32_t _high) {
			return (_low + (lehmer() % (_high - _low)));
		};

		double randomDouble(double _low, double _high) {
			return ( _low + ((double)lehmer() / (double)0x7fffffff) * (_high - _low) );
		};

		double randomDouble2(double _low, double _high) {
			return (_low + ((double)random2() / (double)0xffffffff) * (_high - _low));
		};

		// Chains lehmer and xorshift
		uint32_t random2()
		{
			uint32_t r = lehmer();
			return xorshift32();
		}

		// Lehmer - taken from 
		// https://en.wikipedia.org/wiki/Lehmer_random_number_generator
		uint32_t lehmer()
		{
			uint64_t product = (uint64_t)m_state * 48271;
			uint32_t x = (product & 0x7fffffff) + (product >> 31);

			x = (x & 0x7fffffff) + (x >> 31);
			return m_state = x;
		}

		// Xorshift - Taken from 
		// https://en.wikipedia.org/wiki/Xorshift
		uint32_t xorshift32()
		{
			uint32_t x = m_state;
			x ^= x << 13;
			x ^= x >> 17;
			x ^= x << 5;
			return m_state = x;
		}

	private:
		uint32_t m_state;		
	};
}

#endif // __RANDOM_H_DEFINED__
