get_library_version(swresample version.h LIBSWRESAMPLE_VERSION)

set(SWRESAMPLE_HEADERS swresample.h
    version.h
)

set(SWRESAMPLE_SOURCES audioconvert.c
    dither.c
    options.c
    rematrix.c
    resample.c
    resample_dsp.c
    swresample.c
    swresample_frame.c
)

list(FIND TARGET_ARCHITECTURE_NAMES "X86" IS_X86)
if (NOT IS_X86 EQUAL -1)
    add_subdirectory(x86)
endif ()

source_group("Assembly Files" FILES ${SWRESAMPLE_X86_ASSEMBLY_SOURCES})
if (WIN32)
    set_source_files_properties(${SWRESAMPLE_X86_ASSEMBLY_SOURCES} PROPERTIES VS_TOOL_OVERRIDE "NASM")
else ()
    set_source_files_properties(${SWRESAMPLE_X86_ASSEMBLY_SOURCES} PROPERTIES LANGUAGE ASM_NASM)
endif ()
source_group("Source Files\\x86" FILES ${SWRESAMPLE_X86_SOURCES})
add_library(swresample ${LIBRARY_TYPE} ${SWRESAMPLE_SOURCES} ${SWRESAMPLE_X86_SOURCES} ${SWRESAMPLE_X86_ASSEMBLY_SOURCES} ${SWRESAMPLE_HEADERS} ${GENERATED_CONFIG_HEADERS} ${GENERATED_VERSION_HEADERS})
if (WIN32)
    add_custom_command(TARGET swresample PRE_BUILD COMMAND if not exist  "$(IntDir)\\x86" mkdir "$(IntDir)\\x86")
endif ()
target_link_libraries(swresample PUBLIC avutil)
target_include_directories(swresample PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_definitions(swresample PUBLIC HAVE_AV_CONFIG_H)

set_target_properties(swresample PROPERTIES PUBLIC_HEADER "${SWRESAMPLE_HEADERS}")
set_target_properties(swresample PROPERTIES RUNTIME_OUTPUT_NAME "swresample-${LIBSWRESAMPLE_VERSION}")
install(TARGETS swresample
    ARCHIVE
    LIBRARY
    PUBLIC_HEADER
        DESTINATION include/libswresample
    RUNTIME
)
if (WIN32)
    install(FILES $<TARGET_PDB_FILE:swresample> DESTINATION bin OPTIONAL)
endif ()