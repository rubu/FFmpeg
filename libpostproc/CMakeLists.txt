get_library_version(postproc version.h LIBPOSTPROC_VERSION)

set(POSTPROC_HEADERS postprocess.h
    postprocess_internal.h
)

set(POSTPROC_SOURCES postprocess.c
)

add_library(postproc ${LIBRARY_TYPE} ${POSTPROC_SOURCES} ${POSTPROC_HEADERS} ${GENERATED_CONFIG_HEADERS} ${GENERATED_VERSION_HEADERS})
target_link_libraries(postproc avutil)
target_include_directories(postproc PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_definitions(postproc PUBLIC HAVE_AV_CONFIG_H)

set_target_properties(postproc PROPERTIES PUBLIC_HEADER "${POSTPROC_HEADERS};${BUILT_HEADERS}")
set_target_properties(postproc PROPERTIES RUNTIME_OUTPUT_NAME "postproc-${LIBPOSTPROC_VERSION}")
install(TARGETS postproc
    ARCHIVE
    LIBRARY
    PUBLIC_HEADER
        DESTINATION include/postproc
    RUNTIME
)
if (WIN32 AND "${LIBRARY_TYPE}" STREQUAL "SHARED")
    install(FILES $<TARGET_PDB_FILE:postproc> DESTINATION bin OPTIONAL)
endif ()