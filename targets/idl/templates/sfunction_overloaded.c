#if len($implementations) == 0
    #set $func2 = $self
    #set $func2.arguments = $arguments
    #set $func2.ret_type = $ret_type
    #set $func2.static = $static
    $implementations.append($func2)
#end if
#for $func in $implementations
#set $arguments = $func.arguments
#if $registration_name == "create"
    #if len($arguments) == 0
    #continue
    #end if
#end if
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
        #else
            #set $arglist = $arglist + $arg_tmp
            #set $arglist = $arglist + ' arg' + str(index)
            #set $arglist_call = $arglist_call + ' arg' + str(index)
        #end if
        ##argument wrapper
        #set tmp = $arg.to_webcore_native($generator).replace("const ", "").replace("*", "")
        #if $generator.in_listed_idl_classes($tmp)
            #set tmp = $tmp + "*"
            #set arg_wrapper = $arg_wrapper + "        " + "cocos2d::"+tmp+" _arg"+str(index)+" = (cocos2d::"+tmp+")(arg"+str(index)+"->getCocos2dImpl());\n"
            #if $arg.is_pointer
                #set $arg_wrapper_call = $arg_wrapper_call + ' _arg' + str(index)
            #else
                #set $arg_wrapper_call = $arg_wrapper_call + ' *_arg' + str(index)
            #end if
        #else
            #set $arg_wrapper_call = $arg_wrapper_call + ' arg' + str(index) + $arg.to_cocos_native()
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
    #set $ret_cocos_instance = $ret_impl_type + " *ret = new " + $ret_impl_type+"();"
    #set $ret_impl_type = "cocos2d::"+$ret_impl_type
    #set $ret_cocos_instance_2 = "ret->setCocos2dImpl(ret_impl);"
    #if $ret_type.is_pointer
        #set ret_impl_type = ret_impl_type + "*"
    #end if
    #set $ret_cocos_instance_3 = "return ret;"
#else
    #set $ret_impl_type = $ret_type.to_webcore_native($generator)
    #set $ret_cocos_instance_3 = "return ret_impl;"
#end if
#if $ret_type.is_const
    #set ret_impl_type = "const " + $ret_impl_type
#end if
##
## Auto gen function
##
#set $ret_type_name = $ret_type.to_webcore_native($generator)
    $ret_type_name ${signature_name}($arglist) {
$arg_wrapper
        #if $ret_type.name == "void"
        cocos2d::$class_name::${func_name}($arg_wrapper_call);
        #else
        $ret_impl_type ret_impl = cocos2d::$class_name::${func_name}($arg_wrapper_call);
        $ret_cocos_instance
        $ret_cocos_instance_2
        $ret_cocos_instance_3
        #end if
    }
#end for