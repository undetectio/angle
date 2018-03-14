//
// Copyright (c) 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// PruneEmptyCases.h: The PruneEmptyCases function prunes cases that are followed by nothing from
// the AST.

#ifndef COMPILER_TRANSLATOR_PRUNEEMPTYCASES_H_
#define COMPILER_TRANSLATOR_PRUNEEMPTYCASES_H_

namespace sh
{
class TIntermBlock;

void PruneEmptyCases(TIntermBlock *root);
}  // namespace sh

#endif  // COMPILER_TRANSLATOR_PRUNEEMPTYCASES_H_
