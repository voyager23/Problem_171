/*
 * forloop.cxx
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
#include <iterator>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
	std::vector<int> T = {0,1,2,2,2,3,3,4};
	size_t jog = 0;
	for(int n = 0; n < T.size(); ++n){
		printf("looking for %d\n",n);
		auto r = std::equal_range(T.begin(), T.end(), n);
		if(r.first != T.end()){
			jog = std::distance(r.first, r.second);
			printf("found %d: jog = %ld  next: %d\n", n, jog, *r.second);
		} else {
			printf("%d not found\n",n);
		}
	}
	return 0;
}

