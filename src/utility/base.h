// Copyright (c) 2021 zhengzhibing All rights reserved.
#include <cstring>

#ifndef MYTOY_BASE_H
# define MYTOY_BASE_H
# if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#  define OS_WINDOWS
# elif defined(__CYGWIN__) || defined(__CYGWIN32__)
#  define OS_CYGWIN
# elif defined(linux) || defined(__linux) || defined(__linux__)
#  ifndef OS_LINUX
#   define OS_LINUX
#  endif
# elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
#  define OS_MACOSX
# elif defined(__FreeBSD__)
#  define OS_FREEBSD
# elif defined(__NetBSD__)
#  define OS_NETBSD
# elif defined(__OpenBSD__)
#  define OS_OPENBSD
# else
// TODO Add other platforms.
# endif

# define UNUSED(x) \
  do {             \
   (void)(x);      \
  } while (0)

# define __FILENAME__ (std::strrchr(__FILE__, '/') ? (std::strrchr(__FILE__, '/') + 1) : __FILE__)
#endif  // MYTOY_BASE_H
