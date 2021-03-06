#!/bin/bash
# Copyright 2021 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

set -eux

revision=9a84af84d3fa62b230569cf1d3abf69cc7c576e2

cd $(dirname $0)

rm -rf logdog
git clone https://chromium.googlesource.com/infra/luci/luci-py/client/libs/logdog
(
    cd logdog
    git checkout $revision

    # remove unnecessary files.
    rm -rf .git tests
)

cat <<EOF > README.chromium
Name: logdog
Short Name: logdog
URL: https://chromium.googlesource.com/infra/luci/luci-py/client/libs/logdog
Version: $revision
Revision: $revision
License: Apache 2.0
License File: NOT_SHIPPED
Security Critical: no

Description:
This is used from build/android/pylib/utils/logdog_helper.py

Local Modifications:
See get.sh and this files is also generated by the script.

EOF
