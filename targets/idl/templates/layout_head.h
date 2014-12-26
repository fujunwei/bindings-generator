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

namespace cocos2d {
    class $(current_class.target_class_name);
}

namespace blink {

#if len($current_class.parents) == 0
class $(current_class.target_class_name) : public RefCountedWillBeGarbageCollectedFinalized <$(current_class.target_class_name)>, public ScriptWrappable {
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
    static PassRefPtrWillBeRawPtr<$(current_class.target_class_name)> create()
    {
        return adoptRefWillBeNoop(new $(current_class.target_class_name)());
    }
