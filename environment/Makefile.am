AM_CPPFLAGS += \
		-I$(top_srcdir)/display \
		-I$(top_srcdir)/utilties
AM_CXXFLAGS += -fPIC


lib_LTLIBRARIES = libenvironment.la

libenvironment_la_SOURCES = Environment.cpp

libenvironment_la_CXXFLAGS = $(CXXFLAGS) $(AM_CXXFLAGS)
libenvironment_la_CPPFLAGS = $(CPPFLAGS) $(AM_CPPFLAGS)
