#pragma once

#include "tcc.hpp"

#include <string>

namespace TinyCompiler
{
    class Context
    {
    public:
        Context();
        ~Context();

        /**
         *  Where is crt1.o?
         */
        void setRuntime(std::string const& directory);

        /**
         *  Deletes the old state and creates a new one.
         */
        void reset();

        /**
         *  Implicit converter to C handle.
         */
        operator TCCState*()
        {
            return ctx_;
        }

    private:
        TCCState* ctx_;
        std::string runtime_;
    };
}
