    cocos2d::$current_class.target_class_name* $current_class.target_class_name::getCocos2dImpl() {
        return (cocos2d::$current_class.target_class_name*)(m_cocos2d_impl.get());
    }

    void $current_class.target_class_name::setCocos2dImpl(cocos2d::$current_class.target_class_name* impl) {
        m_cocos2d_impl = impl;
    }

#set generator = $current_class.generator
    $current_class.target_class_name::${current_class.target_class_name}() {
        #if not $current_class.is_abstract
        m_cocos2d_impl = new cocos2d::${current_class.target_class_name}();
        #if $generator.in_listed_extend_classed($current_class.class_name) and not $current_class.is_abstract
        m_cocos2d_impl->setCrosswalkImpl((void*)this);
        #end if
        #end if
    }

#if $generator.in_listed_extend_classed($current_class.class_name) and not $current_class.is_abstract
    void V8$current_class.target_class_name::ctorMethodCustom(const v8::FunctionCallbackInfo<v8::Value>& info) {
    }
#end if
    ##void $current_class.target_class_name::setCocos2dImpl(cocos2d::$current_class.target_class_name impl) {
    ##    m_cocos2d_impl = new cocos2d::$(current_class.target_class_name)(impl);
    ##}
} // namespace blink
