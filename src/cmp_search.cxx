/*
 * cmp_search.cxx
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
#include <map>
#include <vector>

#include "../inc/toolbox.hxx"

int main(int argc, char **argv)
{
	MapUU sum_count;
	
	for(auto a = 0; a <10; ++a){
		unsigned aa = a*a;
		for(auto b = 0; b <10; ++b){
			unsigned bb = aa + (b*b);
			for(auto c = 0; c <10; ++c){
				unsigned  cc = bb + c*c;
				auto r = sum_count.insert(std::make_pair(cc,1));
				if(r.second == false)  
					r.first->second += 1;  // increment an existing sum
			}
		}
	}

#if(0)
	// range based for loop
	for(MapUU element : sum_count){
		printf("%u : %u\n", element.first, element.second);
	}
#endif
	
	std::map<unsigned,unsigned> L,R;
	L = sum_count;
	R = sum_count;
	sum_count.clear();
	
	// now map squares and counts
	// 243*2 = 486
	// 23^2 = 529
	std::map<unsigned, unsigned> t_count;
	unsigned n = 0;
	do{
		t_count.insert(std::make_pair((n*n),0));
		n += 1;
	} while((n*n) <= 529);
	
	// do search for all sums which are perfect squares
	
	printf("Starting search...");
	for(auto p = L.begin(); p != L.end(); ++p){
		for(auto q = R.begin(); q != R.end(); ++q){
			auto r = t_count.find(p->first + q->first);
			if(r != t_count.end()) r->second += 1;
		}
	}
	printf("complete\n");
	
	// calc final sum from t_count.second
	unsigned final_sum = 0;
	for(std::pair<unsigned,unsigned> element : t_count) final_sum += element.second;
	printf("Final sum: %u\n", final_sum - 1);
	
	MapUU mapl,mapr;
	make_map_pair(mapl,mapr,4);
	
	return 0;
}

