include(${CMAKE_CURRENT_LIST_DIR}/utils.cmake)

set(PUBLIC_SUFFIX_PATH "${LADYBIRD_CACHE_DIR}/PublicSuffix" CACHE PATH "Download location for PublicSuffix files")
set(PUBLIC_SUFFIX_DATA_URL "https://raw.githubusercontent.com/publicsuffix/list/master/public_suffix_list.dat")
set(PUBLIC_SUFFIX_DATA_PATH "${PUBLIC_SUFFIX_PATH}/public_suffix_list.dat")
set(PUBLIC_SUFFIX_DATA_HEADER PublicSuffixData.h)
set(PUBLIC_SUFFIX_DATA_IMPLEMENTATION PublicSuffixData.cpp)
if (ENABLE_NETWORK_DOWNLOADS)
    download_file("${PUBLIC_SUFFIX_DATA_URL}" "${PUBLIC_SUFFIX_DATA_PATH}")
else()
    message(STATUS "Skipping download of ${PUBLIC_SUFFIX_DATA_URL}, expecting it to be in ${PUBLIC_SUFFIX_DATA_PATH}")
endif()
invoke_py_generator(
    "PublicSuffixData"
    "generate_public_suffix_data.py"
    "${PUBLIC_SUFFIX_PATH}/"
    "${PUBLIC_SUFFIX_DATA_HEADER}"
    "${PUBLIC_SUFFIX_DATA_IMPLEMENTATION}"
    arguments -p "${PUBLIC_SUFFIX_DATA_PATH}"
)
set(PUBLIC_SUFFIX_SOURCES
	${PUBLIC_SUFFIX_DATA_HEADER}
	${PUBLIC_SUFFIX_DATA_IMPLEMENTATION}
)
