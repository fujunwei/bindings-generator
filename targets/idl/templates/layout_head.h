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
\#include "wtf/text/WTFString.h"
\#include "modules/three/three.hpp"
\#include <memory>

namespace three {
    class $(current_class.target_class_name);
}

namespace blink {

class $(current_class.target_class_name) : public RefCountedWillBeGarbageCollectedFinalized <$(current_class.target_class_name)>, public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();
public:
    static PassRefPtrWillBeRawPtr<$(current_class.target_class_name)> create();
    $(current_class.target_class_name)();
#for $name, $impl in $current_class.methods.iteritems()
    #if name == 'constructor'
		#if len($impl.implementations) == 0
		    #set $func2 = $impl
		    #set $func2.arguments = $impl.arguments
		    #set $func2.ret_type = $impl.ret_type
		    #set $func2.static = $impl.static
		    $impl.implementations.append($func2)
		#end if
        #set skip = False
		#for $func in $impl.implementations
			#set $arguments = $func.arguments
			#set $ret_type = $func.ret_type
			#set arglist = ''
			#set $length = len($arguments)
			#set $index = 0
			#if len($arguments) == 0
			    #continue
			#end if
		    #if $skip == True
		        #break
            #end if
			#for $arg in $arguments
			    #if 'glm' in $arg.namespace_name
			        #set $skip = True
			        #break
			    #end if
			    #set $arg_wrapper =  $arg.to_webcore_native($current_class.generator)
			    #if 'Uint8Array' in $arg_wrapper
			        #set $skip = True
			        #continue
			    #end if
			    #if $current_class.generator.in_listed_extend_classed($arg_wrapper)
			        #set $arg_wrapper = 'ScriptValue&'
			    #end if
			    #set $arglist = $arglist + $arg_wrapper
			    #set $arglist = $arglist + ' arg' + str(index)
			    #if $index < $length - 1 
			        #set $arglist = $arglist + ', '
			    #end if
			    #set $index = $index + 1
			#end for
		    #if $skip == False
    static PassRefPtrWillBeRawPtr<$(current_class.target_class_name)> create($arglist);
    $(current_class.target_class_name)($arglist);
            #end if
            #set $skip = True
		#end for
    #end if
#end for
