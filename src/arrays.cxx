/*
 * arrays.cxx
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

ul modulus = 10000000000;	// mod 10^10 => 9 digits
const int nDigits = 5;
const unsigned Size = (unsigned)std::pow(10,nDigits);

int main(int argc, char **argv)
{
	std::array<ul, 10> lookup;
	for(ul x = 0; x < 10; ++x) lookup[x] = x*x;
	
	std::array<ul, Size> A = {0};	// sum of squares of digits0 -> 99999
	for(ul x = 0; x < Size; ++x){
		if(A[x]) continue;	// prev set
		std::vector<int> perms;
		ul xx = x;
		A[x] = 0;
		while(xx){
			ul d = xx %10;
			xx /= 10;
			A[x] += lookup[d];
			perms.push_back(d);
		}
		// sort perms ascending
		std::sort(perms.begin(), perms.end());
		// calc all perms
		do{
			// convert vector perms to integer i
			int i = 0;
			for(auto x = perms.begin(); x != perms.end(); ++x){
				i *=10;
				i += *x;
			}
			// A[i] = A[x]	update sum for this permutation
			A[i] = A[x];
		}while(std::next_permutation(perms.begin(), perms.end()));
	}
	
	// Assume that the values in A are correct. n : sumofsquares of digits
	unsigned sumofalln = 0;
	for(unsigned i = 0; i < Size; ++i){
		double_t t = std::trunc(std::sqrt(A[i]));
		if((t * t) != A[i]) continue;
		sumofalln += i;
		sumofalln %= modulus;
	}
	printf("For %u digits somofalln  = %u\n", nDigits, sumofalln);
	printf("Brute force for 6 digits = 161887270\n");	
	return 0;
}

