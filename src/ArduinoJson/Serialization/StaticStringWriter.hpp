// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2019
// MIT License

#pragma once

namespace ARDUINOJSON_NAMESPACE {

// A Print implementation that allows to write in a char[]
class StaticStringWriter {
 public:
  StaticStringWriter(char *buf, size_t size) : end(buf + size - 1), p(buf) {
    *p = '\0';
  }

  size_t write(uint8_t c) {
    if (p >= end) return 0;
    *p++ = static_cast<char>(c);
    *p = '\0';
    return 1;
  }

  size_t write(const uint8_t *s, size_t n) {
    size_t avail = size_t(end - p);
    if (avail < n) {
      n = avail;
    }
    memcpy(p, s, n);
    p += n;
    *p = '\0';
    return n;
  }

 private:
  char *end;
  char *p;
};
}  // namespace ARDUINOJSON_NAMESPACE
