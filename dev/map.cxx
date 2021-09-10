/*
 * unoed_map.cxx
 * 
 * Copyright 2021 Mike <mike@pop-os>
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
#include <map>

int main(int argc, char **argv)
{
	std::map<unsigned, std::vector<unsigned> > m1;
	std::map<unsigned, std::vector<unsigned> >::iterator im;
	
	std::vector<std::pair<unsigned,unsigned>> data = { {36, 244}, {36, 424}, {36, 442}, {14, 123}, {14, 321}, {14, 213}, {14, 312} };

	for(auto i = data.begin(); i != data.end(); ++i){
		im = m1.find(i->first);
		if(im == m1.end()){ // new key::value pair
			m1.insert(std::make_pair(i->first, std::vector<unsigned> {i->second}));
		} else {
			(im->second).push_back(i->second);
		}
	}
	
	im = m1.find(36);
	if(im != m1.end()){
		unsigned sum = 0;
		for(auto x = im->second.begin(); x != im->second.end(); ++x) sum += *x;
		printf("Sum[36]:%u\n",sum);
	} else {
		printf("Not found 36\n");
	}
	

	return 0;
}

