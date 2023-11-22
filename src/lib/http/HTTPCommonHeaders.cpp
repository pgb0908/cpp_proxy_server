/* C++ code produced by gperf version 3.1 */
/* Computed positions: -k'3,22,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif


// Copyright 2015-present Facebook.  All rights reserved.

#include "HTTPCommonHeaders.h"
#include <cstring>
#include <glog/logging.h>
#include <cctype>

namespace myproxy {

struct HTTPCommonHeaderName { const char* name; HTTPHeaderCode code; };

// Placeholder for the gen script to insert enum values alongside '%%'
// separators separating declarations, keywords, and functions.
// Note am currently unable to prevent this comment from being present in the
// output file.;
enum
  {
    TOTAL_KEYWORDS = 87,
    MIN_WORD_LENGTH = 2,
    MAX_WORD_LENGTH = 40,
    MIN_HASH_VALUE = 8,
    MAX_HASH_VALUE = 115
  };

/* maximum key range = 108, duplicates = 0 */

#ifndef GPERF_DOWNCASE
#define GPERF_DOWNCASE 1
static unsigned char gperf_downcase[256] =
  {
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,
     15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
     30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
     45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
     60,  61,  62,  63,  64,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106,
    107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121,
    122,  91,  92,  93,  94,  95,  96,  97,  98,  99, 100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134,
    135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
    150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164,
    165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194,
    195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
    210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224,
    225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254,
    255
  };
#endif

#ifndef GPERF_CASE_MEMCMP
#define GPERF_CASE_MEMCMP 1
static int
gperf_case_memcmp (const char *s1, const char *s2, size_t n)
{
  for (; n > 0;)
    {
      unsigned char c1 = gperf_downcase[(unsigned char)*s1++];
      unsigned char c2 = gperf_downcase[(unsigned char)*s2++];
      if (c1 == c2)
        {
          n--;
          continue;
        }
      return (int)c1 - (int)c2;
    }
  return 0;
}
#endif

class HTTPCommonHeadersInternal
{
private:
  static inline unsigned int hash (const char *str, size_t len);
public:
  static const struct HTTPCommonHeaderName *in_word_set (const char *str, size_t len);
};

inline unsigned int
HTTPCommonHeadersInternal::hash (const char *str, size_t len)
{
  static const unsigned char asso_values[] =
    {
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116,   6,  11, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116,  29,  34,  45,   2,  10,
       62,  50,   6, 116,  62,   3,  41,  17,  15,   6,
       30,  77,  22,   5,   2,  48,   4, 116,  10,  34,
      116, 116, 116, 116, 116, 116, 116,  29,  34,  45,
        2,  10,  62,  50,   6, 116,  62,   3,  41,  17,
       15,   6,  30,  77,  22,   5,   2,  48,   4, 116,
       10,  34, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116, 116, 116, 116,
      116, 116, 116, 116, 116, 116, 116
    };
  unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[static_cast<unsigned char>(str[21])];
      case 21:
      case 20:
      case 19:
      case 18:
      case 17:
      case 16:
      case 15:
      case 14:
      case 13:
      case 12:
      case 11:
      case 10:
      case 9:
      case 8:
      case 7:
      case 6:
      case 5:
      case 4:
      case 3:
        hval += asso_values[static_cast<unsigned char>(str[2]+1)];
      case 2:
        break;
    }
  return hval + asso_values[static_cast<unsigned char>(str[len - 1])];
}

static const unsigned char lengthtable[] =
  {
     4,  6,  7,  2,  4, 13, 14,  7, 13,  5, 14,  7, 20,  8,
    14, 15, 12, 13, 13, 10, 16,  6, 22, 29, 16, 20, 17, 30,
    19, 28, 29,  4, 22,  5,  6, 12, 10, 19, 27, 15, 28, 17,
    15,  9, 13, 18, 18, 12,  7, 16,  4,  7, 19, 16,  3, 15,
    10,  6, 15,  7, 16, 17, 10,  3, 13, 13, 14,  7, 11, 10,
     6, 32,  6, 25, 15,  4,  7,  9, 26, 28,  7, 17,  8, 17,
    23, 40, 12
  };

