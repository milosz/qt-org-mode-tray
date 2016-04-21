#!/bin/sh
# Use org-protocol to add new idea entry
# params: title source description

(lsof -c emacs 2>/dev/null | grep -q server) || (emacs --daemon 2>/dev/null)

if [ "$#" -eq 3 ]; then
  emacsclient "org-protocol://capture://i/$1/$2/$3"
fi
