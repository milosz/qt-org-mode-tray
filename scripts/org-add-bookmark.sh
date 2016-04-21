#!/bin/sh
# Use org-protocol to add new bookmark entry
# param: url title description

(lsof -c emacs 2>/dev/null | grep -q server) || (emacs --daemon 2>/dev/null)

if [ "$#" -eq 3 ]; then
  emacsclient "org-protocol://capture://b/$(echo $1 | sed 's|/|%2F|g')/$2/$3"
fi
