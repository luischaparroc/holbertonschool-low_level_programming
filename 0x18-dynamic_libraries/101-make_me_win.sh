#!/bin/bash
wget -P /tmp/ https://raw.github.com/luischaparroc/holbertonschool-low_level_programming/master/0x18-dynamic_libraries/random.so
export LD_PRELOAD=/tmp/random.so
