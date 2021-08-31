/*
 * c_perm.cxx
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
#include <map>
#include <utility>

#include "../inc/c_perm.hxx"

// Definitions
void permute_indexes(Vperms &vp){
	// generate all permutations of 5 indexes
	std::array<unsigned,5> idx = {0,1,2,3,4};
	for(auto a = idx.begin(); a != idx.end(); ++a){
		for(auto b = idx.begin(); b != idx.end(); ++b){
			for(auto c = idx.begin(); c != idx.end(); ++c){
				for(auto d = idx.begin(); d != idx.end(); ++d){
					for(auto e = idx.begin(); e != idx.end(); ++e){
						vp.push_back( Perm {*a,*b,*c,*d,*e} );
					}
				}
			}
		}
	}
}

// ---------------------------------------------------------
int main(int argc, char **argv)
{
	// working data
	Perm data1 = {81,25,1,36,4};
	Perm data2 = {9,49,16,64,0};
	
	Vperms vp;
	
	permute_indexes(vp);
	
	// for each set of indexes, generate 2 partial sums from data1 and data2
	std::multimap<unsigned, Perm> list1; // partial_sum : related perm
	std::multimap<unsigned, Perm> list2;
	
	for(auto a = vp.begin(); a != vp.end(); ++a){
		Perm pm = *a;
		unsigned sum1 = 0;
		unsigned sum2 = 0;
		for(auto b = pm.begin(); b != pm.end(); ++b) {
			sum1 += data1[*b];
			sum2 += data2[*b];
		}
		list1.insert(std::make_pair(sum1, pm));
		list2.insert(std::make_pair(sum2, pm));
	}
	
	size_t foo = list1.size();
	size_t bar = list2.size();
	
	return 0;
	
}

