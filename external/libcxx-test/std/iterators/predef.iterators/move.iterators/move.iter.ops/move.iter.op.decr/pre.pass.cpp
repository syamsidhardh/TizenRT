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

// move_iterator& operator--();
//
//  constexpr in C++17

#include <iterator>
#include <cassert>

#include "test_macros.h"
#include "test_iterators.h"

template <class It>
void
test(It i, It x)
{
    std::move_iterator<It> r(i);
    std::move_iterator<It>& rr = --r;
    assert(r.base() == x);
    assert(&rr == &r);
}

int main()
{
    char s[] = "123";
    test(bidirectional_iterator<char*>(s+1), bidirectional_iterator<char*>(s));
    test(random_access_iterator<char*>(s+1), random_access_iterator<char*>(s));
    test(s+1, s);

#if TEST_STD_VER > 14
    {
    constexpr const char *p = "123456789";
    typedef std::move_iterator<const char *> MI;
    constexpr MI it1 = std::make_move_iterator(p);
    constexpr MI it2 = std::make_move_iterator(p+1);
    static_assert(it1 != it2, "");
    constexpr MI it3 = -- std::make_move_iterator(p+1);
    static_assert(it1 == it3, "");
    static_assert(it2 != it3, "");
    }
#endif
}
