/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <string>
#include <boost/algorithm/string.hpp>


#ifndef NDEBUG
#define EXPECT_DEATH_NO_CORE(token, regex) \
  {                                        \
    rlimit oldLim;                         \
    getrlimit(RLIMIT_CORE, &oldLim);       \
    rlimit newLim{0, oldLim.rlim_max};     \
    setrlimit(RLIMIT_CORE, &newLim);       \
    EXPECT_DEATH(token, regex);            \
    setrlimit(RLIMIT_CORE, &oldLim);       \
  }
#else
#define EXPECT_DEATH_NO_CORE(tken, regex) \
  {}
#endif

inline std::string getContainingDirectory(std::string input) {
/*  auto pos = boost::algorithm::find_last(input, "/");
  if (pos == pos.end()) {
    pos = 0;
  } else {
    pos += 1;
  }
  return input.substr(0, pos);*/
    return "";
}
