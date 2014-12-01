    cocos2d::$current_class.target_class_name* $current_class.target_class_name::getCocos2dImpl() {
        return (cocos2d::$current_class.target_class_name*)(m_cocos2d_impl.get());
    }

    void $current_class.target_class_name::setCocos2dImpl(cocos2d::$current_class.target_class_name* impl) {
        m_cocos2d_impl = impl;
    }

    $current_class.target_class_name::${current_class.target_class_name}() {
        ScriptWrappable::init(this);
        #if not $current_class.is_abstract
        m_cocos2d_impl = new cocos2d::${current_class.target_class_name}();
        #end if
    }

    ##void $current_class.target_class_name::setCocos2dImpl(cocos2d::$current_class.target_class_name impl) {
    ##    m_cocos2d_impl = new cocos2d::$(current_class.target_class_name)(impl);
    ##}
}
