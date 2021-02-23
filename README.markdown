# Forked ANGLE that allows spoofed information

### Environment variables
The following environment variables are available:
* `ANGLE_VENDOR`
* `ANGLE_RENDERER`
* `ANGLE_VERSION`
* `ANGLE_SHADING_VERSION`

### Usage in Linux
```bash
unzip libs-linux.zip -d /opt/google/chrome
google-chrome --use-gl=angle
```

### Usage in macOS
```bash
unzip -o libs-macos.zip -d /Applications/Google\ Chrome.app/Contents/Frameworks/Google\ Chrome\ Framework.framework/Libraries/
xattr -cr /Applications/Google\ Chrome.app
codesign -f -s - --deep /Applications/Google\ Chrome.app/
/Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --use-gl=angle
```

### Syncing the repo

This build is following the latest Chrome stable release on Win64. To sync with upstream, run:
```bash
BRANCH=$(curl https://omahaproxy.appspot.com/all.json | jq '.[] | select(.os == "win64") | .versions[] | select(.channel == "stable") | .true_branch' -r)
git fetch upstream
git merge upstream/chromium/$BRANCH
```