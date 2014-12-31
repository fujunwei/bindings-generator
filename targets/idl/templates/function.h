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
    #set $length = len($arguments)
    #set $index = 0
    #for $arg in $arguments
        #set $arg_wrapper =  $arg.to_webcore_native($generator)
        #if $generator.in_listed_extend_classed($arg_wrapper)
            #set $arg_wrapper = 'ScriptValue&'
        #end if
        #set $arglist = $arglist + $arg_wrapper
        #set $arglist = $arglist + ' arg' + str(index)
        #if $index < $length - 1 
            #set $arglist = $arglist + ', '
        #end if
        #set $index = $index + 1
    #end for
#set $ret_type_name = $ret_type.to_webcore_native($generator)
#if $func.static
    static $ret_type_name ${registration_name}($arglist);
#else
    $ret_type_name ${registration_name}($arglist);
#end if
#end for