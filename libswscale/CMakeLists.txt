get_library_version(swscale version.h LIBSWSCALE_VERSION)

set(SWSCALE_HEADERS swscale.h
    version.h
)

set(SWSCALE_SOURCES alphablend.c
    hscale.c
    hscale_fast_bilinear.c
    gamma.c
    input.c
    options.c
    output.c
    rgb2rgb.c
    slice.c
    swscale.c
    swscale_unscaled.c
    utils.c
    yuv2rgb.c
    vscale.c
)

list(FIND TARGET_ARCHITECTURE_NAMES "X86" IS_X86)
if (NOT IS_X86 EQUAL -1)
    add_subdirectory(x86)
endif ()

source_group("Assembly Files" FILES ${SWSCALE_X86_ASSEMBLY_SOURCES})
if (WIN32)
    set_source_files_properties(${SWSCALE_X86_ASSEMBLY_SOURCES} PROPERTIES VS_TOOL_OVERRIDE "NASM")
else ()
    set_source_files_properties(${SWSCALE_X86_ASSEMBLY_SOURCES} PROPERTIES LANGUAGE ASM_NASM)
endif ()
source_group("Source Files\\x86" REGULAR_EXPRESSION "x86/.+")
add_library(swscale ${LIBRARY_TYPE} ${SWSCALE_SOURCES} ${SWSCALE_X86_SOURCES} ${SWSCALE_X86_ASSEMBLY_SOURCES} ${SWSCALE_HEADERS} ${GENERATED_CONFIG_HEADERS} ${GENERATED_VERSION_HEADERS})
if (WIN32)
    add_custom_command(TARGET swscale PRE_BUILD COMMAND if not exist  "$(IntDir)\\x86" mkdir "$(IntDir)\\x86")
endif ()
target_link_libraries(swscale avutil)
target_include_directories(swscale PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_definitions(swscale PUBLIC HAVE_AV_CONFIG_H)

set_target_properties(swscale PROPERTIES PUBLIC_HEADER "${SWSCALE_HEADERS}")
set_target_properties(swscale PROPERTIES RUNTIME_OUTPUT_NAME "swscale-${LIBSWSCALE_VERSION}")
install(TARGETS swscale
    ARCHIVE
    LIBRARY
    PUBLIC_HEADER
        DESTINATION include/libswscale
    RUNTIME
)
if (WIN32 AND "${LIBRARY_TYPE}" STREQUAL "SHARED")
    install(FILES $<TARGET_PDB_FILE:swscale> DESTINATION bin OPTIONAL)
endif ()