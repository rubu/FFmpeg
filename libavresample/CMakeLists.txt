get_library_version(avresample version.h LIBAVRESAMPLE_VERSION)

set(AVRESAMPLE_HEADERS avresample.h
    version.h
)

set(AVRESAMPLE_SOURCES audio_convert.c
    audio_data.c
    audio_mix.c
    audio_mix_matrix.c
    dither.c
    options.c
    resample.c
    utils.c
)

list(FIND TARGET_ARCHITECTURE_NAMES "X86" IS_X86)
if (NOT IS_X86 EQUAL -1)
    add_subdirectory(x86)
endif ()

source_group("Assembly Files" FILES ${AVRESAMPLE_X86_ASSEMBLY_SOURCES})
if (WIN32)
    set_source_files_properties(${AVRESAMPLE_X86_ASSEMBLY_SOURCES} PROPERTIES VS_TOOL_OVERRIDE "NASM")
else ()
    set_source_files_properties(${AVRESAMPLE_X86_ASSEMBLY_SOURCES} PROPERTIES LANGUAGE ASM_NASM)
endif ()
source_group("Source Files\\x86" FILES ${AVRESAMPLE_X86_SOURCES})
add_library(avresample ${LIBRARY_TYPE} ${AVRESAMPLE_SOURCES} ${AVRESAMPLE_X86_SOURCES} ${AVRESAMPLE_X86_ASSEMBLY_SOURCES} ${AVRESAMPLE_HEADERS} ${GENERATED_CONFIG_HEADERS} ${GENERATED_VERSION_HEADERS})
if (WIN32)
    add_custom_command(TARGET avresample PRE_BUILD COMMAND if not exist  "$(IntDir)\\x86" mkdir "$(IntDir)\\x86")
endif ()
target_link_libraries(avresample avutil)
target_include_directories(avresample PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_definitions(avresample PUBLIC HAVE_AV_CONFIG_H)

set_target_properties(avresample PROPERTIES PUBLIC_HEADER "${AVRESAMPLE_HEADERS}")
set_target_properties(avresample PROPERTIES RUNTIME_OUTPUT_NAME "avresample-${LIBAVRESAMPLE_VERSION}")
install(TARGETS avresample
    ARCHIVE
    LIBRARY
    PUBLIC_HEADER
        DESTINATION include/libavresample
    RUNTIME
)
if (WIN32 AND "${LIBRARY_TYPE}" STREQUAL "SHARED")
    install(FILES $<TARGET_PDB_FILE:avresample> DESTINATION bin OPTIONAL)
endif ()