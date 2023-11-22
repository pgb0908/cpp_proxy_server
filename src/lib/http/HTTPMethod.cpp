/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "HTTPMethod.h"
#include <ostream>
#include "HTTPHeaders.h"
#include <vector>
#include <boost/serialization/singleton.hpp>

#define HTTP_METHOD_STR(method) #method

namespace {

// Method strings. This is indestructible because this structure is
// accessed from multiple threads and still needs to be accessible after exit()
// is called to avoid crashing.
using StringVector = std::vector<std::string>;

const StringVector& getMethodStrings() {
  static const StringVector methodStrings{
      StringVector{"GET",
                   "POST",
                   "OPTIONS",
                   "DELETE",
                   "HEAD",
                   "CONNECT",
                   "CONNECT-UDP",
                   "PUT",
                   "TRACE",
                   "PATCH",
                   "SUB",
                   "PUB",
                   "UNSUB"}};
  return methodStrings;
}

} // namespace

namespace myproxy {

boost::optional<HTTPMethod> stringToMethod(std::string method) {
  const auto& strings = getMethodStrings();
  for (size_t index = 0; index < strings.size(); ++index) {
    const auto& cur = strings[index];
    if (caseInsensitiveEqual(cur, method)) {
      return HTTPMethod(index);
    }
  }
  return boost::none;
}

const std::string& methodToString(HTTPMethod method) {
  return getMethodStrings()[static_cast<unsigned>(method)];
}

std::ostream& operator<<(std::ostream& out, HTTPMethod method) {
  out << methodToString(method);
  return out;
}

} // namespace proxygen
