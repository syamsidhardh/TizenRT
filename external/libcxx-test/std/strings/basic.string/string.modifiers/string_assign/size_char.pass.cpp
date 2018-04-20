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

// <string>

// basic_string<charT,traits,Allocator>&
//   assign(size_type n, charT c);

#include <string>
#include <cassert>

#include "test_macros.h"

template <class S>
void
test(S s, typename S::size_type n, typename S::value_type c, S expected)
{
    s.assign(n, c);
    LIBCPP_ASSERT(s.__invariants());
    assert(s == expected);
}

int main()
{
    {
    typedef std::string S;
    test(S(), 0, 'a', S());
    test(S(), 1, 'a', S(1, 'a'));
    test(S(), 10, 'a', S(10, 'a'));
    test(S(), 100, 'a', S(100, 'a'));

    test(S("12345"), 0, 'a', S());
    test(S("12345"), 1, 'a', S(1, 'a'));
    test(S("12345"), 10, 'a', S(10, 'a'));

    test(S("12345678901234567890"), 0, 'a', S());
    test(S("12345678901234567890"), 1, 'a', S(1, 'a'));
    test(S("12345678901234567890"), 10, 'a', S(10, 'a'));
    }
}
