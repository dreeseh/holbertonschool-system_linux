#!/bin/bash
#sends the signal SIGQUIT to a process, given its PID

if [ "$#" -ne 1 ]
then
    echo "Usage: $0 <pid>"
    exit 1
else
    kill -QUIT $1
fi