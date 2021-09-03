/*
 * mapping.cxx
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
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <utility>

typedef std::map<unsigned,unsigned> UUmap;

int main(int argc, char **argv)
{
	unsigned sum;
	UUmap tcount;
	std::vector<std::pair<unsigned,unsigned>> left, right;
	// populate left with test data
	left.push_back(std::make_pair(1,1));
	left.push_back(std::make_pair(3,2));
	left.push_back(std::make_pair(5,3));
	left.push_back(std::make_pair(7,1));
	// populate right with test data
	right.push_back(std::make_pair(13,1));
	right.push_back(std::make_pair(15,1));
	right.push_back(std::make_pair(17,1));
	right.push_back(std::make_pair(19,2));
	right.push_back(std::make_pair(23,3));
	// populate tcount with test data
	tcount.insert(std::make_pair(14,0));
	tcount.insert(std::make_pair(20,0));
	tcount.insert(std::make_pair(22,0));
	tcount.insert(std::make_pair(28,0));
	tcount.insert(std::make_pair(30,0));
	// ---------------------------------------
	
	UUmap::iterator f;
	for(auto l = left.begin(); l < left.end(); ++l){
		for(auto r = right.begin(); r < right.end(); ++r){
			sum = l->first + r->first;
			f = tcount.find(sum);
			if(f != tcount.end()){
				printf("Sum: %u found\n", sum);

					f->second+= l->second * r->second;

			} else {
				printf("Not found: %u\n", sum);
			}
		}
	}
	
	// range based for loop
	for(std::pair<unsigned,unsigned> element : tcount){
		printf("%u : %u\n", element.first, element.second);
	}
		
	return 0;
}

