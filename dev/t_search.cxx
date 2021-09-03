/*
 * t_search.cxx
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


#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>
#include <vector>
typedef std::pair<unsigned,unsigned> Tcount;
typedef std::vector<unsigned>::iterator It;
bool compare(Tcount &l, Tcount &r);
bool compare(Tcount &l, Tcount &r){
	return (l.first == r.first);
}

int main(int argc, char **argv)
{
	// Test data
	std::vector<unsigned> left = {1,3,3,5,5,5,7};
	std::vector<unsigned> right = {13,15,17,19,19,23,23,23,40};

	std::vector<unsigned> t = {14,20,22,28,30,40};
	std::vector<unsigned> c = {0,0,0,0,0,0};
	
	// Search Process
	for(auto i = left.begin(); i < left.end(); ++i){
		for(auto j = right.begin(); j < right.end(); ++j){
			unsigned sum = *i +*j;
			It k;
			for(k = t.begin(); k != t.end(); ++k) if(*k == sum) break;
			if(k != t.end()){	// found sum
				size_t offset = std::distance(t.begin(),k);
				printf("Found %u at offset %zu\n", sum,offset);

				// find the equal ranges in right and left
				size_t rightr = 1;
				while(*(j+1) == *j){
					std::next(j,1);
					++rightr;
				}
				
				size_t leftr = 1;
				while(*(i+1) == *i){
					std::next(i,1);
					++leftr;
				}
				c[offset] += (leftr * rightr);
			}
		}
	}
	// output sums and counts
	//for(auto x = 0; x < t.size(); ++x) printf("t: %u  c: %u\n", t[x], c[x]);
	
	
	// Results
	for(auto x = 0; x < 6; ++x) printf("T:%d  C:%d\n", t[x], c[x]);
	return 0;
}

