/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

// clang-format off
#pragma once

#include <cstdint>
#include <string>


namespace proxygen {

/**
 * Codes (hashes)
 */
enum HTTPHeaderCode : uint8_t {
  // Code reserved to indicate the absence of a valid field.
  HTTP_HEADER_NONE = 0,
  // Code reserved to indicate a value for which there is no perfect mapping to
  // a unique field (i.e. the default field for all other values).
  HTTP_HEADER_OTHER = 1,

  /* The following is a placeholder for the build script to generate a list
   * of enum values.
   * Note am currently unable to prevent this comment from being present in the
   * output file.
   */
  HTTP_HEADER_CROSS_ORIGIN_EMBEDDER_POLICY_REPORT_ONLY = 77,
  HTTP_HEADER_PROXY_AUTHORIZATION = 49,
  HTTP_HEADER_EDGE_CONTROL = 35,
  HTTP_HEADER_ORIGIN_TRIAL = 82,
  HTTP_HEADER_COLON_PATH = 4,
  HTTP_HEADER_LINK = 43,
  HTTP_HEADER_CONTENT_RANGE = 30,
  HTTP_HEADER_ACCEPT_LANGUAGE = 11,
  HTTP_HEADER_X_THRIFT_PROTOCOL = 72,
  HTTP_HEADER_REFERER = 53,
  HTTP_HEADER_CONTENT_LANGUAGE = 28,
  HTTP_HEADER_ACCEPT_CHARSET = 9,
  HTTP_HEADER_VARY = 65,
  HTTP_HEADER_COOKIE = 32,
  HTTP_HEADER_REPORT_TO = 85,
  HTTP_HEADER_COLON_STATUS = 7,
  HTTP_HEADER_CROSS_ORIGIN_RESOURCE_POLICY = 79,
  HTTP_HEADER_TE = 60,
  HTTP_HEADER_ACCESS_CONTROL_ALLOW_ORIGIN = 16,
  HTTP_HEADER_X_XSS_PROTECTION = 73,
  HTTP_HEADER_USER_AGENT = 64,
  HTTP_HEADER_IF_MODIFIED_SINCE = 39,
  HTTP_HEADER_PRIORITY = 47,
  HTTP_HEADER_DATE = 33,
  HTTP_HEADER_TIMING_ALLOW_ORIGIN = 88,
  HTTP_HEADER_COLON_SCHEME = 6,
  HTTP_HEADER_X_FORWARDED_PROTO = 70,
  HTTP_HEADER_SERVER = 57,
  HTTP_HEADER_CACHE_CONTROL = 24,
  HTTP_HEADER_CROSS_ORIGIN_OPENER_POLICY = 78,
  HTTP_HEADER_EXPECT = 36,
  HTTP_HEADER_FACEBOOK_API_VERSION = 81,
  HTTP_HEADER_COLON_METHOD = 3,
  HTTP_HEADER_LAST_MODIFIED = 42,
  HTTP_HEADER_CONTENT_LENGTH = 29,
  HTTP_HEADER_ACCEPT_RANGES = 12,
  HTTP_HEADER_RETRY_AFTER = 54,
  HTTP_HEADER_CONTENT_ENCODING = 27,
  HTTP_HEADER_X_CONTENT_TYPE_OPTIONS = 68,
  HTTP_HEADER_EXPIRES = 37,
  HTTP_HEADER_QUEUE_TIMEOUT = 84,
  HTTP_HEADER_COLON_AUTHORITY = 2,
  HTTP_HEADER_DOCUMENT_POLICY = 80,
  HTTP_HEADER_ACCESS_CONTROL_EXPOSE_HEADERS = 17,
  HTTP_HEADER_CLIENT_TIMEOUT = 74,
  HTTP_HEADER_PROXY_STATUS = 51,
  HTTP_HEADER_CONTENT_DISPOSITION = 26,
  HTTP_HEADER_UPGRADE = 63,
  HTTP_HEADER_IF_NONE_MATCH = 40,
  HTTP_HEADER_PRAGMA = 46,
  HTTP_HEADER_ETAG = 34,
  HTTP_HEADER_THRIFT_PRIORITY = 87,
  HTTP_HEADER_COLON_PROTOCOL = 5,
  HTTP_HEADER_X_FORWARDED_FOR = 69,
  HTTP_HEADER_SET_COOKIE = 58,
  HTTP_HEADER_AUTHORIZATION = 23,
  HTTP_HEADER_CONTENT_DIGEST = 75,
  HTTP_HEADER_TRANSFER_ENCODING = 62,
  HTTP_HEADER_KEEP_ALIVE = 41,
  HTTP_HEADER_ACCESS_CONTROL_ALLOW_CREDENTIALS = 13,
  HTTP_HEADER_SEC_WEBSOCKET_ACCEPT = 55,
  HTTP_HEADER_ALT_SVC = 22,
  HTTP_HEADER_ACCESS_CONTROL_REQUEST_HEADERS = 19,
  HTTP_HEADER_WWW_AUTHENTICATE = 67,
  HTTP_HEADER_PROXY_CONNECTION = 50,
  HTTP_HEADER_HOST = 38,
  HTTP_HEADER_PERMISSIONS_POLICY = 83,
  HTTP_HEADER_LOCATION = 44,
  HTTP_HEADER_ACCESS_CONTROL_MAX_AGE = 18,
  HTTP_HEADER_X_FRAME_OPTIONS = 71,
  HTTP_HEADER_RANGE = 52,
  HTTP_HEADER_CONNECTION = 25,
  HTTP_HEADER_ACCEPT_ENCODING = 10,
  HTTP_HEADER_VIA = 66,
  HTTP_HEADER_ORIGIN = 45,
  HTTP_HEADER_CONTENT_TYPE = 31,
  HTTP_HEADER_RPCKIND = 86,
  HTTP_HEADER_ACCEPT = 8,
  HTTP_HEADER_STRICT_TRANSPORT_SECURITY = 59,
  HTTP_HEADER_ACCESS_CONTROL_ALLOW_METHODS = 15,
  HTTP_HEADER_CONTENT_SECURITY_POLICY = 76,
  HTTP_HEADER_TRAILER = 61,
  HTTP_HEADER_PROXY_AUTHENTICATE = 48,
  HTTP_HEADER_ACCESS_CONTROL_ALLOW_HEADERS = 14,
  HTTP_HEADER_SEC_WEBSOCKET_KEY = 56,
  HTTP_HEADER_AGE = 21,
  HTTP_HEADER_ACCESS_CONTROL_REQUEST_METHOD = 20,

};

const uint8_t HTTPHeaderCodeCommonOffset = 2;

enum class HTTPCommonHeaderTableType: uint8_t {
  TABLE_CAMELCASE = 0,
  TABLE_LOWERCASE = 1,
};

class HTTPCommonHeaders {
 public:
  // Perfect hash function to match specified names
  static HTTPHeaderCode hash(const char* name, size_t len);

