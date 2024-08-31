## [Git branches](https://www.nobledesktop.com/learn/git/git-branches)

```bash
git branch -a # See all branch
git checkout -b my-branch-name # Create a new branch
git checkout my-branch-name # Switch to a Branch In Your Local Repo

# Switch to a branch from a remote repo
git pull && git checkout --track origin/my-branch-name

git update-index --chmod=+x mydeploy.sh # Add permission
git ls-files --stage # you can check permissons
git commit -m "Executable!"

```