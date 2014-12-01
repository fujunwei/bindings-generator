    cocos2d::$current_class.target_class_name* getCocos2dImpl();
    void setCocos2dImpl(cocos2d::$(current_class.target_class_name)* impl);
    ##void setCocos2dImpl(cocos2d::$(current_class.target_class_name) impl);
    ~$(current_class.target_class_name)() {}

protected:
    Member<cocos2d::$current_class.target_class_name> m_cocos2d_impl;
public:
    $(current_class.target_class_name) ();
};
}

#endif
