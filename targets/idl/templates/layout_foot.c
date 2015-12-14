
#set generator = $current_class.generator

    PassRefPtrWillBeRawPtr<$(current_class.target_class_name)> $current_class.target_class_name::create() {
        RefPtrWillBeRawPtr<$(current_class.target_class_name)> ret = adoptRefWillBeNoop(new $(current_class.target_class_name)());
        std::shared_ptr<${current_class.namespaced_class_name}> impl = three::make_shared<${current_class.namespaced_class_name}>();
        ret->setImpl(impl);
        return ret.release();
    }

    $(current_class.target_class_name)::$(current_class.target_class_name)() {
        //m_impl = new ${current_class.namespaced_class_name}();
    }

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
            #set arglist2 = ''
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
                #set $arglist2 = $arglist2 + ' arg' + str(index)
                #if $index < $length - 1 
                    #set $arglist = $arglist + ', '
                    #set $arglist2 = $arglist2 + ', '
                #end if
                #set $index = $index + 1
            #end for
            #if $skip == False
    $(current_class.target_class_name)::$(current_class.target_class_name)($arglist) {
    }

    PassRefPtrWillBeRawPtr<$(current_class.target_class_name)> $current_class.target_class_name::create($arglist) {
        RefPtrWillBeRawPtr<$(current_class.target_class_name)> ret = adoptRefWillBeNoop(new $(current_class.target_class_name)($arglist2));
        std::shared_ptr<${current_class.namespaced_class_name}> impl = three::make_shared<${current_class.namespaced_class_name}>($arglist2);
        //${current_class.namespaced_class_name}* impl = new ${current_class.namespaced_class_name}($arglist2);
        ret->setImpl(impl);
        return ret.release();
    }
            #end if
            #set $skip = True
        #end for
    #end if
#end for

    $current_class.target_class_name::~$(current_class.target_class_name)() {
##         if (m_cocos2d_impl != NULL) {
## #if $current_class.class_name != 'CCEGLView' and $current_class.class_name != 'CCEGLViewProtocol'
##             if (m_cocos2d_impl->getCrosswalkImpl() == this) {
##                 m_cocos2d_impl->setCrosswalkImpl(NULL);
##             } else {
## #end if
##                 m_cocos2d_impl->release();
## #if $current_class.class_name != 'CCEGLView' and $current_class.class_name != 'CCEGLViewProtocol'
##             }
## #end if
##             m_cocos2d_impl = NULL;
##         }
        m_impl.reset();
    }
    ##void $current_class.target_class_name::setCocos2dImpl(cocos2d::$current_class.target_class_name impl) {
    ##    m_cocos2d_impl = new cocos2d::$(current_class.target_class_name)(impl);
    ##}

    void $current_class.target_class_name::setImpl(three::$(current_class.target_class_name)& impl) {
        // if (m_impl.get() != &impl)
        //    m_impl = std::make_shared<three::$current_class.target_class_name>(impl);
    }
} // namespace blink
