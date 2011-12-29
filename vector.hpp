//
//  vector.h
//  ssdcache
//
//  Created by Phillip Jordan on 12/15/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef LITERAL_COLLECTIONS_VECTOR_HPP
#define LITERAL_COLLECTIONS_VECTOR_HPP

#include <vector>

namespace literal
{
	template <typename T>
		inline void populate_vector(std::vector<T>&)
	{}
	
	template <typename T, typename Arg_T, typename... RestTypes>
		inline void populate_vector(std::vector<T>& coll, Arg_T arg, RestTypes... rest_args)
	{
		coll.push_back(arg);
		populate_vector(coll, rest_args...);
	}
	
	template <typename... ArgTypes> struct vararg_len;
	
	template <> struct vararg_len<>
	{
		static const size_t len = 0u;
	};
	template <typename T, typename... RestTypes> struct vararg_len<T, RestTypes...>
	{
		static const size_t len = 1u + vararg_len<RestTypes...>::len;
	};
	
	template <typename T, typename... ElementTypes>
		std::vector<T> vector(ElementTypes... els)
	{
		std::vector<T> coll;
		size_t num_els = vararg_len<ElementTypes...>::len;
		coll.reserve(num_els);
		populate_vector(coll, els...);
		return coll;
	}
}


#endif
