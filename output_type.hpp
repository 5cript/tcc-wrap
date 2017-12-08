#pragma once

#include "tcc.hpp"

namespace TinyCompiler
{
    enum class OutputType
    {
        /*Memory = TCC_OUTPUT_MEMORY,*/
        Executable = TCC_OUTPUT_EXE,
        DynamicLibrary = TCC_OUTPUT_DLL,
        ObjectFile = TCC_OUTPUT_OBJ
    };
}