static const struct HTTPCommonHeaderName wordlist[] =
  {
    {"Host", HTTP_HEADER_HOST},
    {"Accept", HTTP_HEADER_ACCEPT},
    {"rpckind", HTTP_HEADER_RPCKIND},
    {"TE", HTTP_HEADER_TE},
    {"Link", HTTP_HEADER_LINK},
    {"Last-Modified", HTTP_HEADER_LAST_MODIFIED},
    {"Accept-Charset", HTTP_HEADER_ACCEPT_CHARSET},
    {":Scheme", HTTP_HEADER_COLON_SCHEME},
    {"Accept-Ranges", HTTP_HEADER_ACCEPT_RANGES},
    {"Range", HTTP_HEADER_RANGE},
    {"content-digest", HTTP_HEADER_CONTENT_DIGEST},
    {"Upgrade", HTTP_HEADER_UPGRADE},
    {"Sec-WebSocket-Accept", HTTP_HEADER_SEC_WEBSOCKET_ACCEPT},
    {"Location", HTTP_HEADER_LOCATION},
    {"Content-Length", HTTP_HEADER_CONTENT_LENGTH},
    {"Accept-Language", HTTP_HEADER_ACCEPT_LANGUAGE},
    {"Content-Type", HTTP_HEADER_CONTENT_TYPE},
    {"Content-Range", HTTP_HEADER_CONTENT_RANGE},
    {"If-None-Match", HTTP_HEADER_IF_NONE_MATCH},
    {"Connection", HTTP_HEADER_CONNECTION},
    {"Content-Language", HTTP_HEADER_CONTENT_LANGUAGE},
    {"Server", HTTP_HEADER_SERVER},
    {"X-Content-Type-Options", HTTP_HEADER_X_CONTENT_TYPE_OPTIONS},
    {"Access-Control-Request-Method", HTTP_HEADER_ACCESS_CONTROL_REQUEST_METHOD},
    {"WWW-Authenticate", HTTP_HEADER_WWW_AUTHENTICATE},
    {"facebook-api-version", HTTP_HEADER_FACEBOOK_API_VERSION},
    {"If-Modified-Since", HTTP_HEADER_IF_MODIFIED_SINCE},
    {"Access-Control-Request-Headers", HTTP_HEADER_ACCESS_CONTROL_REQUEST_HEADERS},
    {"Content-Disposition", HTTP_HEADER_CONTENT_DISPOSITION},
    {"Access-Control-Allow-Headers", HTTP_HEADER_ACCESS_CONTROL_ALLOW_HEADERS},
    {"Access-Control-Expose-Headers", HTTP_HEADER_ACCESS_CONTROL_EXPOSE_HEADERS},
    {"Vary", HTTP_HEADER_VARY},
    {"Access-Control-Max-Age", HTTP_HEADER_ACCESS_CONTROL_MAX_AGE},
    {":Path", HTTP_HEADER_COLON_PATH},
    {"Cookie", HTTP_HEADER_COOKIE},
    {"Proxy-Status", HTTP_HEADER_PROXY_STATUS},
    {":Authority", HTTP_HEADER_COLON_AUTHORITY},
    {"timing-allow-origin", HTTP_HEADER_TIMING_ALLOW_ORIGIN},
    {"Access-Control-Allow-Origin", HTTP_HEADER_ACCESS_CONTROL_ALLOW_ORIGIN},
    {"document-policy", HTTP_HEADER_DOCUMENT_POLICY},
    {"Access-Control-Allow-Methods", HTTP_HEADER_ACCESS_CONTROL_ALLOW_METHODS},
    {"Sec-WebSocket-Key", HTTP_HEADER_SEC_WEBSOCKET_KEY},
    {"thrift_priority", HTTP_HEADER_THRIFT_PRIORITY},
    {":Protocol", HTTP_HEADER_COLON_PROTOCOL},
    {"Cache-Control", HTTP_HEADER_CACHE_CONTROL},
    {"permissions-policy", HTTP_HEADER_PERMISSIONS_POLICY},
    {"Proxy-Authenticate", HTTP_HEADER_PROXY_AUTHENTICATE},
    {"Edge-Control", HTTP_HEADER_EDGE_CONTROL},
    {":Status", HTTP_HEADER_COLON_STATUS},
    {"Proxy-Connection", HTTP_HEADER_PROXY_CONNECTION},
    {"Date", HTTP_HEADER_DATE},
    {"Trailer", HTTP_HEADER_TRAILER},
    {"Proxy-Authorization", HTTP_HEADER_PROXY_AUTHORIZATION},
    {"X-XSS-Protection", HTTP_HEADER_X_XSS_PROTECTION},
    {"Via", HTTP_HEADER_VIA},
    {"Accept-Encoding", HTTP_HEADER_ACCEPT_ENCODING},
    {"Set-Cookie", HTTP_HEADER_SET_COOKIE},
    {"Pragma", HTTP_HEADER_PRAGMA},
    {"X-Frame-Options", HTTP_HEADER_X_FRAME_OPTIONS},
    {":Method", HTTP_HEADER_COLON_METHOD},
    {"Content-Encoding", HTTP_HEADER_CONTENT_ENCODING},
    {"X-Forwarded-Proto", HTTP_HEADER_X_FORWARDED_PROTO},
    {"User-Agent", HTTP_HEADER_USER_AGENT},
    {"Age", HTTP_HEADER_AGE},
    {"Authorization", HTTP_HEADER_AUTHORIZATION},
    {"queue_timeout", HTTP_HEADER_QUEUE_TIMEOUT},
    {"client_timeout", HTTP_HEADER_CLIENT_TIMEOUT},
    {"Referer", HTTP_HEADER_REFERER},
    {"Retry-After", HTTP_HEADER_RETRY_AFTER},
    {"Keep-Alive", HTTP_HEADER_KEEP_ALIVE},
    {"Origin", HTTP_HEADER_ORIGIN},
    {"Access-Control-Allow-Credentials", HTTP_HEADER_ACCESS_CONTROL_ALLOW_CREDENTIALS},
    {"Expect", HTTP_HEADER_EXPECT},
    {"Strict-Transport-Security", HTTP_HEADER_STRICT_TRANSPORT_SECURITY},
    {"X-Forwarded-For", HTTP_HEADER_X_FORWARDED_FOR},
    {"ETag", HTTP_HEADER_ETAG},
    {"Expires", HTTP_HEADER_EXPIRES},
    {"report-to", HTTP_HEADER_REPORT_TO},
    {"cross-origin-opener-policy", HTTP_HEADER_CROSS_ORIGIN_OPENER_POLICY},
    {"cross-origin-resource-policy", HTTP_HEADER_CROSS_ORIGIN_RESOURCE_POLICY},
    {"Alt-Svc", HTTP_HEADER_ALT_SVC},
    {"Transfer-Encoding", HTTP_HEADER_TRANSFER_ENCODING},
    {"Priority", HTTP_HEADER_PRIORITY},
    {"X-Thrift-Protocol", HTTP_HEADER_X_THRIFT_PROTOCOL},
    {"content-security-policy", HTTP_HEADER_CONTENT_SECURITY_POLICY},
    {"cross-origin-embedder-policy-report-only", HTTP_HEADER_CROSS_ORIGIN_EMBEDDER_POLICY_REPORT_ONLY},
    {"origin-trial", HTTP_HEADER_ORIGIN_TRIAL}
  };

