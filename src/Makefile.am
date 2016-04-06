AUTOMAKE_OPTIONS = foreign subdir-objects
bin_PROGRAMS = avisim_test

AM_CXXFLAGS = $(INIT_CFLAGS)

avisim_test_SOURCES = avisim_test.c alg_test.c avisim.c devicelib.c  cJSON/cJSON.c
avisim_test_LDADD = $(INIT_LIBS) -lm
