/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "string"


#ifdef STRICT
#undef STRICT
#endif

#ifdef STRICT_COMPAT
#undef STRICT_COMPAT
#endif

namespace myproxy {


/**
 * Check if two ascii characters are case insensitive equal.
 * The difference between the lower/upper case characters are the 6-th bit.
 * We also check they are alpha chars, in case of xor = 32.
 */
struct AsciiCaseInsensitive {
    bool operator()(char lhs, char rhs) const {
        char k = lhs ^ rhs;
        if (k == 0) {
            return true;
        }
        if (k != 32) {
            return false;
        }
        k = lhs | rhs;
        return (k >= 'a' && k <= 'z');
    }
};


    // Case-insensitive string comparison
inline bool caseInsensitiveEqual(std::string s, std::string t) {
  if (s.size() != t.size()) {
    return false;
  }
  return std::equal(
      s.begin(), s.end(), t.begin(), AsciiCaseInsensitive());
}

struct AsciiCaseUnderscoreInsensitive {
  bool operator()(char lhs, char rhs) const {
    if (lhs == '_') {
      lhs = '-';
    }
    if (rhs == '_') {
      rhs = '-';
    }
    return AsciiCaseInsensitive()(lhs, rhs);
  }
};

// Case-insensitive string comparison
inline bool caseUnderscoreInsensitiveEqual(std::string s,
                                           std::string t) {
  if (s.size() != t.size()) {
    return false;
  }
  bool result = std::equal(
      s.begin(), s.end(), t.begin(), AsciiCaseUnderscoreInsensitive());
  return result;
}

enum class URLValidateMode { STRICT_COMPAT, STRICT };
inline bool validateURL(std::string url,
                        URLValidateMode mode = URLValidateMode::STRICT) {
  for (auto p : url) {
    if (p <= 0x20 || p == 0x7f ||
        (p > 0x7f && mode != URLValidateMode::STRICT_COMPAT)) {
      // no controls or unescaped spaces
      return false;
    }
  }
  return true;
}

inline size_t findLastOf(std::string sp, char c) {
  size_t pos = sp.size();
  while (--pos != std::string::npos && sp[pos] != c) {
    // pass
  }
  return pos;
}



} // namespace proxygen
