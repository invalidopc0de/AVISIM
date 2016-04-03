AUTOMAKE_OPTIONS = foreign subdir-objects
bin_PROGRAMS = avisim

AM_CXXFLAGS = $(INIT_CFLAGS)

avisim_SOURCES = avisim.c devicelib.c alg_deployment1.c cJSON/cJSON.c
avisim_LDADD = $(INIT_LIBS) -lm
