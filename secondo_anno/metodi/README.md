# Useful github commands

### Three categories of file:
1. Untracked files
1. Unstaged files
1. Staged

### Reset one of the above:
1. ``git clean -f`` - Removes Unstaged UnTracked files ONLY [Type 1]
1. ``git checkout .`` - Removes Unstaged Tracked files ONLY [Type 2]
1. ``git reset --hard`` - Removes Staged Tracked and UnStaged Tracked files 
ONLY[Type 2, Type 3]
1. ``git stash -u`` - Removes all changes [Type 1, Type 2, Type 3]

``git commit --amend [--no-edit]`` - Adds the staged file into the last commit [without changing the message]
