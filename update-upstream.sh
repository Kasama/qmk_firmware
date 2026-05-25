#/bin/bash

git pull upstream master --recurse-submodules
git reset keyboards
git status
