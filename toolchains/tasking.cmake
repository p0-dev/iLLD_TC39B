# ----------------------------------------------------------------------------------------
#   GENERAL
# ----------------------------------------------------------------------------------------
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# ----------------------------------------------------------------------------------------
#   COMPILER
# ----------------------------------------------------------------------------------------
set(CMAKE_C_COMPILER "D:/ts_mirr/tasking/TriCore.v6.2r2p2/ctc/bin/cctc.exe")

# ----------------------------------------------------------------------------------------
#   DEBUG COMPILE FLAG
# ----------------------------------------------------------------------------------------
add_compile_options($<$<CONFIG:Debug>:--cpu=tc39x>)
add_compile_options($<$<CONFIG:Debug>:--iso=99>)
add_compile_options($<$<CONFIG:Debug>:--language=-gcc,+volatile,+strings>)
add_compile_options($<$<CONFIG:Debug>:--switch=linear>)
add_compile_options($<$<CONFIG:Debug>:--align=4>)
add_compile_options($<$<CONFIG:Debug>:--default-near-size=0>)
add_compile_options($<$<CONFIG:Debug>:--default-a0-size=0>)
add_compile_options($<$<CONFIG:Debug>:--default-a1-size=0>)
add_compile_options($<$<CONFIG:Debug>:--tradeoff=4>)
add_compile_options($<$<CONFIG:Debug>:--use-double-precision-fp>)
add_compile_options($<$<CONFIG:Debug>:-g>)

# ----------------------------------------------------------------------------------------
#   DEBUG LINKING FLAG
# ----------------------------------------------------------------------------------------
add_link_options($<$<CONFIG:Debug>:-Wl-D__CPU__=tc39x>)
add_link_options($<$<CONFIG:Debug>:-Wl-D__PROC_TC39X__>)
add_link_options($<$<CONFIG:Debug>:-Wl--core=mpe:vtc>)
add_link_options($<$<CONFIG:Debug>:-Wl-OtXYcL>)
add_link_options($<$<CONFIG:Debug>:-Wl-mCdfiklmNoQrSu>)
add_link_options($<$<CONFIG:Debug>:-Wl--error-limit=42>)
add_link_options($<$<CONFIG:Debug>:-Wl-g>)

# ----------------------------------------------------------------------------------------
#   END FILE
# ----------------------------------------------------------------------------------------