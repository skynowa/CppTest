#!/usr/bin/env bash
#
#


T=$(mktemp); (cat .gitignore; find . -executable -type f | sed -e 's%^\./%%') | sort | uniq >$T; mv $T .gitignore
