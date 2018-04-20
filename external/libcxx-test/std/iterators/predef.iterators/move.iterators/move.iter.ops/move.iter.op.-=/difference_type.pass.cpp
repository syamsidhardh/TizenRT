/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <iterator>

// move_iterator

// requires RandomAccessIterator<Iter>
//   move_iterator& operator-=(difference_type n);
//
//  constexpr in C++17

#include <iterator>
#include <cassert>

#include "test_macros.h"
#include "test_iterators.h"

template <class It>
void
test(It i, typename std::iterator_traits<It>::difference_type n, It x)
{
    std::move_iterator<It> r(i);
    std::move_iterator<It>& rr = r -= n;
    assert(r.base() == x);
    assert(&rr == &r);
}

int main()
{
    const char* s = "1234567890";
    test(random_access_iterator<const char*>(s+5), 5, random_access_iterator<const char*>(s));
    test(s+5, 5, s);

#if TEST_STD_VER > 14
    {
    constexpr const char *p = "123456789";
    constexpr auto it1 = std::make_move_iterator(p);
    constexpr auto it2 = std::make_move_iterator(p+5) -= 5;
    static_assert(it1 == it2, "");
    }
#endif
}
