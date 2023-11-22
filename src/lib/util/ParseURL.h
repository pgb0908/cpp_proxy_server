/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <glog/logging.h>
#include <boost/optional.hpp>
#include <boost/utility/string_view.hpp>
#include <boost/variant.hpp>
#include <boost/optional.hpp>
#include <string>
#include <sstream>
#include <boost/outcome.hpp>
#include <variant>

namespace myproxy {

// ParseURL can handle non-fully-formed URLs. This class must not persist beyond
// the lifetime of the buffer underlying the input StringPiece

class ParseURL {
 public:
  /* Parse a URL.  If parsing succeeds, return a fully formed ParseURL with
   * valid() == true.  If parsing fails, returns nothing. If you need the
   * partial parse results, use parseURLMaybeInvalid below.
   */
/*  static folly::Expected<ParseURL, folly::Unit> parseURL(
      std::string urlVal, bool strict = false) noexcept {
    ParseURL parseUrl(urlVal, strict);
    if (parseUrl.valid()) {
      return parseUrl;
    } else {
      return folly::makeUnexpected(folly::Unit());
    }
  }*/
    static boost::optional<ParseURL> parseURL(
          std::string urlVal, bool strict = false
          ) noexcept {
      ParseURL parseUrl(urlVal, strict);

      if (parseUrl.valid()) {
          return parseUrl;
      } else {
          return boost::none;
      }
  }



  /* Parse a URL.  Returns a ParseURL object that may or may not be valid.
   * Caller should check valid()
   */
  static ParseURL parseURLMaybeInvalid(std::string urlVal,
                                       bool strict = false) noexcept {
    return ParseURL(urlVal, strict);
  }

  // Deprecated.  Will be removed soon
  explicit ParseURL(std::string urlVal, bool strict = true) noexcept {
    init(urlVal, strict);
  }

  ParseURL(ParseURL&& goner)
      : url_(goner.url_),
        scheme_(goner.scheme_),
        path_(goner.path_),
        query_(goner.query_),
        fragment_(goner.fragment_),
        port_(goner.port_),
        valid_(goner.valid_),
        initialized_(goner.initialized_) {
    moveHostAndAuthority(std::move(goner));
  }

  ParseURL& operator=(ParseURL&& goner) {
    url_ = goner.url_;
    scheme_ = goner.scheme_;
    path_ = goner.path_;
    query_ = goner.query_;
    fragment_ = goner.fragment_;
    port_ = goner.port_;
    valid_ = goner.valid_;
    initialized_ = goner.initialized_;
    moveHostAndAuthority(std::move(goner));
    return *this;
  }

  ParseURL& operator=(const ParseURL&) = delete;
  ParseURL(const ParseURL&) = delete;

  ParseURL() = default;

  void init(std::string urlVal, bool strict = false) {
    CHECK(!initialized_);
    url_ = urlVal;
    parse(strict);
    initialized_ = true;
  }

  operator bool() const {
    return valid();
  }

    boost::string_view url() const {
    return url_;
  }

    boost::string_view  scheme() const {
    return scheme_;
  }

  std::string authority() const {
    return authority_;
  }

  bool hasHost() const {
    return valid() && !host_.empty();
  }

    boost::string_view host() const {
    return host_;
  }

  uint16_t port() const {
    return port_;
  }



    std::string hostAndPort() const {
        std::string rc(host_.data(), host_.length());
        if (port_ != 0) {
            rc+= ":";
            rc += port_;

        }
        return rc;
    }

    boost::string_view  path() const {
    return path_;
  }

    boost::string_view query() const {
    return query_;
  }

    boost::string_view fragment() const {
    return fragment_;
  }

  bool valid() const {
    return valid_;
  }

    boost::string_view hostNoBrackets() {
    stripBrackets();
    return hostNoBrackets_;
  }

  bool hostIsIPAddress();

  void stripBrackets() noexcept;

 boost::optional<std::string> getQueryParam(
      std::string name) const noexcept;

 private:
  void moveHostAndAuthority(ParseURL&& goner) {
    if (!valid_) {
      return;
    }
    int64_t hostOff = -1;
    int64_t hostNoBracketsOff = -1;
/*    if (goner.host_.empty() || (goner.host_.data() >= goner.url_.data() &&
                                goner.host_.data() < goner.url_.end())) {
      // relative url_
      host_ = goner.host_;
    } else {
      // relative authority_
      hostOff = goner.host_.data() - goner.authority_.data();
    }*/
/*    if (goner.hostNoBrackets_.empty() ||
        (goner.hostNoBrackets_.data() >= goner.url_.data() &&
         goner.hostNoBrackets_.data() < goner.url_.end())) {
      // relative url_
      hostNoBrackets_ = goner.hostNoBrackets_;
    } else {
      // relative authority_
      hostNoBracketsOff =
          goner.hostNoBrackets_.data() - goner.authority_.data();
    }*/
    authority_ = std::move(goner.authority_);
/*    if (hostOff >= 0) {
      host_.substr(authority_.data() + hostOff, goner.host_.size());
    }
    if (hostNoBracketsOff >= 0) {
      hostNoBrackets_.reset(authority_.data() + hostNoBracketsOff,
                            goner.hostNoBrackets_.size());
    }*/
  }

  void parse(bool strict) noexcept;

  void parseNonFully(bool strict) noexcept;

  bool parseAuthority() noexcept;

    boost::string_view url_;
    boost::string_view scheme_;
    std::string authority_;
    boost::string_view host_;
    boost::string_view  hostNoBrackets_;
    boost::string_view path_;
    boost::string_view query_;
    boost::string_view  fragment_;
    uint16_t port_{0};
    bool valid_{false};
    bool initialized_{false};
};

} // namespace proxygen
