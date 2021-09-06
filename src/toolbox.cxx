/*
 * toolbox.cxx
 * 
 * Copyright 2021 Michael Tate <mike@Michaels-MBP>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "../inc/toolbox.hxx"

//----------------------------------------------------------
void make_map(MapUU &left){
	// Construct a map 0 <= n < 10^6 of n and corresponding sum
	// std::map< n, sum_of_squares
	const int limit = 1000000;
	U d,sum;
	std::pair<U,U> element;
	for(U n = 0; n < limit; ++n){
		sum = 0;
		d = n;
		while(d){
			sum += std::pow((d%10),2);
			d /=10;
		}
		element = {n, sum};
		left.insert(element);
	}
}


//----------------------------------------------------------
void SieveOfEratosthenes(std::vector<ul> &primes, ul n)
{
	printf("Starting Sieve...");
    // internal vector of bool
    std::vector<bool> prime;
    // Set n+1 entries in vector<bool> to true
    for(ul c = 0; c != n+1; ++c) prime.push_back(true);

    for (ul p = 2; p * p <= n; p++)
	{
		// If prime[p] is not changed,
		// then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples
			// of p greater than or
			// equal to the square of it
			// numbers which are multiples
			// of p and are less than p^2
			// are already been marked.
			for (ul i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
    primes.clear();
    for(ul pn = 2; pn != n+1; ++pn) if(prime[pn]) primes.push_back(pn);
    printf("completed Sieve\n");
}

//----------------------------------------------------------
#if(0)
int main(void) {
	MapUU left;
	make_map(left);
	printf("MapUU.size = %lu\n", left.size());
	for(auto it = left.begin(); it != left.end(); ++it) printf("%u : %u\n", it->first, it->second);
    NL;
}
#endif


