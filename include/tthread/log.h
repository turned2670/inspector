#pragma once

/*
 * @file   tthread/log.h
 * @brief  Read logged memory events
 */

#include <sys/types.h>

#include "tthread/logevent.h"
#include "tthread/logheader.h"
#include "visibility.h"


namespace tthread {
class _PUBLIC_ log {
private:

  void openLog(int logFd);

  const off_t _logOffset;
  size_t _logSize;
  logheader *_header;
  logevent *_log;
  log(const log& l);
  logheader *readHeader(int logFd);

public:

  // include all events logged at the time of construction
  log();
  log(off_t offset);
  log(int logFd);
  log(int   logFd,
      off_t offset);
  ~log();

  // open custom log from file handle
  log(int   logFd,
      off_t size,
      off_t offset);

  size_t length() const;

  off_t end() {
    return _logSize;
  }

  logevent get(unsigned long i);
  void print() const;
};
}
