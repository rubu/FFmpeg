list(APPEND AVUTIL_X86_SOURCE_FILES x86/cpu.c x86/fixed_dsp_init.c x86/float_dsp_init.c x86/imgutils_init.c x86/lls_init.c)


if (${HAVE_X86ASM})
    list(APPEND AVUTIL_X86_ASSEMBLY_FILES x86/cpuid.asm x86/fixed_dsp.asm x86/float_dsp.asm x86/imgutils.asm x86/lls.asm)
endif (${HAVE_X86ASM})

set(AVUTIL_X86_SOURCES "${AVUTIL_X86_SOURCE_FILES}" PARENT_SCOPE)
set(AVUTIL_X86_ASSEMBLY_SOURCES "${AVUTIL_X86_ASSEMBLY_FILES}" PARENT_SCOPE)