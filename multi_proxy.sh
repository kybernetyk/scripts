#!/bin/bash

ssh -t -L 8887:localhost:8886 root@superking.org ssh -t -L 8886:localhost:8885 root@funblog.me ssh -t -g -D 8885 root@superking.org


#ssh -t -L 8887:localhost:8887 root@superking.org ssh -t -D 8887 root@funblog.me

#ssh -g -D 8887 root@funblog.me
