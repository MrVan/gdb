dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.64)dnl
AC_INIT(Makefile.in)
sinclude(../common/acinclude.m4)

SIM_AC_COMMON

AC_CHECK_HEADERS(stdlib.h)

AC_ARG_WITH([system-readline],
  [AS_HELP_STRING([--with-system-readline],
                  [use installed readline library])])

if test "$with_system_readline" = yes; then
  AC_MSG_CHECKING([for readline])
  save_LIBS="$LIBS"
  LIBS="-lreadline $save_LIBS"
  AC_LINK_IFELSE([AC_LANG_CALL([],
    [add_history])], [READLINE=-lreadline],
    [ LIBS="-lreadline -lncurses $save_LIBS"
      AC_LINK_IFELSE([AC_LANG_CALL([],
        [add_history])], [READLINE="-lreadline -lncurses"],
        [AC_MSG_ERROR([unable to detect readline])])
    ])
  LIBS="$save_LIBS"
  AC_MSG_RESULT($READLINE)
  READLINE_DEPS=
  READLINE_CFLAGS=
else
  READLINE='../../readline/libreadline.a -lncurses'
  READLINE_DEPS='$(READLINE)'
  READLINE_CFLAGS='-I$(READLINE_SRC)/..'
fi
AC_SUBST(READLINE)
AC_SUBST(READLINE_DEPS)
AC_SUBST(READLINE_CFLAGS)

SIM_AC_OUTPUT
