/*
 * toolbox.hxx
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
#ifndef __TOOLBOX_HXX__
#define __TOOLBOX_HXX__

	#include <iostream>
	#include <numeric>
	#include <array>
	#include <vector>
	#include <map>
	#include <cmath>
	#include <iterator>
	#include <set>

	#define NL std::cout<<std::endl
	typedef unsigned long long ULL;
	typedef uint64_t ul;
	typedef unsigned U;
	typedef std::map<U,U> MapUU;
	void SieveOfEratosthenes(std::vector<ul> &primes, ul n);
	void make_map_pair(MapUU &left, MapUU &right, int digits);
	void make_map(MapUU &left);
#endif
