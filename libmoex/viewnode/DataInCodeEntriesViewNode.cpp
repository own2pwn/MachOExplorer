//
// Created by everettjf on 2017/7/24.
//

#include "DataInCodeEntriesViewNode.h"

MOEX_NAMESPACE_BEGIN

void DataInCodeEntriesViewNode::InitViewDatas(){
    using namespace moex::util;

    moex::LoadCommand_LC_DATA_IN_CODE *seg=nullptr;
    for(auto & cmd : mh_->loadcmds_ref()){
        if(cmd->offset()->cmd == LC_DATA_IN_CODE) {
            seg = static_cast<moex::LoadCommand_LC_DATA_IN_CODE*>(cmd.get());
            break;
        }
    }
    if(!seg)
        return;

    auto b = CreateBinaryViewDataPtr();
    b->offset = (char*)mh_->header_start() + seg->cmd()->dataoff;
    b->size = seg->cmd()->datasize;
    AddViewData(b);


    // Dices
    auto t = CreateTableViewDataPtr();
    for(auto & dice : seg->GetDices()){
        t->AddRow(seg->GetRAW(&(dice->offset()->offset)),dice->offset()->offset,"Offset",mh_->FileOffsetToSymbol(dice->offset()->offset));
        t->AddRow(seg->GetRAW(&(dice->offset()->length)),dice->offset()->length,"Length",AsShortHexString(dice->offset()->length));
        t->AddRow(seg->GetRAW(&(dice->offset()->kind)),dice->offset()->kind,"Kind",dice->GetKindString());
        t->AddSeparator();
    }
    AddViewData(t);
}

MOEX_NAMESPACE_END