  inline static HTTPHeaderCode hash(const std::string& name) {
    return hash(name.data(), name.length());
  }

  static std::string* initNames(HTTPCommonHeaderTableType type);

  /* The following is a placeholder for the build script to generate a field
   * that stores the max number of defined enum fields.
   i.e. constexpr static uint64_t num_codes;
   * Note am currently unable to prevent this comment from being present in the
   * output file.
   */
  constexpr static uint64_t num_codes = 89;

  static const std::string* getPointerToTable(
    HTTPCommonHeaderTableType type);

  inline static const std::string* getPointerToName(HTTPHeaderCode code,
      HTTPCommonHeaderTableType type = HTTPCommonHeaderTableType::TABLE_CAMELCASE) {
    return getPointerToTable(type) + code;
  }

  inline static bool isNameFromTable(const std::string* headerName,
      HTTPCommonHeaderTableType type) {
    return getCodeFromTableName(headerName, type) >=
      HTTPHeaderCodeCommonOffset;
  }

  // This method supplements hash().  If dealing with string pointers, some
  // pointing to entries in the the name table and some not, this
  // method can be used in place of hash to reverse map a string from the
  // name table to its code.
  inline static HTTPHeaderCode getCodeFromTableName(
      const std::string* headerName, HTTPCommonHeaderTableType type) {
    if (headerName == nullptr) {
      return HTTP_HEADER_NONE;
    } else {
      auto diff = headerName - getPointerToTable(type);
      if (diff >= HTTPHeaderCodeCommonOffset && diff < (long)num_codes) {
        return static_cast<HTTPHeaderCode>(diff);
      } else {
        return HTTP_HEADER_OTHER;
      }
    }
  }

};

} // proxygen
// clang-format on
