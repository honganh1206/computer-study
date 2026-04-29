#!/bin/bash

# Simple text file whre each line is a key-value pair
db_set() {
  echo "$1,$2" >>database
}

# Old versions of a key are not overwritten, we only append
# hence the tail command to look for the latest occurence of the key
db_get() {
  grep "^$1," database | sed -e "s/^$1,//" | tail -n 1
}

# Turn functions into commands
case "$1" in
set)
  db_set "$2" "$3"
  ;;
get)
  db_get "$2"
  ;;
*)
  echo "Usage $0 {set key value | get key}"
  ;;
esac
