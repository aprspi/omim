#pragma once

#include "../std/stdint.hpp"
#include "../std/string.hpp"
#include "../std/ctime.hpp"


namespace my
{

/// Cross platform timer
class Timer
{
  double m_startTime;

public:
  Timer();

  /// @return current UTC time in seconds, elapsed from 1970.
  static double LocalTime();
  /// @return Elapsed time in seconds from start (@see Reset).
  double ElapsedSeconds() const;
  void Reset();
};

string FormatCurrentTime();
uint32_t TodayAsYYMMDD();

/// Always creates strings in UTC time: 1997-07-16T07:30:15Z
/// Returns empty string on error
string TimestampToString(time_t time);

time_t const INVALID_TIME_STAMP = -1;

/// Accepts strings in UTC format: 1997-07-16T07:30:15Z
/// And with custom time offset:   1997-07-16T10:30:15+03:00
/// @return INVALID_TIME_STAMP if string is invalid
time_t StringToTimestamp(string const & s);

}
