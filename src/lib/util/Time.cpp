/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "Time.h"

#include <openssl/ossl_typ.h>
#include <openssl/bio.h>
#include <openssl/asn1.h>

namespace proxygen {

std::string getDateTimeStr(const ASN1_TIME* const time) {
  if (!time) {
    return "";
  }

  constexpr auto bufSize = 32;
  char buf[bufSize] = {0};

  auto bio = BIO_new(BIO_s_mem());
  if (!bio) {
    return "";
  }

  ASN1_TIME_print(bio, time);
  const auto readResult = BIO_read(bio, buf, bufSize - 1);
  BIO_free(bio);

  return ((readResult <= 0) ? "" : std::string(buf));
}
} // namespace proxygen
