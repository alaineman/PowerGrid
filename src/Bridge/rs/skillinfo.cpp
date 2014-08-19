#include "skillinfo.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(SkillInfo)
IMPL_RSCLASS_GET(SkillInfo)

IMPL_PRIMITIVE_METHOD(SkillInfo, getCurrentLevel, JInt)
IMPL_PRIMITIVE_METHOD(SkillInfo, getExperience, JInt)
IMPL_PRIMITIVE_METHOD(SkillInfo, getMaxLevel, JInt)

} // namespace bridge

