/*
 * adev.cxx
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
#include <vector>
#include <iterator>
#include <cmath>

typedef std::array<int,10> Intarray;
typedef Intarray::iterator Iter;

int main(int argc, char **argv)
{
	Intarray squares = {0,1,4,9,16,25,36,49,64,81};
	
	std::vector<Iter> idx;
	
	std::vector<int> foo(10,0);
	
	// setup 3 iterators
	idx.push_back(squares.begin());
	idx.push_back(squares.begin());
	idx.push_back(squares.begin());
	
	for(idx[0] = squares.begin(); idx[0] != squares.end(); ++idx[0]){
		for(idx[1] = squares.begin(); idx[1] != squares.end(); ++idx[1]){
			int s01 = *(idx[0]) + *(idx[1]);
			for(idx[2] = squares.begin(); idx[2] != squares.end(); ++idx[2]){
				int s02 = s01 + *(idx[2]);
				// if s02 is perf. sqr print s02
				int x = std::floor( std::sqrt(s02) );
				if(s02 == (x*x)) std::cout << s02 << std::endl;
			}
		}
	}
	
	return 0;
}

