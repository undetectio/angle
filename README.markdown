# Forked ANGLE that allows spoofed information

### Usage
The following environment variables are available:
* `ANGLE_VENDOR`
* `ANGLE_RENDERER`
* `ANGLE_VERSION`
* `ANGLE_SHADING_VERSION`

### Syncing the repo

This build is following the latest Chrome stable release on Win64. To sync with upstream, run:
```bash
BRANCH=$(curl https://omahaproxy.appspot.com/all.json | jq '.[] | select(.os == "win64") | .versions[] | select(.channel == "stable") | .true_branch' -r)
git fetch upstream
git merge upstream/chromium/$BRANCH
```