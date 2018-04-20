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

// template<> struct char_traits<char16_t>

// static int compare(const char_type* s1, const char_type* s2, size_t n);
// constexpr in C++17

#include <string>
#include <cassert>

#include "test_macros.h"

#if TEST_STD_VER > 14
constexpr bool test_constexpr()
{
    return std::char_traits<char16_t>::compare(u"123", u"223", 3) < 0
        && std::char_traits<char16_t>::compare(u"223", u"123", 3) > 0
        && std::char_traits<char16_t>::compare(u"123", u"123", 3) == 0;
}
#endif


int main()
{
#ifndef _LIBCPP_HAS_NO_UNICODE_CHARS
#if TEST_STD_VER >= 11
    assert(std::char_traits<char16_t>::compare(u"", u"", 0) == 0);
    assert(std::char_traits<char16_t>::compare(NULL, NULL, 0) == 0);

    assert(std::char_traits<char16_t>::compare(u"1", u"1", 1) == 0);
    assert(std::char_traits<char16_t>::compare(u"1", u"2", 1) < 0);
    assert(std::char_traits<char16_t>::compare(u"2", u"1", 1) > 0);

    assert(std::char_traits<char16_t>::compare(u"12", u"12", 2) == 0);
    assert(std::char_traits<char16_t>::compare(u"12", u"13", 2) < 0);
    assert(std::char_traits<char16_t>::compare(u"12", u"22", 2) < 0);
    assert(std::char_traits<char16_t>::compare(u"13", u"12", 2) > 0);
    assert(std::char_traits<char16_t>::compare(u"22", u"12", 2) > 0);

    assert(std::char_traits<char16_t>::compare(u"123", u"123", 3) == 0);
    assert(std::char_traits<char16_t>::compare(u"123", u"223", 3) < 0);
    assert(std::char_traits<char16_t>::compare(u"123", u"133", 3) < 0);
    assert(std::char_traits<char16_t>::compare(u"123", u"124", 3) < 0);
    assert(std::char_traits<char16_t>::compare(u"223", u"123", 3) > 0);
    assert(std::char_traits<char16_t>::compare(u"133", u"123", 3) > 0);
    assert(std::char_traits<char16_t>::compare(u"124", u"123", 3) > 0);
#endif

#if TEST_STD_VER > 14
    static_assert(test_constexpr(), "" );
#endif
#endif  // _LIBCPP_HAS_NO_UNICODE_CHARS
}
