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
void make_map_pair(MapUU &left, MapUU &right, int digits){
	// -----sanity check-----
	left.clear();
	right.clear();
	if(digits > 19) return;
	//-------------------------
	
	int nl = digits/2;
	int nr = nl + digits % 2;	// length >= nl;
	// construct the (longest) map right;
	unsigned limit = std::pow(10, nr);
	for(auto m = 1; m < limit; ++m){
		// find sum of squares of digits of m
		unsigned sum = 0;
		unsigned copy = m;
		while(copy){
			sum += (copy % 10)*(copy % 10);
			copy /= 10;
		}
		// insert or update map
		auto result = right.insert(std::make_pair(sum,1));
		if((result.second)==false) result.first->second += 1;
	}
	// insert a (subset) of elements from right to left
	limit = std::pow(10,nl);
	for(auto idx = 0; idx < limit; ++idx) 
		left.insert(std::make_pair(idx, right[idx]));
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
    std::vector<ul> primes;
    const ul n = 9999999;
    SieveOfEratosthenes(primes,n);
    for(auto pf = primes.begin(); pf != primes.end(); ++pf) printf("%lu  ", *pf);
    NL;
}
#endif


