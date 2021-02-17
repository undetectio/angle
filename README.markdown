# Forked ANGLE that allows spoofed information

This build is following the latest Chrome stable release on Win64. To sync with upstream, run:
```bash
BRANCH=$(curl https://omahaproxy.appspot.com/all.json | jq '.[] | select(.os == "win64") | .versions[] | select(.channel == "stable") | .true_branch' -r)
git fetch upstream
git merge upstream/chromium/$BRANCH
```