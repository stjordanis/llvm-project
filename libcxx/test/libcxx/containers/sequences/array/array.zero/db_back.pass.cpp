//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// UNSUPPORTED: c++98, c++03
// UNSUPPORTED: windows

// MODULES_DEFINES: _LIBCPP_DEBUG=1

// Can't test the system lib because this test enables debug mode
// UNSUPPORTED: with_system_cxx_lib

// test array<T, 0>::front() raises a debug error.

#define _LIBCPP_DEBUG 1
#include <array>
#include "debug_mode_helper.h"

int main(int, char**)
{
  {
    typedef std::array<int, 0> C;
    C c = {};
    C const& cc = c;
    EXPECT_DEATH( c.back() );
    EXPECT_DEATH( cc.back() );
  }
  {
    typedef std::array<const int, 0> C;
    C c = {{}};
    C const& cc = c;
    EXPECT_DEATH( c.back() );
    EXPECT_DEATH( cc.back() );
  }

  return 0;
}
