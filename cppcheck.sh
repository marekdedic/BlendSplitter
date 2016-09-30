#!/bin/bash

cppcheck -I. --enable=warning,style,performance,portability,information,missingInclude --suppress=missingIncludeSystem src 2> CppCheckResults.txt
