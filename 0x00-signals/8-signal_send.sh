#!/usr/bin/env sh
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <pid>"
    exit 1
fi

kill -QUIT "$1"