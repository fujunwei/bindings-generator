    $current_class.namespaced_class_name* getCocos2dImpl();
    virtual void setCocos2dImpl($(current_class.namespaced_class_name)* impl);
    ##void setCocos2dImpl(cocos2d::$(current_class.target_class_name) impl);
    ~$(current_class.target_class_name)();
## #if len($current_class.parents) == 0
## protected:
##    cocos2d::$current_class.target_class_name* m_cocos2d_impl;
## #end if
public:
    $(current_class.target_class_name) ();
};

#if len($current_class.parents) != 0
#for $parent in $current_class.parents
	#set $parent_name = parent.target_class_name
DEFINE_TYPE_CASTS($(current_class.target_class_name), $parent_name, p$(current_class.target_class_name), true, true);
	#break
#end for
#else
DEFINE_TYPE_CASTS($(current_class.target_class_name), CCObject, p$(current_class.target_class_name), true, true);
#end if

} // namespace blink

#endif
