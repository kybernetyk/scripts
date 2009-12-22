#!/bin/bash

ssh -t -L 8887:localhost:8887 root@superking.org ssh -t -g -D 8887 root@funblog.me

#ssh -g -D 8887 root@funblog.me
