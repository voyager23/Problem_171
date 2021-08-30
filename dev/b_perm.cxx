/*
 * b_perm.cxx
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
 * Examine permutation generator
 */


#include <iostream>
#include <vector>
#include <cmath>
#include <set>

typedef std::vector<int> Perm;
typedef std::vector<Perm> Vperms;

int main(int argc, char **argv)
{
	// working data
	Perm data1 = {81,25,1,36,4};
	Perm data2 = {9,49,16,64,0};
	// setup a set of squares up to 30^2
	std::set<int> squares;
	for(int n = 0; n != 31; ++n) squares.insert(n*n);
	
	// Setup the output vector of permutations
	Vperms src, dest;
	for(auto a = data1.begin(); a != data1.end(); ++a){
		Perm t = { *a };
		src.push_back(t);
	}
	int pass_count = 4;	// largest perm is passcount+1
	Vperms::iterator foo = src.begin();
	do{
		// using src and data vectors
		for(auto a = foo; a != src.end(); ++a){
			for(auto b = data1.begin(); b != data1.end(); ++b){
				Perm t = *a;	// vector from source
				t.push_back(*b);
				dest.push_back(t);
			}
		}
		size_t ss = src.size();
		src.insert(src.end(), dest.begin(), dest.end());
		dest.clear();
		foo = src.begin() + ss;
	} while(--pass_count);
	
	// diagnostic printout
	
	for(auto a = src.begin(); a != src.end(); ++a){
		int acc = 0;
		for(auto b = a->begin(); b != a->end(); ++b){
			acc += *b;
			printf("%d ", *b);
		}
		auto sr = std::floor(std::sqrt(acc));
		if((sr*sr)==acc) printf(" %d is square.", acc);
		printf("\n");
	}
	
	return 0;
	
}

