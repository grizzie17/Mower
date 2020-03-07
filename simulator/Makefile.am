AM_CPPFLAGS += \
		-I$(top_srcdir)/base-station \
		-I$(top_srcdir)/display \
		-I$(top_srcdir)/environment \
		-I$(top_srcdir)/mower \
		-I$(top_srcdir)/utilties
AM_CXXFLAGS += -fPIC


lib_LTLIBRARIES = libsimulator.la

libsimulator_la_SOURCES = Simulator.cpp

libsimulator_la_CXXFLAGS = $(CXXFLAGS) $(AM_CXXFLAGS)
libsimulator_la_CPPFLAGS = $(CPPFLAGS) $(AM_CPPFLAGS)
