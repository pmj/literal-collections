//
//  set.hpp
//  ssdcache
//
//  Created by Phillip Jordan on 12/14/11.
//  Copyright (c) 2011 Phillip Jordan. All rights reserved.
//

#ifndef LITERAL_COLLECTIONS_SET_HPP
#define LITERAL_COLLECTIONS_SET_HPP

#include <set>

/* convenient syntax for creating pre-populated (literal) STL std::set collections
 * 
 * // create a set of integers containing the numbers 1-4
 * std::set<int> my_set = literal::set<int>(1, 2, 3, 4);
 *
 * For even shorter syntax, try
 * namespace l = literal;
 */

namespace literal
{
	template <typename T>
		inline void populate_set(std::set<T>&)
	{}
	
	template <typename T, typename Arg_T, typename... RestTypes>
		inline void populate_set(std::set<T>& coll, Arg_T arg, RestTypes... rest_args)
	{
		coll.insert(arg);
		populate_set(coll, rest_args...);
	}
	
	template <typename T, typename... ElementTypes>
		std::set<T> set(ElementTypes... els)
	{
		std::set<T> coll;
		populate_set(coll, els...);
		return coll;
	}
}


#endif
