Store the patch files here used for hacking core modules.

AFTER EACH CORE -or- CORE MODULE UPDATE YOU SHOULD CHECK WHETHER ANY OF THESE 
PATCHES NEED TO BE APPLIED AGAIN.

USAGE:
1. `cd` to the root of your git repo 
2. run `git apply hacks/<patchfile>`


CREATION:

[!] Before making the changes to the core module:
1. create and checkout a new branch // DO NOT SKIP THIS STEP. P.S. will refer to this branch as the 'patching branch'
2. make the necessary changes to the core module
3. add and commit those changes
4. run `git format-patch <BRANCH_YOU_WANT_TO_COMPARE_WITH>`

[!] `git format-patch` will compare the commits in the patching branch with BRANCH_YOU_WANT_TO_COMPARE_WITH and will create a .patch file for each commit that differs between the two branches [!]
(Read the last sentence again, it's important)

The patch file(s) will be saved into the root, move it/them to the `hacks` directory and add and commit it/them.
Now switch back to your working branch and merge it with the patching branch.
