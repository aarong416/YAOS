#ifndef LOGGING_H
#define LGGING_H

class Logger
{
public:
  Logger();

  static void log(const char* s);

private:
  static void writeChar(const char c);
};

#endif
