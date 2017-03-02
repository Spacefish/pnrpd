cmake_minimum_required (VERSION 2.8.11)
project(PNRPD)

FILE(GLOB PNRPDSources *.c)
ADD_EXECUTABLE(pnrpd ${PNRPDSources})