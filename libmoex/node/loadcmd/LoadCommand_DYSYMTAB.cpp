//
// Created by everettjf on 2017/7/20.
//
#include "LoadCommand_DYSYMTAB.h"
#include "../MachHeader.h"
#include "LoadCommand_SYMTAB.h"

MOEX_NAMESPACE_BEGIN




std::tuple<bool, uint32_t, uint32_t> LoadCommand_LC_DYSYMTAB::GetDataRange()
{
    if(cmd_->tocoff>0)
        return std::make_tuple(true,cmd_->tocoff,cmd_->ntoc * sizeof(struct dylib_table_of_contents));
    if(cmd_->modtaboff>0){
        if(header_->Is64())
            return std::make_tuple(true,cmd_->modtaboff,cmd_->nmodtab * sizeof(struct dylib_module_64));
        else
            return std::make_tuple(true,cmd_->modtaboff,cmd_->nmodtab * sizeof(struct dylib_module));
    }
    if(cmd_->extrefsymoff>0)
        return std::make_tuple(true,cmd_->extrefsymoff,cmd_->nextrefsyms * sizeof(struct dylib_reference));
    if(cmd_->indirectsymoff>0)
        return std::make_tuple(true,cmd_->indirectsymoff,cmd_->nindirectsyms * sizeof(uint32_t));
    if(cmd_->extreloff>0)
        return std::make_tuple(true,cmd_->extreloff,cmd_->nextrel * sizeof(struct relocation_info));
    if(cmd_->locreloff>0)
        return std::make_tuple(true,cmd_->locreloff,cmd_->nlocrel * sizeof(struct relocation_info));
    return std::make_tuple(false,0,0);
}

std::vector<IndirectSymbol> &LoadCommand_LC_DYSYMTAB::GetIndirectSymbols()
{
    if(!indirect_symbols_.empty()){
        return indirect_symbols_;
    }

    char * offset = (char*)header_->header_start() + cmd_->indirectsymoff;
    for(uint32_t nindsym = 0; nindsym < cmd_->nindirectsyms; ++nindsym) {
        uint32_t *p = (uint32_t *) (offset + nindsym * sizeof(uint32_t));
        uint32_t indirect_index = *p;

        IndirectSymbol sym;
        sym.offset = (uint64_t)p;
        sym.data = indirect_index;
        indirect_symbols_.push_back(sym);
    }
    return indirect_symbols_;
}

MOEX_NAMESPACE_END