static const signed char lookup[] =
  {
    -1, -1, -1, -1, -1, -1, -1, -1,  0, -1,  1,  2,  3,  4,
    -1, -1, -1,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,
    44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
    58, 59, 60, 61, 62, 63, 64, 65, 66, 67, -1, 68, 69, 70,
    71, 72, 73, 74, 75, 76, -1, -1, 77, -1, -1, -1, 78, -1,
    79, -1, 80, 81, -1, -1, 82, -1, 83, -1, 84, -1, 85, -1,
    -1, -1, -1, 86
  };

const struct HTTPCommonHeaderName *
HTTPCommonHeadersInternal::in_word_set (const char *str, size_t len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          int index = lookup[key];

          if (index >= 0)
            {
              if (len == lengthtable[index])
                {
                  const char *s = wordlist[index].name;

                  if ((((unsigned char)*str ^ (unsigned char)*s) & ~32) == 0 && !gperf_case_memcmp (str, s, len))
                    return &wordlist[index];
                }
            }
        }
    }
  return 0;
}


HTTPHeaderCode HTTPCommonHeaders::hash(const char* name, size_t len) {
  const HTTPCommonHeaderName* match =
    HTTPCommonHeadersInternal::in_word_set(name, len);
  return (match == nullptr) ? HTTP_HEADER_OTHER : match->code;
}

std::string* HTTPCommonHeaders::initNames(
    HTTPCommonHeaderTableType type) {
  auto names = new std::string[HTTPCommonHeaders::num_codes];
  const uint8_t OFFSET = 2; // first 2 values are reserved for special cases
  for (uint64_t j = 0; j < HTTPCommonHeaders::num_codes - OFFSET; ++j) {
    uint8_t code = wordlist[j].code;
    DCHECK_EQ(names[code], std::string());
    // this would mean a duplicate code in the .gperf file
    names[code] = wordlist[j].name;
    if (type == HTTPCommonHeaderTableType::TABLE_LOWERCASE) {
        auto old = names[code];
        std::string temp;
        for(auto c : old){
            temp += std::tolower(c);
        }
        names[code] = temp;
      //folly::toLowerAscii(const_cast<char*>(names[code].data()),names[code].size());
    }
  }
  return names;
}

const std::string* HTTPCommonHeaders::getPointerToTable(
    HTTPCommonHeaderTableType type) {
  // The actual  tables are static and initialized here in source
  // so as to prevent duplicate initializations that could occur through the
  // use of inline semantics or compilation unit referencing if defined in a
  // header
  switch(type) {
    case HTTPCommonHeaderTableType::TABLE_CAMELCASE:
      static const std::string* camelcaseTable = initNames(type);
      return camelcaseTable;
    case HTTPCommonHeaderTableType::TABLE_LOWERCASE:
      static const std::string* lowercaseTable = initNames(type);
      return lowercaseTable;
    default:
      // Controlled abort here so its clear from a crash stack this method
      // was called with a table type for which there is no current
      // implementation
      CHECK(false);
      return nullptr;
  }
}

} // proxygen
