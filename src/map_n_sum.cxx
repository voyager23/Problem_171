/*
 * map_n_sum.cxx
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

#include "../inc/toolbox.hxx"

int main(int argc, char **argv)
{
	MapUU left;
	make_map(left); printf("left.size() = %lu\n", left.size());
	// using 4 iterators MSI = a, LSI = d
	U sum = 0;
	for(auto a = left.begin(); a != std::next(left.begin(),1); ++a){
		for(auto b = left.begin(); b != std::next(left.begin(),1); ++b){
			for(auto c = left.begin(); c != std::next(left.begin(),1); ++c){
				for(auto d = left.begin(); d != std::next(left.begin(),1000); ++d){
					printf("%u : %u\n", d->first, d->second);
					sum += d->second;
				} //d
			} //c
		} //b
	} //a
	printf("Sum = %u\n", sum);
	return 0;
}

