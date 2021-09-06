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

#include "../inc/toolbox.hxx"

int main(int argc, char **argv)
{
	// Construct a set of squares
	std::set<unsigned long> sqrs;
	unsigned long ss, s = 0;
	do{
		ss = s*s;
		sqrs.insert(ss);
		s += 1;
	}while(ss < 10000000000L);
	
	printf("Max square %lu\n", *(std::next(sqrs.end(), -1)));
	
	MapUU left;
	make_map(left); printf("left.size() = %lu\n", left.size());
	// using 4 iterators MSI = a, LSI = d
	U sa, sb, sc, sd;	// partial sums for each iterator group
	for(auto a = left.begin(); a != std::next(left.begin(),1); ++a){
		sa = a->first;
		for(auto b = left.begin(); b != std::next(left.begin(),1); ++b){
			sb = sa + b->first;
			for(auto c = left.begin(); c != std::next(left.begin(),1); ++c){
				sc = sb + c->first;
				for(auto d = left.begin(); d != std::next(left.begin(),100000); ++d){
					sd = sc + d->first;
					auto froot = sqrs.find(sd);
					if(froot != sqrs.end())
						printf("%u+%u+%u+%u = %u ->%lu\n", a->first, b->first, c->first, d->first, sd, *froot);
				} //d
			} //c
		} //b
	} //a
	return 0;
}

