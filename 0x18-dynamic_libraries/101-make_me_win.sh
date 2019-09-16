#!/bin/bash
wget -P /tmp/ https://github.com/luischaparroc/holbertonschool-low_level_programming/blob/master/0x18-dynamic_libraries/random.so?raw=true
export LD_PRELOAD=/tmp/random.so
