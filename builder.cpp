#include "builder.hpp"

namespace TinyCompiler
{
//#####################################################################################################################
    Builder::Builder(Context* ctx)
        : ctx_{ctx}
    {

    }
//---------------------------------------------------------------------------------------------------------------------
    void Builder::linkLibrary(std::string const& name)
    {
        tcc_add_library(*ctx_, name.c_str());
    }
//---------------------------------------------------------------------------------------------------------------------
    void Builder::passArguments(std::string const& args)
    {
        tcc_set_options(*ctx_, args.c_str());
    }
//---------------------------------------------------------------------------------------------------------------------
    void Builder::compile(std::string const& program, std::string const& output, OutputType type)
    {
        tcc_set_output_type(*ctx_, static_cast <int> (type));
        tcc_compile_string(*ctx_, program.c_str());
        tcc_output_file(*ctx_, output.c_str());
    }
//---------------------------------------------------------------------------------------------------------------------
    void Builder::addLibraryPath(std::string const& path)
    {
        tcc_add_library_path(*ctx_, path.c_str());
    }
//#####################################################################################################################
}
