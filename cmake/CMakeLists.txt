cmake_minimum_required (VERSION 2.8)

add_compile_options(-std=c++11)

project (simple)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include_directories (${PROJECT_SOURCE_DIR}/../include)

function(setSourceGroup strSourceGroup strDir)
    file(GLOB listFiles "${strDir}/*")
    foreach(it ${listFiles})
        get_filename_component(nameFile ${it} NAME)
        get_filename_component(extFile ${it} EXT)
        if(IS_DIRECTORY ${it})  
            setSourceGroup("${strSourceGroup}\\${nameFile}"
                "${strDir}/${nameFile}")
        elseif("${extFile}" MATCHES "\\.h")
            source_group(${strSourceGroup} FILES ${it})
        endif()
    endforeach()
endfunction(setSourceGroup)

function(UpperName strInput strOutput)
    string(LENGTH ${strInput} strLength)
    math(EXPR strLength "${strLength}-1")
    string(SUBSTRING ${strInput} 0 1 firstName)
    string(TOUPPER ${firstName} firstName)
    string(SUBSTRING ${strInput} 1 ${strLength} nextName)
    set(${strOutput} "${firstName}${nextName}" PARENT_SCOPE)
endfunction(UpperName)

function(addTestExecutable strTarget strFolder strDir listOther)
    file(GLOB listFiles "${strDir}/*")
    foreach(it ${listFiles})
        get_filename_component(nameFile ${it} NAME_WE)
        get_filename_component(extFile ${it} EXT)
        if(IS_DIRECTORY ${it})  
            UpperName(${nameFile} upperNameFile)
            addTestExecutable("${strTarget}${upperNameFile}" "${strFolder}//${nameFile}" 
                "${strDir}/${nameFile}" "${listOther}")
        elseif("${extFile}" MATCHES "\\.test\\.cpp")
            UpperName(${nameFile} upperNameFile)
            add_executable("${strTarget}${upperNameFile}" ${it} ${listOther})
            set_property(TARGET "${strTarget}${upperNameFile}" PROPERTY FOLDER ${strFolder})
        endif()
    endforeach()
endfunction(addTestExecutable)

file(GLOB_RECURSE LIST_INCLUDE "${PROJECT_SOURCE_DIR}/../include/*")

setSourceGroup("Header Files" "${PROJECT_SOURCE_DIR}/../include")

addTestExecutable("Test" "test" "${PROJECT_SOURCE_DIR}/../test" "${LIST_INCLUDE}")
