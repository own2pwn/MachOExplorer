//
// Created by everettjf on 2017/8/6.
//

#ifndef MOEX_SECTIONVIEWNODE_H
#define MOEX_SECTIONVIEWNODE_H

#include "ViewNode.h"

MOEX_NAMESPACE_BEGIN

class SectionViewNode : public ViewNode{
private:
    MachSectionPtr d_;
public:
    void Init(MachSectionPtr d);
    std::string GetDisplayName()override;

    void InitViewDatas()override;
};
using SectionViewNodePtr = std::shared_ptr<SectionViewNode>;


MOEX_NAMESPACE_END

#endif //MOEX_SECTIONVIEWNODE_H
