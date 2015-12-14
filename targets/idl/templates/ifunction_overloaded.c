#if len($implementations) == 0
    #set $func2 = $self
    #set $func2.arguments = $arguments
    #set $func2.ret_type = $ret_type
    #set $func2.static = $static
    $implementations.append($func2)
#end if
#for $func in $implementations
#set $arguments = $func.arguments
#set $ret_type = $func.ret_type
#set arglist = ''
#set arglist_call = ""
#set arg_wrapper = ""
#set arg_wrapper_call = ""
    #set $length = len($arguments)
    #set $index = 0
    #for $arg in $arguments
        #set $arg_tmp = $arg.to_webcore_native($generator)
        #if $generator.in_listed_extend_classed($arg_tmp)
            #set $arglist = $arglist + 'ScriptValue&'
            #set $arglist = $arglist + ' arg' + str(index) + '_wrapper'
            #set $arglist_call = $arglist_call + ' arg' + str(index) + '_wrapper'
            #set $tmp = $arg_tmp.replace("*","").replace("const ", "")
            #set arg_wrapper = $arg_wrapper + '        SCRIPT_VALUE_WRAPPER('+tmp+', '+'arg'+str(index)+'_wrapper, '+'arg'+str(index)+');\n'
        #else if $arg.name == "std::string"
            #set $arglist = $arglist + $arg_tmp
            #set $arglist = $arglist + ' arg' + str(index) + '_wrapper'
            #set $arglist_call = $arglist_call + ' arg' + str(index) + '_wrapper'
            #set arg_wrapper = $arg_wrapper + '        std::string arg' + str(index) + ' = ' + 'std::string(arg'+str(index)+'_wrapper.utf8().data());'
        #else
            #set $arglist = $arglist + $arg_tmp
            #set $arglist = $arglist + ' arg' + str(index)
            #set $arglist_call = $arglist_call + ' arg' + str(index)
        #end if
        ##argument wrapper
        #set tmp = $arg.to_webcore_native($generator).replace("const ", "").replace("*", "")
        #if $generator.in_listed_idl_classes($tmp)
            #if "shared_ptr" in $arg.name
                #set tmp = $arg.whole_name
                #set arg_wrapper = $arg_wrapper + "        " + $tmp+" _arg"+str(index)+" = arg"+str(index)+"->getImpl();\n"
                #set $arg_wrapper_call = $arg_wrapper_call + ' _arg' + str(index)
            #else
                #set tmp = $tmp + "*"
                #set arg_wrapper = $arg_wrapper + "        " + $arg.namespace_name +tmp+" _arg"+str(index)+" = ("+$arg.namespace_name+tmp+")(arg"+str(index)+"->getImpl().get());\n"
                #if $arg.is_pointer
                    #set $arg_wrapper_call = $arg_wrapper_call + ' _arg' + str(index)
                #else
                    #set $arg_wrapper_call = $arg_wrapper_call + ' *_arg' + str(index)
                #end if
            #end if
        #else
            #set $arg_wrapper_call = $arg_wrapper_call + '(' + arg.namespaced_name + ')' +'(arg' + str(index) + $arg.to_cocos_native() + ')'
        #end if
        #if $index < $length - 1 
            #set $arglist = $arglist + ', '
            #set $arglist_call = $arglist_call + ', '
            #set $arg_wrapper_call = $arg_wrapper_call + ', '
        #end if
        #set $index = $index + 1
    #end for
##
## Return type wrapper
##
#set $ret_impl_type = $ret_type.to_webcore_native($generator).replace("const ", "").replace("*", "")
#set $ret_cocos_instance = ""
#set $ret_cocos_instance_2 = ""
#set $ret_cocos_instance_3 = ""
#if $generator.in_listed_idl_classes($ret_impl_type)
    #if $generator.in_listed_idl_classes($ret_impl_type) and $ret_type.is_pointer and $generator.extend_from_ccobj($ret_impl_type)
        #set $ret_cocos_instance = "if (ret_impl.get() == NULL) { return ScriptValue(); }"
        #set $ret_cocos_instance_2 = 'RET_V8_WRAPPER(ret_impl, ' + $ret_impl_type + ')'
    #else
        #if $ret_type.is_pointer
        #set $ret_cocos_instance = "if (ret_impl.get() == nullptr) { return nullptr; }"
        #end if
        #set $ret_cocos_instance = ret_cocos_instance + '\n' + '        RefPtr' + '<' + $ret_impl_type + '> ' + " ret = adoptRefWillBeNoop(new " + $ret_impl_type+"());"
        #set $ret_cocos_instance_2 = "ret->setImpl(ret_impl);"
        #set $ret_cocos_instance_3 = "return ret.release();"
    #end if
        #if "shared_ptr" in $ret_type.name
            #set $ret_impl_type = $ret_type.whole_name
        #else
            #set $ret_impl_type = $ret_type.namespace_name+$ret_impl_type
            #if $ret_type.is_pointer
                #set ret_impl_type = ret_impl_type + "*"
            #end if
        #end if
#else
    #set $ret_impl_type = $ret_type.to_webcore_native($generator)
    #set $ret_cocos_instance_3 = "return ret_impl;"
#end if
## #if $ret_type.is_const
##    #set ret_impl_type = "const " + $ret_impl_type
## #end if

##
## Auto gen function
##
#set $ret_type_name = $ret_type.to_webcore_native($generator)
#set $tmp = $ret_type_name.replace("const ", "").replace("*", "")
#if $generator.in_listed_idl_classes($tmp)
    #if $ret_type.is_pointer  and $generator.extend_from_ccobj($tmp)
        #set $ret_type_name = 'ScriptValue'
    #else
        #set $ret_type_name = 'PassRefPtrWillBeRawPtr' + '<' + $tmp + '>'
    #end if
#end if
#set $prefix = ''
#if $ret_type_name == 'ScriptValue'
#set $prefix = 'ScriptState* scriptState'
#if len($arguments)
    #set $prefix = $prefix + ', '
#end if
#end if
    $ret_type_name ${signature_name}($prefix$arglist) {
$arg_wrapper
        #if $ret_type.name == "void"
        (($namespaced_class_name*)m_impl.get())->${func_name}($arg_wrapper_call);
        #else
        #if $ret_type.namespaced_name == 'std::string'
        $ret_impl_type ret_impl = String((($namespaced_class_name*)m_impl.get())->${func_name}($arg_wrapper_call).c_str());
        #else
        $ret_impl_type ret_impl = (($namespaced_class_name*)m_impl.get())->${func_name}($arg_wrapper_call);
        #end if
        $ret_cocos_instance
        $ret_cocos_instance_2
        $ret_cocos_instance_3
        #end if
    }
#end for
