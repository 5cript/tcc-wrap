#pragma once

#include "context.hpp"

#include "output_type.hpp"

#include <string>

namespace TinyCompiler
{
    class Builder
    {
    public:
        Builder(Context* ctx);

        /**
         *  Compiles a program string and writes it into output, depending on type.
         */
        void compile(std::string const& program, std::string const& output, OutputType type);

        /**
         *  Add symbols, like a _cdecl function etc.
         */
        template <typename T>
        void addSymbol(std::string const& name, T* symbol)
        {
            tcc_add_symbol(*ctx_, name.c_str(), reinterpret_cast <void*> (symbol));
        }

        /**
         *  The library name is the same as the argument of the '-l' option.
         */
        void linkLibrary(std::string const& name);

        /**
         *  Equivalent to -Lpath option.
         */
        void addLibraryPath(std::string const& path);

    private:
        Context* ctx_;
    };
}
