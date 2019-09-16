#!/bin/bash
mv random.so $HOME
export LD_PRELOAD=$HOME/random.so
