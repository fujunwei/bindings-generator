// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

\#ifndef __$(current_class.target_class_name)_h__
\#define __$(current_class.target_class_name)_h__

\#include "bindings/core/v8/ScriptWrappable.h"
\#include "platform/heap/Handle.h"
\#include "wtf/Forward.h"
\#include "wtf/RefCounted.h"
\#include "wtf/RefPtr.h"
\#include "wtf/Uint8Array.h"

##//#include "modules/cocos2d/cocos2d.hpp"

\#include "modules/cocos2d/cocos2d_class.hpp"
#set namespace = $current_class.namespace_name
#if $namespace == "cocos2d::"
namespace cocos2d {
    class $(current_class.target_class_name);
}
#else
namespace cocos2d {
    namespace extension {
        class $(current_class.target_class_name);
    }
}
#end if

namespace blink {

#if len($current_class.parents) == 0
##class $(current_class.target_class_name) : public RefCountedWillBeGarbageCollectedFinalized <$(current_class.target_class_name)>, public ScriptWrappable {
class $(current_class.target_class_name) : public CCObject {
#else
class $(current_class.target_class_name) 
#for $parent in $current_class.parents
	#set $parent_name = parent.target_class_name
		:public $parent_name
	#break
#end for
{
#end if
    DEFINE_WRAPPERTYPEINFO();
public:
    void trace(Visitor*) {}
    static PassRefPtrWillBeRawPtr<$(current_class.target_class_name)> create();
